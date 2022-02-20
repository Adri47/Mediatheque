#include <iostream>
#include <fstream>
#include <vector>
#include "commande.h"
#include "media.h"
#include "classes.h"

using namespace std;
extern Mediatheque M; 

void  lecture_clavier(string chaine_ecran, string *donnee_clavier)
{
    //cout << chaine_ecran << endl;
    cout << ">> ";
    //cin.ignore(255, '\n');  //vide l'ancien buffer cin jusqu'à trouver le '\n' dans une limite de 255 carac
    getline(cin, *donnee_clavier);
    //cout << "Vous avez entré la commande " << *donnee_clavier << endl;
}

void lecture_fichier(string nom_fichier)
{
    string STRING;
    ifstream infile;

    infile.open(nom_fichier);
    //cout << infile.eof()<< endl;
    while(infile.eof() == 0)
    {
        getline(infile, STRING);
        cout << "\033[1m" << STRING << endl;
    }
    infile.close();
    cout << "\033[0m";
}

void ecriture_fichier(string nom_fichier, string texte)
{
    string STRING;
    ofstream outfile(nom_fichier, ios::app);
    
    if (outfile)
    {
        outfile << texte << endl;
    }
    else 
        cout << "Erreur d'ouverture fichier pour ecriture" << endl;
}

void recup_string(string separateur, string *premier_mot, string *deuxieme_mot)
{
    string c;
    getline(cin, c);
    //cout << "Vous avez entré la commande " << c << endl;

    int taille = c.size();

    if (taille != 0)
    {
        int position = c.find(separateur);
        //cout << "Position : " << position << endl;
        *premier_mot = c.substr(0,position);
        //cout << "premier_mot : " << *premier_mot << endl;
        *deuxieme_mot = c.substr(position + 1, taille-(position +1));
        //cout << "deuxieme_mot : " << *deuxieme_mot << endl;
    }
}

void selection_commande(string *commande)
{
    cout << "\033[1;32mVeuillez renseigner votre commande :\033[0m"  << endl;
    lecture_fichier("../ressources_media/Description_commandes/liste_commandes.txt");
    cout << ">> ";
    cin >> *commande;
}

void selection_option(string *commande, string *option, Mediatheque* database)
{

    if (*commande == "ADD")
    {
        int return_error = 2;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_ADD.txt");
        
        do
        {
            //cette actioin doit etre faite que si le user se trompe dans le type
            if (return_error == 2)
            {
                cout << ">> ";
                cin >> *option;
                cin.ignore(1000, '\n');
            }
            return_error = 0;
            return_error = commande_ADD(option, database);
            if ( return_error == 0) 
            {
                cout << "\033[1;32mVotre " << *option << " a bien été ajouté !\033[0m"  << endl;
            }

        } while (return_error != 0); //tant que user rentre une donnee non-valide on reboucle
        
    }
    else if (*commande == "LOAD")
    {
        lecture_fichier("../ressources_media/Description_commandes/description_commande_LOAD.txt");
        cout << ">> ";
        cin >> *option;
    }
    else if (*commande == "SAVE")
    {
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SAVE.txt");
        cout << ">> ";
        cin >> *option;
        if (commande_SAVE(*option, &M) == EXIT_FAILURE)
        {
            cout << "\033[1;31mLa commande SAVE renvoie une erreur\033[0m" << endl;
        }
    }
    else if (*commande == "SEARCH")
    {
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SEARCH.txt");
        cout << ">> ";
        cin >> *option;
    }
    else if (*commande == "SHOW")
    {
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SHOW.txt");
        cout << ">> ";
        cin >> *option;
    }
    else if (*commande == "DELETE")
    {
        lecture_fichier("../ressources_media/Description_commandes/description_commande_DELETE.txt");
        cout << ">> ";
        cin >> *option;
    }
    else if ( *commande == ("BYE") || *commande == ("CLEAR") || *commande == ("LIST") || *commande == ("RESET"))
    {
    }
    else
    {
        cout << "\033[1;31mCommande inconnue ! Veuillez vous référer à la liste.\033[0m" << endl;
    }
}

int commande_ADD(string *type, Mediatheque* database)
{
    string donnee;

    if (*type == "Livre")
    {
        string donnee_livre[MAX_INFO_LIVRE] = {};
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_Livre.txt");
        lecture_clavier("", &donnee);

        if ( recup_donnee_ressource(donnee, donnee_livre, MAX_INFO_LIVRE) == 0)
        {
            try{
                Livre *new_livre = new Livre(donnee_livre[0], donnee_livre[1], donnee_livre[2], stoi(donnee_livre[3]), stoi(donnee_livre[4])) ;
                database->ajouter_media(new_livre);
                return EXIT_SUCCESS;
            }
            catch(invalid_argument){
                cout << "\033[1;31mVous avez rentré des lettres au lieux de chiffre !! \033[0m" << endl;
                return EXIT_FAILURE;
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }

    else if (*type == "DVD")
    {
        string donnee_dvd[MAX_INFO_DVD] = {};
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_DVD.txt");
        lecture_clavier("", &donnee);

        if ( recup_donnee_ressource(donnee, donnee_dvd, MAX_INFO_DVD) == 0)
        {
            try{
                DVD *new_dvd = new DVD(donnee_dvd[0], donnee_dvd[1], donnee_dvd[2], stoi(donnee_dvd[3]), stoi(donnee_dvd[4])) ;
                database->ajouter_media(new_dvd);
                return EXIT_SUCCESS;
            }
            catch(invalid_argument){
                cout << "\033[1;31mVous avez rentré des lettres au lieux de chiffre !! \033[0m" << endl;
                return EXIT_FAILURE;
            }
        }
        else
        {
            return EXIT_FAILURE;
        }

    }
    else if (*type == "VHS")
    {
        string donnee_vhs[MAX_INFO_VHS] = {};
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_VHS.txt");
        lecture_clavier("", &donnee);

        if ( recup_donnee_ressource(donnee, donnee_vhs, MAX_INFO_VHS) == 0)
        {
            try{
                VHS *new_vhs = new VHS(donnee_vhs[0], donnee_vhs[1], donnee_vhs[2], stoi(donnee_vhs[3]), stoi(donnee_vhs[4])) ;
                database->ajouter_media(new_vhs);
                return EXIT_SUCCESS;
            }
            catch(invalid_argument){
                cout << "\033[1;31mVous avez rentré des lettres au lieux de chiffre !! \033[0m" << endl;
                return EXIT_FAILURE;
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else if (*type == "CD")
    {
        string donnee_cd[MAX_INFO_CD] = {};
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_CD.txt");
        lecture_clavier("", &donnee);

        if ( recup_donnee_ressource(donnee, donnee_cd, MAX_INFO_CD) == 0)
        {
            try{
                CD *new_cd = new CD(donnee_cd[0], donnee_cd[1], donnee_cd[2], stoi(donnee_cd[3]), stoi(donnee_cd[4])) ;
                database->ajouter_media(new_cd);
                return EXIT_SUCCESS;
            }
            catch(invalid_argument){
                cout << "\033[1;31mVous avez rentré des lettres au lieux de chiffre !! \033[0m" << endl;
                return EXIT_FAILURE;
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else if(*type == "Revue")
    {
        string donnee_revue[MAX_INFO_REVUE] = {};
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_Revue.txt");
        lecture_clavier("", &donnee);

        if ( recup_donnee_ressource(donnee, donnee_revue, MAX_INFO_REVUE) == 0)
        {
            try{
                Revue *new_cd = new Revue(donnee_revue[0], donnee_revue[1], donnee_revue[2], donnee_revue[3], stoi(donnee_revue[4]), stoi(donnee_revue[5]), stoi(donnee_revue[6]));
                database->ajouter_media(new_cd);   
                return EXIT_SUCCESS;
            }
            catch(invalid_argument){
                cout << "\033[1;31mVous avez rentré des lettres au lieux de chiffre !! \033[0m" << endl;
                return EXIT_FAILURE;
            }
        } 
        else
        {
            return EXIT_FAILURE;
        }    
    }
    else{
        cout << "\033[1;31mVous avez entré une mauvaise option !\033[0m" << endl;
    }
    return 2; //retour de 2 pour ne pas re-demander au user d'entrer le type de ressourse
}

int recup_donnee_ressource (string donnee, string *donnee_ressources, int nombre_ressources)
{
    int j = 0;
    char c = 0;
    for (int i = 0 ; i <= donnee.size(); i++)
    {
        if (j > nombre_ressources - 1) 
        {
            //gestion surplus de donnees
            cout << "\033[1;31mVous avez rentré trop de donnee ! \033[0m" << endl;
            return EXIT_FAILURE;
        }
        c = donnee[i];
        if (c ==';') j++; 
        if (c !=';') donnee_ressources[j] = donnee_ressources[j] + donnee[i];
    }
    //si le nombre de ressources est trop faible
    if ( (j + 1) < nombre_ressources) 
    {
        cout << "\033[1;31mVous avez rentré un nombre de données insuffisants ! \033[0m" << endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
int commande_SAVE(string nom_fichier, Mediatheque *media)
{
    string STRING;
    string nom_fichier_modifie = "../Dossier_User/" + nom_fichier;
    ofstream outfile(nom_fichier_modifie, ios::app);
    
    if (outfile)
    {
        outfile << *media << endl;
        cout << "\033[1;32mVotre fichier " << nom_fichier << " est placé dans le dossier Dossier_User !\033[0m" << endl;
        return EXIT_SUCCESS;
    }
    else 
        cout << "\033[1;31mErreur d'ouverture fichier pour ecriture\033[0m" << endl;

        return EXIT_FAILURE;
}

int commande_CLEAR()
{
    return EXIT_SUCCESS;
}
int verif_buffer_string(string *buffer, int nb_element)
{
    int taille = sizeof(buffer) - nb_element + 1;
    cout << "taille : " << taille << endl;

    if ( sizeof(buffer) != taille  )
    {
        return EXIT_FAILURE;
    }
    else return EXIT_SUCCESS;
}
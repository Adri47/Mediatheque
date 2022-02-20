#include <iostream>
#include <fstream>
#include <vector>
#include "commande.h"
#include "media.h"
#include "classes.h"

using namespace std;


void  lecture_clavier(string chaine_ecran, string *donnee_clavier)
{
    //cout << chaine_ecran << endl;
    cout << ">> ";
    cin.ignore(255, '\n');  //vide l'ancien buffer cin jusqu'à trouver le '\n' dans une limite de 255 carac
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
        cout << STRING << endl;
    }
    infile.close();
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
    cout << "Veuillez renseigner votre commande :"  << endl;
    lecture_fichier("../ressources_media/Description_commandes/liste_commandes.txt");
    cout << ">> ";
    cin >> *commande;
}

void selection_option(string *commande, string *option, Mediatheque* database)
{

    if (*commande == "ADD")
    {
        //cout << "commande ADD" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_ADD.txt");
        cout << ">> ";
        cin >> *option;
        commande_ADD(option, database);
        //cout << database[0] << endl;
        
    }
    else if (*commande == "LOAD")
    {
        //cout << "commande LOAD" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_LOAD.txt");
        cin >> *option;
    }
    else if (*commande == "SAVE")
    {
        //cout << "commande SAVE" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SAVE.txt");
        cin >> *option;
    }
    else if (*commande == "SEARCH")
    {
        //cout << "commande SEARCH" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SEARCH.txt");
        cin >> *option;
    }
    else if (*commande == "SHOW")
    {
        //cout << "commande SHOW" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_SHOW.txt");
        cin >> *option;
    }
    else if (*commande == "DELETE")
    {
        //cout << "commande DELETE" << endl;
        lecture_fichier("../ressources_media/Description_commandes/description_commande_DELETE.txt");
        cin >> *option;
    }
    else if ( *commande == ("BYE") || *commande == ("CLEAR") || *commande == ("LIST") || *commande == ("RESET"))
    {
        //cout << "commande BYE / CLEAR / LIST / RESET" << endl;
    }
    else
    {
        cout << "Commande inconnue ! Veuillez vous référer à la liste." << endl;
    }
}

void commande_ADD(string *type, Mediatheque* database)
{
    string donnee;
    string donnee_livre[5] = {};
    string *buffer;

    if (*type == "Livre")
    {
        lecture_fichier("../ressources_media/Description_ressources/description_ressources_Livre.txt");
        lecture_clavier("", &donnee);
        //cout << donnee << endl;
        
        recup_donnee_livre(donnee, donnee_livre);
           
        //cout << "1 :" << donnee_livre[0] << "2 :" << donnee_livre[1] << "3 :" << donnee_livre[2] << "4 :" << donnee_livre[3] << "5 :" << donnee_livre[4] << endl;
        Livre *new_livre = new Livre(donnee_livre[0], donnee_livre[1], donnee_livre[2], stoi(donnee_livre[3]), stoi(donnee_livre[4])) ;
        //cout << new_livre->auteur << " " << new_livre->titre << " " << new_livre->collection << " "<< new_livre->parrution << " "<< new_livre->nb_page << endl; 
        database->ajouter_media(new_livre);
    }

    if (*type == "DVD")
    {
        lecture_fichier("../ressources_media/Descriptiorn_ressources/description_ressources_DVD.txt");
        lecture_clavier("", &donnee);

        recup_donnee_dvd(donnee, donnee_livre);
    }
    cout << "Votre " << *type << " a bien été ajouté !"  << endl;
}

void recup_donnee_livre(string donnee, string *donnee_livre)
{
    int j = 0;
    char c = 0;
    for (int i = 0 ; i <= donnee.size(); i++)
    {
        if (j > 5 - 1) 
        {
            cout << "Vous avez rentré trop de donnee ! " << endl;
            break;
        }
        c = donnee[i];
        if (c ==' ') j++; 

        if (c !=' ') donnee_livre[j] = donnee_livre[j] + donnee[i];
        
        //cout << "c : " << c << endl;
        //cout << "donnee_livre : " << donnee_livre[j] << "j : " << j << endl;  
    }
}

void recup_donnee_dvd(string donnee, string *donnee_dvd)
{
    int j = 0;
    char c = 0;
    for (int i = 0 ; i <= donnee.size(); i++)
    {
        if (j > 5 - 1) 
        {
            cout << "Vous avez rentré trop de donnee ! " << endl;
            break;
        }
        c = donnee[i];
        if (c ==' ') j++; 

        if (c !=' ') donnee_dvd[j] = donnee_dvd[j] + donnee[i];
        
        //cout << "c : " << c << endl;
        //cout << "donnee_livre : " << donnee_livre[j] << "j : " << j << endl;  
    }
}
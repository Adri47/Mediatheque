#include <iostream>
#include <fstream>
#include "commande.h"
#include "media.h"

using namespace std;

string lecture_clavier(string chaine_ecran)
{
    string chaine_clavier;
    cout << chaine_ecran << endl;
    getline(cin,chaine_clavier);
    cout << "Vous avez entré la commande " << chaine_clavier << endl;

    return chaine_clavier;
}

void lecture_fichier(string nom_fichier)
{
    string STRING;
    ifstream infile;

    infile.open(nom_fichier);
    cout << infile.eof()<< endl;
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

void recup_string(string chaine_ecran, string separateur, string *premier_mot, string *deuxieme_mot)
{
    string c;
    cout << chaine_ecran <<endl;
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

void commande_ADD(string type)
{
    cout << "Votre " << type << " a bien été ajouté !"  << endl;
}
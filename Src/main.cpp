#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "classes.h"
#include "commande.h"


using namespace std;

int main ()
{
    string commande;
    string option;
    //lecture_fichier("../Src/test.txt");

    vector<Media*> database ; 
    VHS History("Ben","History of SEE","SEE",90) ;
    DVD HP("JK.Rowling","Harry Potter à l'école des sorciers","Mappa",120,12) ;

    database.push_back(&History) ;
    database.push_back(&HP) ;

    for (int i = 0; i < database.size(); i++) {
        
        Media *m = database[i] ;
        if(m->type_media == "VHS") {
            VHS *t =  dynamic_cast<VHS*>(m);
            //cout << *t ;

        }
        else if (m->type_media == "DVD")
        {
            DVD *t =  dynamic_cast<DVD*>(m);
            //cout << *t ;
        }
        else if (m->type_media == "Livre")
        {
            Livre *t =  dynamic_cast<Livre*>(m);
            //cout << *t ;
        }
        else if (m->type_media == "CD")
        {
            CD *t =  dynamic_cast<CD*>(m);
            //cout << *t ;
        }
        else if (m->type_media == "Revue")
        {
            Revue *t =  dynamic_cast<Revue*>(m);
            //cout << *t ;
        } 
    }

    ecriture_fichier("../Src/test.txt", "C'est réussi !");
    while (commande != "BYE")
    {
        recup_string("Entrez votre commande :", " " , &commande, &option);
        //cout << "COMMANDE : " << commande << endl;
        //cout << "OPTION : " << option << endl;

        if (commande == "ADD")
        {
            commande_ADD(option);
        }
    }
    cout << "Vous avez quitté la médiathèque :'(  Au revoir !" << endl;

    return EXIT_SUCCESS;
}
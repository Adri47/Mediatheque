#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "classes.h"
#include "commande.h"


using namespace std;
vector<Media*> database ; 

int main ()
{
    string commande;
    string option;
    //lecture_fichier("../Src/test.txt");

    //VHS History("Ben","History of SEE","SEE",90) ;
    //DVD HP("JK.Rowling","Harry Potter à l'école des sorciers","Mappa",120,12) ;
    Livre SA("J.R.R.Tolkien","The Lord of the ring","Marvel",1940,452) ;

    //database.push_back(&History) ;
    //database.push_back(&HP) ;

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
    string donnee;
    //ecriture_fichier("../Src/test.txt", "C'est réussi !");
    while (commande != "BYE")
    {
        selection_commande(&commande);
        selection_option(&commande, &option, database);
    }
    cout << "Vous avez quitté la médiathèque :'(  Au revoir !" << endl;
    cin.clear(); //remet l'état du flux dans un état valide (resolution pb de terminal)
    
    return EXIT_SUCCESS;
}
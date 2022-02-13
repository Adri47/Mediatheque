#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "classes.h"
#include "commande.h"


using namespace std;
//vector<Media*> database ; 

int main ()
{
    string commande;
    string option;
    string donnee;

    Mediatheque M; 
    
    while (commande != "BYE")
    {
        selection_commande(&commande);
        selection_option(&commande, &option, &M);
        cout << *M.database[0];

    }
    cout << "Vous avez quitté la médiathèque :'(  Au revoir !" << endl;
    cin.clear(); //remet l'état du flux dans un état valide (resolution pb de terminal)
    
    return EXIT_SUCCESS;
}
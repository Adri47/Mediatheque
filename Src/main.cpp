#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "classes.h"
#include "commande.h"


using namespace std;
Mediatheque M; 

int main ()
{    
    string commande;
    string option;
    string donnee;

    lecture_fichier("../ressources_media/Description_commandes/Bienvenue.txt");

    while (commande != "BYE")
    {
        selection_commande(&commande);
        selection_option(&commande, &option, &M);      
    }
    
    cout << "\033[1;34mVous avez quitté la médiathèque ! Au revoir !\033[0m" << endl;
    cin.clear(); //remet l'état du flux dans un état valide (resolution pb de terminal)
    lecture_fichier("../ressources_media/Description_commandes/bye.txt");
    
    return EXIT_SUCCESS;
}
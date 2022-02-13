#include <iostream>
#include <string>
#include <fstream>
#include "main.h"
#include "classes.h"


int main() {
    
    Mediatheque M; 
    
    VHS History("Ben","History of SEE","SEE",90) ;
    DVD HP("JK.Rowling","Harry Potter à l'école des sorciers","Mappa",120,12) ;
    CD MJ("Mickeal Jackson","Thriller","Sony",72,15) ;
    Livre SA("J.R.R.Tolkien","The Lord of the ring","Marvel",1940,452) ;
    Revue SV("Ma bite","Science et vie junior - Tome 42","N/A","Hachete",12,2021,134) ;

    M.ajouter_media(&SA);

    std::cout << M ;
    std::cout << "Nombre de ressource(s) dans la médiathèque : " << M.database.size() << std::endl ;  

    
    /*
    std::ofstream fichier("../save.txt", std::ios::in);  // on ouvre le fichier en lecture
        if(fichier)  // si l'ouverture a réussi
        {       
            // instructions
                fichier << database[0]->auteur << " ";
                fichier << database[0]->titre << " " ;
                fichier << database[0]->type_media << std::endl ;
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    
   */
    return 0 ;
}
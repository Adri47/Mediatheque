#include <iostream>
#include <string>
#include "classes.h"


/*
--------------------------------------------------------
    METHODES MEDIA
--------------------------------------------------------
*/

Media::Media(std::string a, std::string t) {
    auteur = a ;
    titre = t ;
}


void Mediatheque::generation_ID(Media *m){
    /*
        ID : 
        - première lettre du type de média (ex : L pour Livre)
        - deux première lettre du titre (ex : HA pour Harry Potter)
        - trois première lettre du nom de l'auteur (ex : ROW pour JK Rowling)
        - nombre de ressources du même type dans la médiathèque 

        - Pour un livre du nom d'Harry Potter écrit par JK Rowling -> L-HA-ROW
    */
    int space = m->auteur.find(" ",0,1) ;
    int nb_ressource = 1 ;

    m->ID = m->type_media[0] ;
    m->ID += '-' ;
    m->ID += m->titre[0] ;
    m->ID += std::toupper(m->titre[1] ) ; 
    m->ID += '-' ; 
    m->ID += m->auteur[space+1] ;
    m->ID += std::toupper(m->auteur[space+2]);
    //m->ID += std::toupper(m->auteur[space+3]); 
    m->ID += '-' ;
    m->ID += std::to_string(nb_ressource); 

    for(int i = 0 ; i < database.size() ; ++i) {
        if(database[i]->ID == m->ID){
            ++nb_ressource ;
            m->ID[m->ID.length()-1] = nb_ressource + '0'; // Convertit un int en char 
        }     
    }   
}

int Media::search(std::string str) { 
    int search_autor = auteur.find(str) ;
    int search_title = titre.find(str) ;
    if (search_autor != std::string::npos || search_title != std::string::npos)
        return True ; 
    return False ;
}

void Media::print_infos(std::ostream& where) const  {

    where << "Type de ressource : " << type_media << std::endl ; 
    where << "Auteur : " << auteur << std::endl ; 
    where << "Titre : " << titre << std::endl ;

}
Media::~Media(){}
/*
--------------------------------------------------------
    METHODES MEDIATHEQUE
--------------------------------------------------------
*/

void Mediatheque::ajouter_media(Media *m) {

    generation_ID(m) ; 
    if(database == result_search)
        result_search.push_back(m) ;
   
    database.push_back(m);

}


void Mediatheque::recherche(std::string str){
    std::cout << ">> Recherche lancée : " << str << std::endl; 
    std::vector<Media *> tempo ; 
    int result ; 
    
    int nb_ressources = 0 ;

    for(int i = 0; i < result_search.size(); ++i) { 
        result = result_search[i]->search(str); 

        if (result == True){
            nb_ressources++ ;
            tempo.push_back(result_search[i]) ;
        }
    }
    if (nb_ressources == 0)
        std::cout << "\033[1;31m>> Aucune correspondance avec la chaîne recherchée : " << str << "\033[0m" << std::endl;
    else {
        std::cout << "\033[1;32m>> Nombre de ressource(s) trouvée(s) : " << nb_ressources << "\033[0m" << std::endl ;

        result_search.clear() ;
        result_search = tempo ; 
    }

    std::cout << "\033[1;32m>>----------------\nFin de recherche\n\033[0m" ;
}

Mediatheque::Mediatheque() { }

void Mediatheque::clear(){
    result_search.clear() ;
    result_search = database ; 
    std::cout << "\033[1;32m>> Buffer recherche vidé\n\033[0m" ;
}

void Mediatheque::show_ID(std::string str){
    int find = False ; 
    for(int i = 0 ; i < database.size(); ++i){
        if (database[i]->ID == str){
           std::cout << *database[i] ;  
           find = True ; 
           break ; 
        }
    }
    if (find == False)
        std::cout << "\033[1;31m>>> ID non trouvé !\n\033[0m" ;
}

// Affiche le contenu de la médiathèque
void Mediatheque::list(Mediatheque m)  {
    std::cout << "\033[1;32m>> Voici la liste des ressources de la médiathèque : \033[0m" << std::endl;
    std::cout << m ; 
}

// Supprime le contenu dans la médiathèque et dans le buffer de recherche
void Mediatheque::reset(){
    std::cout << "\033[1;32m>> Donnée(s) en cours de suppresion\n\033[0m" ;
    
    for(int i = 0 ; i < database.size(); ++ i){
        delete database[i];
    }
    
    database.clear() ;
    result_search.clear() ;
    std::cout << "\033[1;32m>> Donnée(s) effacée(s)\n\033[0m";
}

void Mediatheque::delete_ID(std::string str){
    
    std::vector<Media *> tempo = database ; 
    int wrong_ID = 1;
    database.clear() ;
    result_search.clear() ;
    for(int i = 0 ; i < tempo.size(); ++i) {
        if(tempo[i]->ID == str)
        {
            delete tempo[i] ;
            wrong_ID = 0;
            std::cout << "\033[1;32m>> Ressource supprimée !\n\033[0m" ;
        }

        else {
            database.push_back(tempo[i]) ; 
            result_search.push_back(tempo[i]) ;
        }
    }
    if (wrong_ID == 1)
    {
        std::cout << "\033[1;31m>> Mauvais ID !\n\033[0m" ;
        wrong_ID = 1;
    }
    
}

/*
--------------------------------------------------------
SURCHAGE D'OPERATEUR
--------------------------------------------------------
*/
std::ostream& operator<<(std::ostream& out , Media& m) {
    m.print_infos(out) ;
    out << "Etiquette : " << m.ID << std::endl ; 
    out << "------------------" << std::endl;
    return out ; 
}


std::ostream& operator<<(std::ostream& out , Mediatheque& M) {

   for (int i = 0 ; i < M.result_search.size() ; ++ i) {
       out << *M.result_search[i] ;
   }
    return out ;
}
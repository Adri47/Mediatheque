#include <iostream>
#include <string>
#include "classes.h"

Media::Media(std::string a, std::string t) {
    auteur = a ;
    titre = t ;
}

Mediatheque::Mediatheque() { }

void Mediatheque::generation_ID(Media *m){
    /*
        ID : 
        - première lettre du type de média (ex : L pouur Livre)
        - deux première lettre du titre (ex : HA pour Harry Potter)
        - trois première lettre du nom de l'auteur ( ROW pour JK Rowling)

        - Pour un livre du nom d'Harry Potter écrit par JK Rowling -> L-HA-ROW
    */
    int space = m->auteur.find(" ",0,1) ;
    m->ID = m->type_media[0] ;
    m->ID += '-' ;
    m->ID += m->titre[0] ;
    m->ID += std::toupper(m->titre[1] ) ; 
    m->ID += '-' ; 
    m->ID += m->auteur[space+1] ;
    m->ID += std::toupper(m->auteur[space+2]);
    m->ID += std::toupper(m->auteur[space+3]); 

    //std::cout << m->ID << std::endl; 
}

void Mediatheque::ajouter_media(Media *m) {
   
    generation_ID(m) ; 
    database.push_back(m);
}

/*
--------------------------------------------------------
SURCHAGE D'OPERATEUR
--------------------------------------------------------
*/
std::ostream& operator<<(std::ostream& out , Media& m) {
    out << "Type de ressource : " << m.type_media << std::endl ; 
    out << "Auteur : " << m.auteur << std::endl ; 
    out << "Titre : " << m.titre << std::endl ; 

    return out ;
}


std::ostream& operator<<(std::ostream& out , Mediatheque& M) {

    for (int i = 0; i < M.database.size(); i++) {
        Media *m = M.database[i];
        if(m->type_media == "VHS") {
            VHS *t =  dynamic_cast<VHS*>(m);
            out << *t ;

        }
        else if (m->type_media == "DVD")
        {
            DVD *t =  dynamic_cast<DVD*>(m);
            out << *t ;
        }
        else if (m->type_media == "Livre")
        {
            Livre *t =  dynamic_cast<Livre*>(m);
            out << *t ;
        }
        else if (m->type_media == "CD")
        {
            CD *t =  dynamic_cast<CD*>(m);
            out << *t ;
        }
        else if (m->type_media == "Revue")
        {
            Revue *t =  dynamic_cast<Revue*>(m);
            out << *t ;
        } 
    }
    
    return out ;
}
#include <iostream>
#include <string>
#include "classes.h"


// VHS
VHS::VHS(std::string auteur ,std::string titre, std::string maison_prod, int duree ) 
    : Media(auteur, titre) {
        this->maison_prod = maison_prod ;
        this->duree = duree ;
        type_media = type ; 

}

// DVD
DVD::DVD(std::string auteur ,std::string titre, std::string maison_prod, int duree, int nb_pistes ) 
    : VHS(auteur,titre, maison_prod, duree) { 
        nbpistes = nb_pistes ;
        type_media = type ; 
    }


std::ostream& operator<<(std::ostream& out , VHS& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Maison de production : " << s.maison_prod << std::endl ; 
    out << "Durée : " << std::to_string(s.duree) << " min" <<std::endl ; 
    out << "------------------" << std::endl;

    return out ;
}

std::ostream& operator<<(std::ostream& out , DVD& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Maison de production : " << s.maison_prod << std::endl ; 
    out << "Durée : " << std::to_string(s.duree) << " min" <<std::endl ; 
    out << "Nombre de pistes : " << std::to_string(s.nbpistes) << std::endl;
    out << "------------------" << std::endl;

    return out ;
}


#include <iostream>
#include <string>
#include "classes.h"

Media::Media(std::string a, std::string t) {
    auteur = a ;
    titre = t ;
}


std::ostream& operator<<(std::ostream& out , Media& m) {
    out << "Auteur : " << m.auteur << std::endl ; 
    out << "Titre : " << m.titre << std::endl ; 
    out << "Type de ressource : " << m.type_media << std::endl ; 

    return out ;
}
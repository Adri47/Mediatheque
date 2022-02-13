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

// CD
CD::CD(std::string auteur ,std::string titre, std::string maison_prod, int duree , int nb_pistes)
    : VHS(auteur,titre, maison_prod, duree) { 
        nbpistes = nb_pistes ;
        type_media = type ; 
    }


Livre::Livre (std::string auteur ,std::string titre, std::string collection ,int annee, int pages) 
    : Media(auteur,titre) {
        this->collection = collection ;
        parrution = annee ;
        nb_page = pages ;
        type_media = type ; 
    }

Revue::Revue(std::string auteur ,std::string titre, std::string collection,std::string editeur,int nb_articles, int annee, int pages) 
    : Livre(auteur,titre,collection,annee,pages){
        this->editeur = editeur ;
        this->nb_articles = nb_articles;
        type_media = type ; 
    }

/*
--------------------------------------------------------
SURCHAGE D'OPERATEUR
--------------------------------------------------------
*/
std::ostream& operator<<(std::ostream& out , VHS& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Maison de production : " << s.maison_prod << std::endl ; 
    out << "Durée : " << s.duree << " min" <<std::endl ; 
    out << "------------------" << std::endl;

    return out ;
}

std::ostream& operator<<(std::ostream& out , DVD& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Maison de production : " << s.maison_prod << std::endl ; 
    out << "Durée : " << s.duree << " min" <<std::endl ; 
    out << "Nombre de pistes : " << s.nbpistes << std::endl;
    out << "------------------" << std::endl;

    return out ;
}

std::ostream& operator<<(std::ostream& out , CD& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Maison de production : " << s.maison_prod << std::endl ; 
    out << "Durée : " << s.duree << " min" <<std::endl ; 
    out << "Nombre de pistes : " << s.nbpistes << std::endl;
    out << "------------------" << std::endl;

    return out ;
}

std::ostream& operator<<(std::ostream& out , Livre& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Collection : " << s.collection << std::endl ; 
    out << "Année de parution : " << s.parrution << std::endl ; 
    out << "Nombre de pages : " << s.nb_page <<std::endl ; 
    out << "------------------" << std::endl;

    return out ;
}

std::ostream& operator<<(std::ostream& out , Revue& s) {
    out << "Type de ressource : " << s.type_media << std::endl ; 
    out << "Titre : " << s.titre << std::endl ; 
    out << "Auteur : " << s.auteur << std::endl ; 
    out << "Collection : " << s.collection << std::endl ; 
    out << "Editeur : " << s.editeur << std::endl; 
    out << "Année de parution : " << s.parrution << std::endl ; 
    out << "Nombre d'articles : " << s.nb_articles << std::endl ; 
    out << "Nombre de pages : " << s.nb_page <<std::endl ; 
    out << "------------------" << std::endl;

    return out ;
}
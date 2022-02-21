#include <iostream>
#include <string>
#include "classes.h"

/*
--------------------------------------------------------
CONSTRUCTEURS
--------------------------------------------------------
*/
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

// Livre
Livre::Livre (std::string auteur ,std::string titre, std::string collection ,int annee, int pages) 
    : Media(auteur,titre) {
        this->collection = collection ;
        parrution = annee ;
        nb_page = pages ;
        type_media = type ; 
    }

// Revue
Revue::Revue(std::string auteur ,std::string titre, std::string collection,std::string editeur,int nb_articles, int annee, int pages) 
    : Livre(auteur,titre,collection,annee,pages){
        this->editeur = editeur ;
        this->nb_articles = nb_articles;
        type_media = type ; 
    }

/*
--------------------------------------------------------
METHODES
--------------------------------------------------------
*/

int VHS::search(std::string str)
{

    int result = Media::search(str) ; // appelle la méthode de la fonction mère
    int search_maison = maison_prod.find(str) ;
    int search_duration = std::to_string(duree).find(str) ;
    
    if (search_maison != std::string::npos || search_duration != std::string::npos )
        result = True ;
    return result ;
}

int CD::search(std::string str)
{
    int result = VHS::search(str) ; // appelle la méthode de la fonction mère
    int nbpistes = std::to_string(duree).find(str) ;
    
    if (nbpistes != std::string::npos )
        result = True ;
    return result ;
}

int DVD::search(std::string str)
{
    int result = VHS::search(str) ; // appelle la méthode de la fonction mère
    int nbpistes = std::to_string(duree).find(str) ;
    
    if (nbpistes != std::string::npos )
        result = True ;
    return result ;
}

int Livre::search(std::string str)
{
    int result = Media::search(str) ; // appelle la méthode de la fonction mère
    int search_collection = collection.find(str) ;
    int search_years = std::to_string(parrution).find(str) ;
    int search_pages = std::to_string(nb_page).find(str) ;

    if (search_collection != std::string::npos || search_years != std::string::npos ||search_pages != std::string::npos )
        result = True ;
    return result ;
}

int Revue::search(std::string str)
{

    int result = Livre::search(str) ; // appelle la méthode de la fonction mère

    int search_edition = editeur.find(str) ;
    int search_articles = std::to_string(nb_articles).find(str);


    if (search_edition != std::string::npos || search_articles != std::string::npos )
        result = True ;
    return result ;
}


void VHS::print_infos(std::ostream& where ) const {
    Media::print_infos(where) ;
    where << "Maison de production : " << maison_prod << std::endl ; 
    where << "Durée : " << duree << " min" << std::endl ; 
}

void DVD::print_infos(std::ostream& where ) const {
    VHS::print_infos(where) ;
    where << "Nombre de pistes : " << nbpistes << std::endl;

}

void CD::print_infos (std::ostream& where) const {
    VHS::print_infos(where);
    where << "Nombre de pistes : " << nbpistes << std::endl;

}
void Livre::print_infos(std::ostream& where) const {  
    Media::print_infos(where) ;
    where << "Collection : " << collection << std::endl ; 
    where << "Année de parution : " << parrution << std::endl ; 
    where << "Nombre de pages : " << nb_page <<std::endl ; 
}

void Revue::print_infos(std::ostream& where) const {
    Livre::print_infos(where) ;
    where << "Editeur : " << editeur << std::endl; 
    where << "Nombre d'articles : " << nb_articles << std::endl ; 

    
}

/*
--------------------------------------------------------
SURCHAGE D'OPERATEUR
--------------------------------------------------------
*/
std::ostream& operator<<(std::ostream& out , VHS& s) {
    s.print_infos(out) ; 
    return out ;
}

std::ostream& operator<<(std::ostream& out , DVD& s) {
    s.print_infos(out) ;
    return out ;
}

std::ostream& operator<<(std::ostream& out , CD& s) {
    s.print_infos(out) ;
    return out ;
}

std::ostream& operator<<(std::ostream& out , Livre& s) {
    s.print_infos(out);
    return out ;
}

std::ostream& operator<<(std::ostream& out , Revue& s) {
    s.print_infos(out) ;
    return out ;
}
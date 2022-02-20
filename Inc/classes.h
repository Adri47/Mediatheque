#include <iostream>
#include "media.h"

#ifndef CLASSES_H
#define CLASSES_H

class VHS : public Media{
    public : 
        VHS(std::string auteur ,std::string titre, std::string maison_prod, int duree, int annee ) ;
        friend std::ostream& operator<<(std::ostream& , VHS&);

        std::string maison_prod;
        std::string type = "VHS"; 
        int duree ;  
        int annee;     
} ;

class DVD : public VHS{
    public :
        DVD (std::string auteur ,std::string titre, std::string maison_prod, int duree, int annee ) ;
        friend std::ostream& operator<<(std::ostream& , DVD&);
        
        std::string type = "DVD"; 
        int annee ;
} ;

class CD : public VHS {
    public :
        CD(std::string auteur ,std::string titre, std::string maison_prod, int duree , int nb_pistes) ;
        friend std::ostream& operator<<(std::ostream& , CD&);

        std::string type = "CD"; 
        int nbpistes ; 
} ;

class Livre : public Media {
    public : 
        Livre (std::string auteur ,std::string titre, std::string collection,int annee, int pages) ;
        friend std::ostream& operator<<(std::ostream& , Livre&);

        std::string collection ;
        std::string type = "Livre" ; 
        int parrution ;
        int nb_page ; 
} ;


class Revue : public Livre {
    public : 
        Revue(std::string auteur ,std::string titre, std::string collection,std::string editeur,int nb_articles, int annee, int pages) ;
        friend std::ostream& operator<<(std::ostream& , Revue&);

        std::string editeur ;
        std::string type = "Revue" ; 
        int nb_articles ;
} ;

#endif

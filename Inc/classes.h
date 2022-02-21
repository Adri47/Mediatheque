#include <iostream>
#include "media.h"

class VHS : public Media{
    public : 
        VHS(std::string auteur ,std::string titre, std::string maison_prod, int duree ) ;
        virtual ~VHS(){} ;
        virtual int search(std::string str) ;
        virtual void print_infos(std::ostream& where) const ; 
        friend std::ostream& operator<<(std::ostream& , VHS&);

        std::string maison_prod;
        std::string type = "VHS"; 
        int duree ;       
} ;

class DVD : public VHS{
    public :
        DVD (std::string auteur ,std::string titre, std::string maison_prod, int duree, int nb_pistes ) ;
        virtual ~DVD(){} ;
        int search(std::string str) ;
        virtual void print_infos(std::ostream& where) const ; 
        friend std::ostream& operator<<(std::ostream& , DVD&);
        
        std::string type = "DVD"; 
        int nbpistes ;
} ;

class CD : public VHS {
    public :
        CD(std::string auteur ,std::string titre, std::string maison_prod, int duree , int nb_pistes) ;
        virtual ~CD(){} ;
        int search(std::string str) ;
        virtual void print_infos(std::ostream& where) const ; 
        friend std::ostream& operator<<(std::ostream& , CD&);

        std::string type = "CD"; 
        int nbpistes ; 
} ;

class Livre : public Media {
    public : 
        Livre (std::string auteur ,std::string titre, std::string collection,int annee, int pages) ;
        virtual ~Livre(){} ;
        int search(std::string str) ;
        virtual void print_infos(std::ostream& where) const ; 
        friend std::ostream& operator<<(std::ostream& , Livre&);

        std::string collection ;
        std::string type = "Livre" ; 
        int parrution ;
        int nb_page ; 

        
} ;


class Revue : public Livre {
    public : 
        Revue(std::string auteur ,std::string titre, std::string collection,std::string editeur,int nb_articles, int annee, int pages) ;
        virtual ~Revue(){} ;
        int search(std::string str) ;
        void print_infos(std::ostream& where) const ; 
        friend std::ostream& operator<<(std::ostream& , Revue&);

        std::string editeur ;
        std::string type = "Revue" ; 
        int nb_articles ;
} ;

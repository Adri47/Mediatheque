#include <iostream>
#include "media.h"

class VHS : public Media{
    public : 
        VHS(std::string auteur ,std::string titre, std::string maison_prod, int duree ) ;
        friend std::ostream& operator<<(std::ostream& , VHS&);

        std::string maison_prod;
        std::string type = "VHS"; 
        int duree ;       
} ;

class DVD : public VHS{
    public :
        DVD (std::string auteur ,std::string titre, std::string maison_prod, int duree, int nb_pistes ) ;
        friend std::ostream& operator<<(std::ostream& , DVD&);
        
        std::string type = "DVD"; 
        int nbpistes ;
} ;

class Livre : public Media {
    public : 
        Livre () ;

        std::string maison_edition ;
        std::string type = "Livre" ; 
        int annee ;
        int page ; 
} ;


class Revue : public Livre {
    public : 
        Revue() ;

        std::string editeur ;
        std::string type = "Revue" ; 
        int nb_articles ;
} ;

class CD : public Media {
    public :
        CD() ;

        std::string maison_prod;
        std::string type = "CD"; 
        int annee ;
        int nb_pistes ; 
} ;
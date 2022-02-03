#include <iostream>
#include "media.h"


class DVD : public Media{
    public :
        DVD () ;
} ;

class Livre : public Media {
    public : 
        Livre () ;
        std::string auteur;
        std::string titre ;
        std::string maison_edition ;
        int annee ;
        int page ; 
} ;

class VHS : public Media {
    public : 
        VHS() ;
} ;

class Revue : public Media {
    public : 
        Revue() ;
} ;

class CD : public Media {
    public :
        CD() ;
} ;
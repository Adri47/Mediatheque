#include <iostream>

class Media{
    public :
        Media () ;
};


class DVD : public Media{
    public :
        DVD () ;
} ;

class Livre : public Media {
    public : 
        Livre () ;
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
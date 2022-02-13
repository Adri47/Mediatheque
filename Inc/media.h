#include <iostream>
#include <vector>

#ifndef MEDIA_H
#define MEDIA_H

class Media{
    public :
        Media(std::string auteur, std::string titre) ;
        virtual ~Media(){} ;
        friend std::ostream& operator<<(std::ostream& , Media&);

        std::string auteur;
        std::string titre ;
        std::string type_media ;
        std::string ID ;  
};

class Mediatheque{
    public: 
        Mediatheque() ;
        friend std::ostream& operator<<(std::ostream& , Mediatheque&);
        void ajouter_media(Media *m) ;
        void generation_ID(Media *m) ;
        void recherche(Media *m) ;

        std::vector<Media*> database ; 
};

#endif
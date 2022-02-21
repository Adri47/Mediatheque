#include <iostream>
#include <vector>

#ifndef MEDIA_H
#define MEDIA_H

#define True 1
#define False 0 

class Media{
    public :
        Media(std::string auteur, std::string titre) ;
        virtual ~Media() = 0 ;
        virtual int search(std::string str) ;
        virtual void print_infos(std::ostream& where) const ; 
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
        void recherche(std::string str) ;
        void show_IT(std::string str) ;
        void delete_IT(std::string str) ;
        void list(Mediatheque m) ;
        void reset();
        void clear() ;
        
        std::vector<Media*> result_search ; 
        std::vector<Media*> database ;       
};
#endif
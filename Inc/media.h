#include <iostream>

class Media{
    public :
        Media(std::string auteur, std::string titre) ;
        virtual ~Media(){} ;
        friend std::ostream& operator<<(std::ostream& , Media&);

        std::string auteur;
        std::string titre ;
        std::string type_media ;
    private :
        std::ostream& print() ;
};

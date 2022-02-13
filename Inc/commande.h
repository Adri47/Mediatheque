#include <iostream>
#include "media.h"

#define MAX_INFO_LIVRE 5
using namespace std;

void lecture_clavier(string chaine_ecran, string *donnee_clavier);
void lecture_fichier(string nom_fichier);
void ecriture_fichier(string nom_fichier, string texte);
void recup_string(string separateur, string *premier_mot, string *deuxieme_mot);
void selection_commande(string *commande);
void selection_option(string *commande, string *option, vector<Media*> database);
void commande_ADD(string *type, vector<Media*> database);
void recup_donnee_livre(string donnee, string *donnee_livre);
void recup_donnee_dvd(string donnee, string *donnee_dvd);

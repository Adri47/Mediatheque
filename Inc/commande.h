#include <iostream>
#include "media.h"

#ifndef COMMANDE_H
#define COMMANDE_H

#define MAX_INFO_LIVRE 5
using namespace std;

void lecture_clavier(string chaine_ecran, string *donnee_clavier);
void lecture_fichier(string nom_fichier);
void ecriture_fichier(string nom_fichier, string texte);
void recup_string(string separateur, string *premier_mot, string *deuxieme_mot);
void selection_commande(string *commande);
void selection_option(string *commande, string *option, Mediatheque* database);
void commande_ADD(string *type, Mediatheque* database);
void recup_donnee_livre(string donnee, string *donnee_livre);
void recup_donnee_dvd(string donnee, string *donnee_dvd);

#endif

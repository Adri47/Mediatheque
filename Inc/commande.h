#include <iostream>
#include "media.h"

#ifndef COMMANDE_H
#define COMMANDE_H

#define MAX_INFO_LIVRE  5
#define MAX_INFO_DVD    5
#define MAX_INFO_VHS    5
#define MAX_INFO_CD     5
#define MAX_INFO_REVUE  7


using namespace std;

void lecture_clavier(string chaine_ecran, string *donnee_clavier);
void lecture_fichier(string nom_fichier);
void ecriture_fichier(string nom_fichier, string texte);
void recup_string(string separateur, string *premier_mot, string *deuxieme_mot);
void selection_commande(string *commande);
void selection_option(string *commande, string *option, Mediatheque* database);
int commande_ADD(string *type, Mediatheque* database);
int commande_SAVE(string nom_fichier, Mediatheque *media);
int commande_CLEAR();
int recup_donnee_ressource (string donnee, string *donnee_ressources, int nombre_ressources);
int verif_buffer_string(string *buffer, int nb_element);

#endif

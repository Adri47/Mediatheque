#include <iostream>
#include "media.h"

#ifndef COMMANDE_H
#define COMMANDE_H

#define MAX_INFO_LIVRE  5
#define MAX_INFO_DVD    5
#define MAX_INFO_VHS    4
#define MAX_INFO_CD     5
#define MAX_INFO_REVUE  7


using namespace std;

/**
 * Lecture des donnees entrees par l'utilisateur sur le terminal
 *
 * @param chaine_ecran [in] string a afficher sur le terminal avant lecture
 * @param donnee_clavier [in] pointeur permettant de stocker la lecture
 *
 * @return -no return
 */

void lecture_clavier(string chaine_ecran, string *donnee_clavier);

/**
 * Lecture d'un fichier et l'affiche sur le terminal 
 *
 * @param nom_fichier [in] nom du fichier
 *
 * @return -no return
 */
void lecture_fichier(string nom_fichier);

/**
 * Ecriture dans un fichier texte
 *
 * @param nom_fichier [in] nom du fichier 
 * @param texte [in] texte a ecrire dans le fichier texte
 *
 * @return -no return
 */
void ecriture_fichier(string nom_fichier, string texte);

/**
 * Separation d'un string en deux mots a partir d'un separateur  
 *
 * @param nom_fichier [in] nom du fichier 
 * @param texte [in] texte a ecrire dans le fichier texte
 *
 * @return -no return
 */
void recup_string(string separateur, string *premier_mot, string *deuxieme_mot);

/**
 * Selection de la commande a partir d'un string rentre par l'utilisateur   
 *
 * @param commande [in] nom du fichier 
 *
 * @return -no return
 */
void selection_commande(string *commande);

/**
 * Selection de l'option a partir d'un string rentre par l'utilisateur   
 *
 * @param commande [in] nom de la commande
 * @param option [in] nom de l'option
 * @param database [in] classe mediatheque 
 *
 * @return -no return
 */
void selection_option(string *commande, string *option, Mediatheque* database);

/**
 * Ajout d'une ressource dans la mediatheque   
 *
 * @param type [in] type de ressource a ajouter 
 * @param database [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_ADD(string *type, Mediatheque* database);

/**
 * Sauvegarde de toutes les ressources dans un fichier texte dans le dossier Dossier_User/   
 *
 * @param nom_fichier [in] nom du fichier texte
 * @param media [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_SAVE(string nom_fichier, Mediatheque *media);

/**
 * Rechercher une ressource dans la classe mediatheque utilisee   
 *
 * @param recherche [in] string de recherche
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_SEARCH(string recherche, Mediatheque *M);

/**
 * Afficher les information d'une ressource   
 *
 * @param ressource [in] identifiant de la ressource
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_SHOW(string ressource, Mediatheque *M);

/**
 * Supprimer une ressource  
 *
 * @param ressource [in] identifiant de la ressource
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_DELETE(string ressource, Mediatheque *M);

/**
 * Effacer le buffer de recherche  
 *
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_CLEAR(Mediatheque *M);

/**
 * Vider toute la mediatheque  
 *
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_RESET(Mediatheque *M);

/**
 * Lister toute les ressources de manière compacte  
 *
 * @param M [in] classe mediatheque 
 * 
 * @return 0 si pas de probleme
 */
int commande_LIST(Mediatheque *M);

/**
 * Charger un fichier texte contenant les ressources a mettre dans la mediatheque. Celle-ci sera reinitialisee puis charger.  
 *
 * @param nom_fichier_txt [in] nom du fichier texte avec les ressources a stocker
 * @param M [in] mediatheque ou on vient stocker les nouvelles ressources
 * 
 * @return 0 si pas de probleme
 */
int commande_LOAD(string nom_fichier_txt, Mediatheque *M);

/**
 * Fonction utilisee dans la fonction commande_ADD pour stocker les donnee rentree par l'utilisateur   
 *
 * @param donnee [in] donnee entree par l'utilisateur
 * @param donnee_ressources [in] buffer pour le stockage des donnees
 * @param nombre_ressources [in] nombre de ressources a entrer par l'utilisateur
 * 
 * @return 0 si pas de probleme
 */
int recup_donnee_ressource (string donnee, string *donnee_ressources, int nombre_ressources);



#endif

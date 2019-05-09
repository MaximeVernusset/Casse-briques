#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


/// Bobliothèques
#include "newtypes.h"
#include "barre.h"
#include "balle.h"
#include "briques.h"
#include "bonus.h"
#include "utile.h"


/// Définitions
#define SEUIL_VIE_UP 100

#define DUREE_AFFICHAGE_EVENEMENT 80
#define REST 20


/// Prototypes
void afficher_hub(t_global* donnees);
void affichage(t_global* donnees, int* p_duree_affichage_evenement);
void deplacement(t_global* donnees);
void collisions(t_global* donnees, int* duree_affichage_evenement);
void pause(t_global* donnees);
void musique(t_global* donnees);
booleen niveau_suivant(t_global* donnees);
void vie_up(t_global* donnees, int* p_centaine, int* p_duree_affichage_evenement); /// Ajoute une balle tous "SEUIL_VIE_UP" points.
void jouer(t_global* donnees);


#endif // JEU_H_INCLUDED

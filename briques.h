#ifndef BRIQUES_H_INCLUDED
#define BRIQUES_H_INCLUDED


/// Bibliothèques
#include "utile.h"
#include "newtypes.h"
#include "barre.h"
#include "bonus.h"


/// Définitions
#define FIN_PARTIE true

#define NB_BRIQUE_W  20
#define NB_BRIQUE_H  15
#define BRIQUE_W     SCREEN_W/NB_BRIQUE_W
#define BRIQUE_H     SCREEN_H/2/NB_BRIQUE_H

#define TYPE_FAIBLE   1
#define TYPE_MOYENNE  2
#define TYPE_FORTE    3
#define TYPE_BONUS    4

#define COULEUR_FAIBLE  makecol(255,255,0)
#define COULEUR_MOYENNE makecol(0,255,0)
#define COULEUR_FORTE   makecol(0,0,255)
#define COULEUR_BONUS   makecol(255,255,255)
#define VIE_FAIBLE    1
#define VIE_MOYENNNE  2
#define VIE_FORTE     3
#define VIE_BONUS     5

#define FREQ_RAFRAICHISSEMENT 750




/// Prototypes
booleen init_niveau(t_global* donnees); /// Charge en mémoire les données de toutes les briques du niveau correspondant.
void actionner_briques(t_global* donnees); /// Désactive les briques si elles n'ont plus de vie.
booleen reste_briques(t_global* donnees);
void afficher_briques(t_global* donnees);
void raffraichir_niveau(t_global* donnees, int* nb_tour);
void liberer_niveau(t_global* donnees); /// Si le joueur a perdu, on libère la liste chainné de briques pour en recréer une nouvelle pour éviter des bugs.


#endif // BRIQUES_H_INCLUDED

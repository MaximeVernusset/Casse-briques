#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED


/// Bibliothèques
#include "newtypes.h"
#include "briques.h"
#include "balle.h"


/// Définitions
enum
{
    BONUS_BALLE = 0,
    BONUS_BARRE = 1,
    BONUS_DEGAT = 2,
    BONUS_VIE = 3,
    BONUS_POINT = 4,
    BONUS_INVINCIBILITE = 5,
    NB_BONUS = 6,
};


/*#define BONUS_BALLE 0
#define BONUS_BARRE 1
#define BONUS_DEGAT 2
#define BONUS_VIE   3
#define BONUS_POINT 4
#define BONUS_INVINCIBILITE 5
#define NB_BONUS    6*/
#define BONUS_R     10*SCREEN_W/SCREEN_H

#define NB_POINTS_BONUS 10


/// Prototypes
void creer_bonus(t_global* donnees, t_brique* brique);
void deplacer_bonus(t_global* donnees);
void collisions_bonus(t_global* donnees, int* p_duree_affichage_evenement);
void afficher_bonus(t_global* donnees);
void creer_balle_bonus(t_global* donnees, t_bonus* bonus);
void deplacer_balles_bonus(t_global* donnees);
void collisions_balles_bonus(t_global* donnees);
void afficher_balles_bonus(t_global* donnees);


#endif // BONUS_H_INCLUDED

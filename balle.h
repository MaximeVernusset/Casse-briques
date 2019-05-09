#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED


/// Bibliothèques
#include <math.h>
#include "utile.h"
#include "newtypes.h"
#include "barre.h"


/// Définitions
#define BALLE_R HAUTEUR_FENETRE/80
#define BALLE_VIE 5
#define BALLE_DEGATS 1
#define BALLE_COULEUR makecol(255,0,55)
#define BALLE_CONTOUR makecol(128,128,128)
#define COEFF_VITESSE ((HAUTEUR_FENETRE+LARGEUR_FENETRE)/2)/350
#define FRITTAGE_VITESSE 2

#define MALUS_BALLE_PERDUE 3

#define PI 3.1416


/// Prototypes
void init_balle(t_global* donnees);
void reinit_balle(t_global* donnees);
void afficher_balle(t_global* donnees);
void deplacer_balle(t_global* donnees);
void collisions_balle(t_global* donnees);
booleen reste_balles(t_global* donnees);

#endif // BALLE_H_INCLUDED

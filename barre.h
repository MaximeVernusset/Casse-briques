#ifndef BARRE_H_INCLUDED
#define BARRE_H_INCLUDED

/// Bibliothèques
#include "utile.h"
#include "newtypes.h"

/// Définitions
#define BARRE_H HAUTEUR_FENETRE/50
#define BARRE_W  LARGEUR_FENETRE/8
#define BARRE_V ((HAUTEUR_FENETRE+LARGEUR_FENETRE))/100
#define ECART_BARRE 5
#define COULEUR_BARRE makecol(128,128,128)
#define COULEUR_CONTOUR makecol(255,0,255)
#define BONUS_TAILLE 15


/// Prototypes
void init_barre(t_global* donnees);
void afficher_barre(t_global* donnees);
void deplacer_barre(t_global* donnees);

#endif // BARRE_H_INCLUDED

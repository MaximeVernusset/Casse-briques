#include "barre.h"


void init_barre(t_global* donnees)
{
    (donnees->barre).x = SCREEN_W/2 - BARRE_W/2;
    (donnees->barre).y = SCREEN_H  - (BARRE_H + ECART_BARRE);
    (donnees->barre).couleur = COULEUR_BARRE;
    (donnees->barre).vitesse = BARRE_V;
    (donnees->barre).bonus_taille = 0;
}



void afficher_barre(t_global* donnees)
{
    rectfill(donnees->buffer, (donnees->barre).x-(donnees->barre).bonus_taille, (donnees->barre).y, (donnees->barre).x+BARRE_W+(donnees->barre).bonus_taille, (donnees->barre).y+BARRE_H, (donnees->barre).couleur);
    rect(donnees->buffer, (donnees->barre).x-(donnees->barre).bonus_taille, (donnees->barre).y, (donnees->barre).x+BARRE_W+(donnees->barre).bonus_taille, (donnees->barre).y+BARRE_H, COULEUR_CONTOUR);
}



void deplacer_barre(t_global* donnees)
{

    if(key[KEY_LEFT])
        (donnees->barre).x -= (donnees->barre).vitesse;

    if(key[KEY_RIGHT])
        (donnees->barre).x += (donnees->barre).vitesse;

    if((donnees->barre).x - (donnees->barre).bonus_taille < 0)
        (donnees->barre).x = (donnees->barre).bonus_taille;

    if((donnees->barre).x + BARRE_W + (donnees->barre).bonus_taille > SCREEN_W - 1)
        (donnees->barre).x = SCREEN_W- 1 - BARRE_W - (donnees->barre).bonus_taille;
}

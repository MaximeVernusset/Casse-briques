#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <allegro.h>


#define BONUS_MAX 20
#define BALLE_MAX 4



/// Type booléen
typedef int booleen;


/// Définitons des types structurés

typedef struct barre
{
    float x, y;
    int couleur;
    float vitesse;
    int bonus_taille;
}t_barre;


typedef struct balle
{
    float x, y, vx, vy;
    int couleur, vie, degats, nb_rebonds, invincibilite;
}t_balle;

typedef struct brique
{
    int type, x, y, couleur, vie;
}t_brique;


typedef struct bonus
{
    float x, y, vy;
    int type;
}t_bonus;


typedef struct police
{
    PALETTE palette;
    FONT* myfont1;
    FONT* myfont2;
    FONT* myfont3;
}t_police;


typedef struct musique
{
   SAMPLE* collision;
   SAMPLE* casse;
   SAMPLE* balle_perdue;
   SAMPLE* vie_up;
   SAMPLE* bonus_taken;
   SAMPLE* music;
   booleen play_music;
   booleen play_sfx;
}t_musique;


typedef struct global
{
    int niveau, score, nb_briques;
    char evenement[40];
    t_barre barre;
    t_balle balle;
    t_balle* balle_bonus[BALLE_MAX];
    BITMAP* buffer;
    t_bonus* bonus[BONUS_MAX];
    t_brique** briques;
    t_police police;
    t_musique musique;
}t_global;


#endif // STRUCTURES_H_INCLUDED

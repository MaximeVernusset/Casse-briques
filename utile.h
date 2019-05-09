#ifndef UTILE_H_INCLUDED
#define UTILE_H_INCLUDED

/// Biblioth�ques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

#include "newtypes.h"
#include "briques.h"


/// D�finitions
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define ZONE_BRIQUE_W   LARGEUR_FENETRE
#define ZONE_BRIQUE_H   HAUTEUR_FENETRE/2

#define false         0
#define true          1


/// Prototypes
void lancerToutAllegro(int largeur, int hauteur);
booleen load_settings(t_global* donnees);
void init_font(t_global* donnees);
void init_musique(t_global* donnees);
void reinitialiser_settings(t_global* donnees); // Remet le niveau � 1 dans le fichier settings, si tous les niveaux ont �t� termin�s.
void save_settings(t_global* donnees);
void free_memoire(t_global* donnees); // Lib�re la m�moire allou� dynamiquement

#endif // UTILE_H_INCLUDED

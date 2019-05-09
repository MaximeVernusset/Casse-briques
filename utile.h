#ifndef UTILE_H_INCLUDED
#define UTILE_H_INCLUDED

/// Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

#include "newtypes.h"
#include "briques.h"


/// Définitions
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
void reinitialiser_settings(t_global* donnees); // Remet le niveau à 1 dans le fichier settings, si tous les niveaux ont été terminés.
void save_settings(t_global* donnees);
void free_memoire(t_global* donnees); // Libère la mémoire alloué dynamiquement

#endif // UTILE_H_INCLUDED

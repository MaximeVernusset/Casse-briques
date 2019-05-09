#include "utile.h"
#include "newtypes.h"
#include "barre.h"
#include "balle.h"
#include "briques.h"
#include "jeu.h"




int main()
{
    srand(time(NULL)); // Initialisation su système aléatoire

    t_global* donnees = (t_global*)malloc(sizeof(t_global)); // Allocation de la mémoire pour stocker les données de jeu

    lancerToutAllegro(LARGEUR_FENETRE, HAUTEUR_FENETRE); // Ouverture de la fenêtre graphique et initialisation du son, clavier, souris...

    ///Initialisation
    set_window_title("Casse Briques"); // Définit le titre de la fenêtre
    init_font(donnees); // Charge les polices d'écriture
    init_musique(donnees); // Charge de sons
    donnees->buffer = create_bitmap(SCREEN_W, SCREEN_H); // Création du buffer d'image

    strcpy(donnees->evenement, "");

    jouer(donnees); // Lancement du jeu

    free_memoire(donnees); // Libère toute la mémoire allouée dynamiquement

    return 0;

}END_OF_MAIN();

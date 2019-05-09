#include "utile.h"
#include "newtypes.h"
#include "barre.h"
#include "balle.h"
#include "briques.h"
#include "jeu.h"




int main()
{
    srand(time(NULL)); // Initialisation su syst�me al�atoire

    t_global* donnees = (t_global*)malloc(sizeof(t_global)); // Allocation de la m�moire pour stocker les donn�es de jeu

    lancerToutAllegro(LARGEUR_FENETRE, HAUTEUR_FENETRE); // Ouverture de la fen�tre graphique et initialisation du son, clavier, souris...

    ///Initialisation
    set_window_title("Casse Briques"); // D�finit le titre de la fen�tre
    init_font(donnees); // Charge les polices d'�criture
    init_musique(donnees); // Charge de sons
    donnees->buffer = create_bitmap(SCREEN_W, SCREEN_H); // Cr�ation du buffer d'image

    strcpy(donnees->evenement, "");

    jouer(donnees); // Lancement du jeu

    free_memoire(donnees); // Lib�re toute la m�moire allou�e dynamiquement

    return 0;

}END_OF_MAIN();

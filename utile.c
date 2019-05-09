#include "utile.h"


void lancerToutAllegro(int largeur, int hauteur)
{
    allegro_init();
    install_keyboard();
    install_mouse();
    (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") /*!= 0*/);

    // OUVERTURE MODE GRAPHIQUE (ouverture fenêtre allegro)
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("Probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_mouse();
}



/*booleen load_settings(t_global* donnees)
{
    FILE* fichier = fopen("settings\\parametres.set", "r");

    if(fichier != NULL)
    {
        fscanf(fichier, "%d", &(donnees->niveau));
        if(donnees->niveau <= 0)
            donnees->niveau = 1;
        fscanf(fichier, "%d", &(donnees->musique.play_music));
        fscanf(fichier, "%d", &(donnees->musique.play_sfx));
        //fclose(fichier);
        return !FIN_PARTIE;
    }
    else
    {
        allegro_message("Probleme de chargement des parametres. Verifiez que le fichier \"settings\\parametres.set existe.");
        //fclose(fichier);
        return FIN_PARTIE;
    }
    //fclose(fichier);
}*/


booleen load_settings(t_global* donnees)
{
    FILE* fichier = fopen("settings\\parametres.bin", "rb");
    booleen fin_partie = false;

    if(fichier != NULL) // Lit le niveau à jouer et si la musique et les bruitages sont activés
    {
        fread(&(donnees->niveau), sizeof(int), 1, fichier);
        if(donnees->niveau <= 0)
            donnees->niveau = 1;
        fread(&(donnees->musique.play_music), sizeof(booleen), 1, fichier);
        fread(&(donnees->musique.play_sfx), sizeof(booleen), 1, fichier);
        fin_partie = false;
    }
    else
    {
        allegro_message("Probleme de chargement des parametres. Verifiez que le fichier \"settings\\parametres.set existe.");
        fin_partie = true;
    }

    fclose(fichier);

    return fin_partie;
}




void init_font(t_global* donnees) // Charge le polices d'écriture
{
    donnees->police.myfont1 = load_font("fonts\\pixeltype_72.pcx", donnees->police.palette, NULL); /// Charge le fichier font.pcx contenant la police.
    if (!donnees->police.myfont1)
       {
           allegro_message("Chargement de la police echoue !\nVerifiez le fichier ""font\\pixeltype_72.pcx""");
           allegro_message("Le jeu va fermer.");
           exit(EXIT_FAILURE);
       }

    donnees->police.myfont2 = load_font("fonts\\pixeltype_24.pcx", donnees->police.palette, NULL);/// Charge le fichier font.pcx contenant la police.
    if (!donnees->police.myfont2)
       {
           allegro_message("Chargement de la police echoue !\nVerifiez le fichier ""font\\pixeltype_24.pcx""");
           allegro_message("Le jeu va fermer.");
           exit(EXIT_FAILURE);
       }

    donnees->police.myfont3 = load_font("fonts\\pixeltype_12.pcx", donnees->police.palette, NULL);/// Charge le fichier font.pcx contenant la police.
    if (!donnees->police.myfont3)
       {
           allegro_message("Chargement de la police echoue !\nVerifiez le fichier ""font\\pixeltype_12.pcx""");
           allegro_message("Le jeu va fermer.");
           exit(EXIT_FAILURE);
       }
}



void init_musique(t_global* donnees) // Charge les bruitages et la musique
{
    (donnees->musique).collision = load_sample("sounds\\collision.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.collision)
    {
        allegro_message("Chargement du SFX echoue !\nVerifiez le fichier \"sounds\\collision.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    (donnees->musique).casse = load_sample("sounds\\casse.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.casse)
    {
        allegro_message("Chargement du SFX echoue !\nVerifiez le fichier \"sounds\\casse.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    (donnees->musique).balle_perdue = load_sample("sounds\\balle_perdue.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.balle_perdue)
    {
        allegro_message("Chargement du SFX echoue !\nVerifiez le fichier \"sounds\\balle_perdue.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    (donnees->musique).vie_up = load_sample("sounds\\vie_up.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.vie_up)
    {
        allegro_message("Chargement du SFX echoue !\nVerifiez le fichier \"sounds\\vie_up.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    (donnees->musique).bonus_taken = load_sample("sounds\\bonus.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.bonus_taken)
    {
        allegro_message("Chargement du SFX echoue !\nVerifiez le fichier \"sounds\\bonus.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    (donnees->musique).music = load_sample("sounds\\techno.wav"); ///Format WAV NECESSAIRE
    if(!donnees->musique.music)
    {
        allegro_message("Chargement de la police echoue !\nVerifiez le fichier \"sounds\\techno.wav\"");
        allegro_message("Le jeu va fermer.");
        exit(EXIT_FAILURE);
    }

    // La musique et les bruitages sont activés par défaut, au cas où le chargement des paramètres échouerait
    (donnees->musique).play_music = true;
    (donnees->musique).play_sfx = true;
}







void reinitialiser_settings(t_global* donnees)
{
    FILE* fichier = NULL;
    char chemin[15], niveau[4];

    itoa(donnees->niveau, niveau, 10); // Convertit le niveau de int à char
    sprintf(chemin, "niveaux\\%s.lvl",niveau);
    fichier = fopen(chemin, "r");
    if(fichier == NULL) // Si le niveau enregistré en fin de partie n'exite pas, on le remet à 1 pour ne pas être bloqué en relançant le jeu.
        donnees->niveau = 1;

    fclose(fichier);
}



/*void save_settings(t_global* donnees)
{
    FILE* fichier = fopen("settings\\parametres.set", "w");

    if(fichier != NULL)
    {
        fprintf(fichier, "%d\n", donnees->niveau);
        fprintf(fichier, "%d\n", donnees->musique.play_music);
        fprintf(fichier, "%d", donnees->musique.play_sfx);
    }
    else
        allegro_message("Echec de la sauvegarde des parametres et de la progression. Verifiez que le fichier \"settings\\parametres.set existe.");

    fclose(fichier);
}*/


void save_settings(t_global* donnees)
{
    FILE* fichier = fopen("settings\\parametres.bin", "wb");

    if(fichier != NULL)
    {
        // Les paramètres sont sauvegardés dans un fichier binaire pour que l'on ne puisse pas les modifier en dehors du jeu (changer le niveau par exemple... :p)
        fwrite(&(donnees->niveau), sizeof(int), 1, fichier);
        fwrite(&(donnees->musique.play_music), sizeof(booleen), 1, fichier);
        fwrite(&(donnees->musique.play_sfx), sizeof(booleen), 1, fichier);
    }
    else
        allegro_message("Echec de la sauvegarde des parametres et de la progression. Verifiez que le fichier \"settings\\parametres.set existe.");

    fclose(fichier);
}





void free_memoire(t_global* donnees) // Libère toutes la mémoire alloué dynamiquement, avant la fermeture du programme (même si elle est quand automatiquement liérée --> plus propre)
{
    destroy_bitmap(donnees->buffer);

    destroy_font(donnees->police.myfont1);
    destroy_font(donnees->police.myfont2);
    destroy_font(donnees->police.myfont3);

    destroy_sample(donnees->musique.balle_perdue);
    destroy_sample(donnees->musique.bonus_taken);
    destroy_sample(donnees->musique.casse);
    destroy_sample(donnees->musique.collision);
    destroy_sample(donnees->musique.vie_up);
    destroy_sample(donnees->musique.music);

    free(donnees->briques);
    free(donnees);
}

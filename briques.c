#include "briques.h"


booleen init_niveau(t_global* donnees)
{
    int i, temp;
    t_brique** brique = NULL;
    FILE* fichier = NULL;
    char chemin[15], niveau[4];

    itoa(donnees->niveau, niveau, 10);
    sprintf(chemin, "niveaux\\%s.lvl",niveau);
    fichier = fopen(chemin, "r"); // Ouverture du fichier correspondant au niveau à jouer


    printf("\n\nChargement du niveau :\n\n");

    donnees->nb_briques = 0;
    if(fichier != NULL)
    {
        if(!feof(fichier))
        {
            while(!feof(fichier)) // On récupère le nombre de brique à créer pour allouer le tableau à la bonne taile
            {
                fscanf(fichier, "%d", &temp);
                fscanf(fichier, "%d", &temp);
                fscanf(fichier, "%d", &temp);
                donnees->nb_briques++;
            }
        }

        rewind(fichier); // On se repositionne au début du fichier

        donnees->briques = (t_brique**)malloc((donnees->nb_briques)*sizeof(t_brique*)); // Allocation du tableau de pointeurs sur briques
        brique = donnees->briques;
        for(i=0; i<(donnees->nb_briques); i++)
        {
            brique[i] = (t_brique*)malloc(sizeof(t_brique));

            fscanf(fichier, "%d", &(brique[i]->type)); // Lecture du type de brique

            switch(brique[i]->type) // Assgnation de la vie et de la couleur en fonction du type
            {
                case TYPE_BONUS   : brique[i]->couleur = COULEUR_BONUS;
                                    brique[i]->vie = VIE_BONUS;
                                    break;
                case TYPE_FORTE   : brique[i]->couleur = COULEUR_FORTE;
                                    brique[i]->vie = VIE_FORTE;
                                    break;
                case TYPE_MOYENNE : brique[i]->couleur = COULEUR_MOYENNE;
                                    brique[i]->vie = VIE_MOYENNNE;
                                    break;
                case TYPE_FAIBLE  :
                default           : brique[i]->couleur = COULEUR_FAIBLE;
                                    brique[i]->vie = VIE_FAIBLE;
                                    break;
            }
            fscanf(fichier, "%d", &(brique[i]->x)); // Lecture de la zone en x
            brique[i]->x = ZONE_BRIQUE_W/(NB_BRIQUE_W)*brique[i]->x; // Calcul de la position en x à l'écran

            fscanf(fichier, "%d", &(brique[i]->y)); // Lecture de la zone en x
            brique[i]->y += 3; // Pour ne pas afficher les briques au même endroit que le hub (score, niveau...).
            brique[i]->y = ZONE_BRIQUE_H/(NB_BRIQUE_H)*(brique[i]->y);// Calcul de la position en x à l'écran

            if(!(brique[i]->x < ZONE_BRIQUE_W) && !(brique[i]->y < ZONE_BRIQUE_H)) // Pour éviter d'avoir des briques qui dépassent de la zone.
            {
                free(brique[i]);
                brique[i] = NULL;
            }

            printf("Type : %d\tx : %d\ty : %d\n", brique[i]->type, brique[i]->x, brique[i]->y);
        }

        fclose(fichier);
        return !FIN_PARTIE;
    }
    else // Le fichier n'a pas pu être ouvert, c'est qu'il n'xiste pas
    {
        if(donnees->niveau == 1)
            allegro_message("Erreur de chargement du niveau. Verifiez que le fichier \"niveaux\\1.lvl\" existe.");
        else // Si le niveau à jouer n'est pas le niveau 1, c'est que tous les niveaux ont été joués
        {
            clear_to_color(screen, makecol(0,0,0));
            textprintf_ex(screen, donnees->police.myfont2, SCREEN_W - text_length((donnees->police).myfont2, "Maxime Vernusset") - 5, SCREEN_H - text_height((donnees->police).myfont2), -1, -1, "Maxime Vernusset");
            textprintf_ex(screen, donnees->police.myfont1, SCREEN_W/2 - text_length(donnees->police.myfont1, "GAGNE")/2, SCREEN_H/2 - text_height(donnees->police.myfont1)/2, makecol(255,0,0), -1, "GAGNE");
            stop_sample((donnees->musique).music); // Arrête la musique.
            rest(750); // Attend 750 ms pour laisser le temps d'arrêter la musique.
            allegro_message("Bravo, vous avez fini tous les niveaux disponnibles !");
        }
        return FIN_PARTIE; // Indique que le jeu est fini
    }
}




void actionner_briques(t_global* donnees)
{
    t_brique** brique = donnees->briques;
    int couleurs_brique_bonus[VIE_BONUS];
    int i;

    for(i=0; i<VIE_BONUS; i++)
        couleurs_brique_bonus[i] = makecol(255-50*i,255-50*i,255-50*i);

     for(i=0; i<donnees->nb_briques; i++)
     {
        if(brique[i] != NULL)
        {
            // On applique aux briques la couleur correspondant à leur niveau de vie
            if(brique[i]->vie == VIE_FORTE && brique[i]->type != TYPE_BONUS)
                brique[i]->couleur = COULEUR_FORTE;
            if(brique[i]->vie == VIE_MOYENNNE && brique[i]->type != TYPE_BONUS)
                brique[i]->couleur = COULEUR_MOYENNE;
            if(brique[i]->vie == VIE_FAIBLE && brique[i]->type != TYPE_BONUS)
                brique[i]->couleur = COULEUR_FAIBLE;

            if(brique[i]->type == TYPE_BONUS) // Les briques bonus se grisent au fur et à mesure qu'elles perdent de la vie
                brique[i]->couleur = couleurs_brique_bonus[VIE_BONUS - brique[i]->vie];

            if(brique[i]->vie <= 0) // On incrément le score du nombre original de points de vie de la brique
            {
                if(brique[i]->type == TYPE_BONUS) // On crée un bonus si la brique détruite est une brique bonus
                {
                    printf("\nBrique Bonus detruite : +%d points", VIE_BONUS);
                    donnees->score += VIE_BONUS;
                    creer_bonus(donnees, brique[i]);
                }
                if(brique[i]->type == TYPE_FORTE)
                {
                    printf("\nBrique forte detruite : +%d points", VIE_FORTE);
                    donnees->score += VIE_FORTE;
                }

                if(brique[i]->type == TYPE_MOYENNE)
                {
                    printf("\nBrique moyenne detruite : +%d points", VIE_MOYENNNE);
                    donnees->score += VIE_MOYENNNE;
                }
                if(brique[i]->type == TYPE_FAIBLE)
                {
                    printf("\nBrique faible detruite : +%d points", VIE_FAIBLE);
                    donnees->score += VIE_FAIBLE;
                }

                if((donnees->musique).play_sfx == true)
                        play_sample((donnees->musique).casse, 100, 100, 900, 0); ///150 volume baffle gauche - droite | 1000 vitesse | 0 pas de répétition (1 pour boucle infini).

                free(brique[i]); // On libère la brique qui a été détruite
                brique[i] = NULL;
            }
        }


     }
}






booleen reste_briques(t_global* donnees) // Les balles rebondiront tant qu'il reste des briques à afficher
{
    int i;
    booleen reste = false;
    t_brique** brique = donnees->briques;

    for(i=0; i<(donnees->nb_briques); i++)
    {
        if(brique[i] != NULL)
            reste = true;
    }

    return reste;
}




void afficher_briques(t_global* donnees)
{
    int i;
    t_brique** brique = donnees->briques;

    for(i=0; i<(donnees->nb_briques); i++)
    {
        if(brique[i] != NULL)
        {
            rectfill(donnees->buffer, brique[i]->x, brique[i]->y, brique[i]->x+ZONE_BRIQUE_W/(NB_BRIQUE_W), brique[i]->y+ZONE_BRIQUE_H/(NB_BRIQUE_H), brique[i]->couleur);
            rect(donnees->buffer, brique[i]->x, brique[i]->y, brique[i]->x+ZONE_BRIQUE_W/(NB_BRIQUE_W), brique[i]->y+ZONE_BRIQUE_H/(NB_BRIQUE_H), makecol(128,128,128));
            if(brique[i]->type == TYPE_BONUS)
                textprintf_ex(donnees->buffer, (donnees->police.myfont2), (2*brique[i]->x+BRIQUE_W)/2-text_length((donnees->police.myfont2), "B")/2, (2*brique[i]->y+BRIQUE_H)/2-text_height(donnees->police.myfont2)/2.9, makecol(0,0,0), -1, "B");
        }
    }
}




void raffraichir_niveau(t_global* donnees, int* nb_tour)
{
// Tous les 'FREQ_RAFRAICHISSEMENT' tours de boucle de jeu, on transfère les briques restantes du niveau dans un autre tableau réalloué à la bonne taille, et on libère l'ancien, pour libérer un peu de mémoire (pas beaucoup)
    int i = 0, j = 0, new_nb = 0;
    t_brique** brique = donnees->briques;
    t_brique** new_tab;

    printf("\nTour de boucle No %d\n", (*nb_tour)++);
    if(*nb_tour%FREQ_RAFRAICHISSEMENT == 0)     {
        for(i=0; i<(donnees->nb_briques); i++)
        {
            if(brique[i] != NULL)
                new_nb++;
        }
        new_tab = (t_brique**)malloc(new_nb*sizeof(t_brique*));
        for(i=0; i<(donnees->nb_briques); i++)
        {
            if(brique[i] != NULL)
            {
                new_tab[j] = brique[i];
                j++;
            }
        }
        donnees->nb_briques = new_nb;
        donnees->briques = new_tab;
    }
}




void liberer_niveau(t_global* donnees)
{
    int i;
    t_brique** brique = donnees->briques;

    for(i=0; i<(donnees->nb_briques); i++) // On supprime toutes les briques de la mémoire, et le tableau les contenant
    {
        free(brique[i]);
        brique[i] = NULL;
    }
    free(donnees->briques);

    for(i=0; i<BONUS_MAX; i++) // On supprime tous les bonus
    {
        free(donnees->bonus[i]);
        donnees->bonus[i] = NULL;
    }
    for(i=0; i<BALLE_MAX; i++) // On supprime toutes les balle bonus
    {
        free(donnees->balle_bonus[i]);
        donnees->balle_bonus[i] = NULL;
    }
}

#include "jeu.h"



void afficher_hub(t_global* donnees)
{
    rectfill(donnees->buffer, 0, 0, SCREEN_W, 2.5*text_height(donnees->police.myfont2), makecol(0,0,0));
    rect(donnees->buffer, 0, 0, SCREEN_W-1, 2.5*text_height(donnees->police.myfont2), makecol(128,128,128));
    textprintf_ex(donnees->buffer, donnees->police.myfont2, 5, 5, -1, -1, "Score : %d", donnees->score);
    textprintf_ex(donnees->buffer, donnees->police.myfont2, 5, 5 + text_height(donnees->police.myfont2), -1, -1, "Nb rebonds : %d", (donnees->balle).nb_rebonds);
    textprintf_ex(donnees->buffer, donnees->police.myfont2, SCREEN_W/2 - text_length((donnees->police).myfont2, "Niveau  ")/2, 5, makecol(255,255,255),-1, "Niveau %d", donnees->niveau);
    textprintf_ex(donnees->buffer, donnees->police.myfont2, SCREEN_W/2 - text_length((donnees->police).myfont2, donnees->evenement)/2, 5 +  text_height(donnees->police.myfont2), makecol(255,128,0), -1, donnees->evenement, donnees->niveau);
    textprintf_ex(donnees->buffer, donnees->police.myfont2, SCREEN_W - text_length((donnees->police).myfont2, "Balles restantes :   ") - 5, 5, -1, -1, "Balles restantes : %d", (donnees->balle).vie);
    textprintf_ex(donnees->buffer, donnees->police.myfont2, SCREEN_W - text_length((donnees->police).myfont2, "Puissance balle :   ") - 5, 5 + text_height(donnees->police.myfont2), -1, -1, "Puissance balle : %d", (donnees->balle).degats);
    textprintf_ex(donnees->buffer, donnees->police.myfont3, SCREEN_W - text_length((donnees->police).myfont3, "Maxime Vernusset") - 2, SCREEN_H - text_height((donnees->police).myfont3), -1, -1, "Maxime Vernusset");
}




void affichage(t_global* donnees, int* p_duree_affichage_evenement)
{
    clear_bitmap(donnees->buffer);

    afficher_briques(donnees);
    afficher_bonus(donnees);
    afficher_balles_bonus(donnees);
    afficher_balle(donnees);
    afficher_barre(donnees);
    afficher_hub(donnees);

    (*p_duree_affichage_evenement)++;
    if(*p_duree_affichage_evenement == DUREE_AFFICHAGE_EVENEMENT || *p_duree_affichage_evenement == 0)
    {
        strcpy(donnees->evenement, "");
        *p_duree_affichage_evenement = 0;
    }

    blit(donnees->buffer, screen, 0,0, 0,0, SCREEN_W, SCREEN_H); // Après avoir tout affiché sur le buffer, on l'affiche à l'écran (--> pas de clignotements)
}



void deplacement(t_global* donnees)
{
    deplacer_barre(donnees);
    deplacer_balle(donnees);
    deplacer_balles_bonus(donnees);
    deplacer_bonus(donnees);
}


void collisions(t_global* donnees, int* p_duree_affichage_evenement)
{
    collisions_balle(donnees);
    collisions_balles_bonus(donnees);
    collisions_bonus(donnees, p_duree_affichage_evenement);
}



void musique(t_global* donnees)
{
    if(key[KEY_X]) // Activation ou non de la musique
    {
        while(key[KEY_X]) {}
        (donnees->musique).play_music = !(donnees->musique).play_music;

        if((donnees->musique).play_music == true)
            play_sample((donnees->musique).music, 140, 140, 1000, 1); ///140 volume baffle gauche - droite | 1000 vitesse | 0 pas de répétition (1 pour boucle infini).
        else if((donnees->musique).play_music == false)
            stop_sample((donnees->musique).music); /// Arrête la musique.
    }
    else if(key[KEY_Z]) // Activation ou non des bruitages
    {
        while(key[KEY_Z]) {}
        (donnees->musique).play_sfx = !(donnees->musique).play_sfx;
    }

    if((donnees->musique).play_music == true)
        textprintf_ex(screen, donnees->police.myfont2, 5, SCREEN_H - text_height(donnees->police.myfont2) -5, -1, 0, "Musique : ON  (X pour desactiver)");
    else if((donnees->musique).play_music == false)
        textprintf_ex(screen, donnees->police.myfont2, 5, SCREEN_H - text_height(donnees->police.myfont2) -5, -1, 0, "Musique : OFF  (X pour activer)     ");

    if((donnees->musique).play_sfx == true)
        textprintf_ex(screen, donnees->police.myfont2, 5, SCREEN_H - 2*text_height(donnees->police.myfont2) -5, -1, 0, "SFX : ON  (W pour desactiver)");
    else if((donnees->musique).play_sfx == false)
        textprintf_ex(screen, donnees->police.myfont2, 5, SCREEN_H - 2*text_height(donnees->police.myfont2) -5, -1, 0, "SFX : OFF  (W pour activer)     ");
}




void pause(t_global* donnees)
{
    textprintf_ex(screen, donnees->police.myfont1, SCREEN_W/2 - text_length(donnees->police.myfont1, "PAUSE")/2, SCREEN_H/2 - text_height(donnees->police.myfont1)/2, makecol(255,0,0), -1, "PAUSE");
    while(key[KEY_SPACE]){musique(donnees);}

    while(!(key[KEY_SPACE] || key[KEY_ESC]))
    {
        textprintf_ex(donnees->buffer, donnees->police.myfont1, SCREEN_W/2 - text_length(donnees->police.myfont1, " PAUSE ")/2, SCREEN_H/2 - text_height(donnees->police.myfont1)/2, makecol(255,0,0), -1, " PAUSE ");
        musique(donnees);
    }
    while(key[KEY_SPACE]){}
}



booleen niveau_suivant(t_global* donnees)
{
    init_barre(donnees);
    init_balle(donnees);
    donnees->score = 0;

    return init_niveau(donnees);
}




void vie_up(t_global* donnees, int* p_centaine, int* p_duree_affichage_evenement)
{
    // Tous les 100 points, le joueur gagne une balle
    if(donnees->score >= (*p_centaine)*SEUIL_VIE_UP)
    {
        (donnees->balle).vie++;
        (*p_centaine)++;
        *p_duree_affichage_evenement = 0;
        strcpy(donnees->evenement, "+1 balle");
        printf("\n+1 balle\n");
        if((donnees->musique).play_sfx == true)
            play_sample((donnees->musique).vie_up, 140, 140, 1000, 0);
    }
}






void jouer(t_global* donnees)
{
    int centaine = 1, nb_tour = 0, duree_affichage_evenement = 0;
    booleen fin_partie = false;
    booleen balles_restantes = true;
    booleen briques_restantes = true;

    fin_partie = load_settings(donnees);

    while(!(key[KEY_ESC] || fin_partie))
    {
        if((donnees->musique).play_music == true) // On joue la musique si le joueur ne l'a pas bloquée
           {
               stop_sample((donnees->musique).music); // Arrête la musique, pour qu'au niveau suivant elle recommence (sinon on en entend 2).
               play_sample((donnees->musique).music, 140, 140, 1000, 1); ///140 volume baffle gauche - droite | 1000 vitesse | 0 pas de répétition (1 pour boucle infini).
           }

        balles_restantes = true;
        fin_partie = niveau_suivant(donnees);

        if(fin_partie == false)
        {
            affichage(donnees, &duree_affichage_evenement);

            if(balles_restantes == true)
            {
                do
                {
                    textprintf_ex(screen, donnees->police.myfont1, SCREEN_W/2 - text_length(donnees->police.myfont1, "NIVEAU  ")/2, SCREEN_H/2 - text_height(donnees->police.myfont1)/2, makecol(255,0,0), -1, "NIVEAU %d", donnees->niveau);
                    textprintf_ex(screen, donnees->police.myfont2, SCREEN_W/2 - text_length(donnees->police.myfont2, "Appuyez sur ESPACE")/2, SCREEN_H/2 + text_height(donnees->police.myfont1)/2, -1, -1, "Appuyez sur ESPACE");

                    musique(donnees);
                    briques_restantes = reste_briques(donnees);

                    if(key[KEY_SPACE]) // Pour lancer la balle
                    {
                        while(key[KEY_SPACE]) {}

                        while(!key[KEY_ESC] && briques_restantes == true && balles_restantes == true) // Boucle de jeu
                        {
                            affichage(donnees, &duree_affichage_evenement);
                            briques_restantes = reste_briques(donnees);
                            deplacement(donnees);
                            collisions(donnees, &duree_affichage_evenement);
                            balles_restantes = reste_balles(donnees);
                            actionner_briques(donnees);
                            vie_up(donnees, &centaine, &duree_affichage_evenement);
                            raffraichir_niveau(donnees, &nb_tour);

                            if(key[KEY_SPACE])
                                pause(donnees);

                            rest(REST);
                        }
                    }
                }while(!key[KEY_ESC] && briques_restantes == true && balles_restantes == true);

                liberer_niveau(donnees);
                duree_affichage_evenement = 0;
                centaine = 1;
                nb_tour = 0;
                donnees->score = 0;

                if(key[KEY_ESC])
                    fin_partie = true;
            }
        }

        if(balles_restantes == true && !key[KEY_ESC])
            donnees->niveau++;
        else if(balles_restantes == false)
        {
            textprintf_ex(screen, donnees->police.myfont1, SCREEN_W/2 - text_length(donnees->police.myfont1, "PERDU")/2, SCREEN_H/2 - text_height(donnees->police.myfont1)/2, makecol(255,0,0), -1, "PERDU");
            rest(750);
        }

        rest(300);
    }

    reinitialiser_settings(donnees);
    save_settings(donnees);
}

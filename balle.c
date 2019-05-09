#include "balle.h"

void init_balle(t_global* donnees)
{
    int vx[] = {-4, -3, -2, -1, 1, 2, 3, 4};

    (donnees->balle).x = SCREEN_W/2;
    (donnees->balle).y = (donnees->barre).y - BALLE_R -1;
    (donnees->balle).vx = COEFF_VITESSE*vx[rand()%8];
    (donnees->balle).vy = COEFF_VITESSE*(-5);
    (donnees->balle).vie = BALLE_VIE;
    (donnees->balle).degats = BALLE_DEGATS;
    (donnees->balle).couleur = BALLE_COULEUR;
    (donnees->balle).nb_rebonds = 0;
    (donnees->balle).invincibilite = 0;
}


void reinit_balle(t_global* donnees)
{
    int vx[] = {-4, -3, -2, -1, 1, 2, 3, 4};

    (donnees->balle).x = SCREEN_W/2;
    (donnees->balle).y = (donnees->barre).y - BALLE_R -1;
    (donnees->balle).vx = COEFF_VITESSE*vx[rand()%8];
    (donnees->balle).vy = COEFF_VITESSE*(-5);
    if((donnees->balle).degats > 1)
        (donnees->balle).degats--;
    (donnees->balle).couleur = BALLE_COULEUR;
    (donnees->balle).nb_rebonds = 0;
    (donnees->balle).invincibilite = 0;
}


void afficher_balle(t_global* donnees)
{
    circlefill(donnees->buffer, (donnees->balle).x, (donnees->balle).y, BALLE_R, (donnees->balle).couleur);
    circle(donnees->buffer, (donnees->balle).x, (donnees->balle).y, BALLE_R, BALLE_CONTOUR);
}



void deplacer_balle(t_global* donnees)
{
    (donnees->balle).x += (donnees->balle).vx;
    (donnees->balle).y += (donnees->balle).vy;
}



void collisions_balle(t_global* donnees)
{
    t_brique** brique = donnees->briques;
    t_barre barre = donnees->barre;

    booleen inverser_vx = false;
    booleen inverser_vy = false;
    booleen sortir_boucle = false;
    int i;


    /// Collisions avec la barre.
    if((donnees->balle).y + BALLE_R >= barre.y && (donnees->balle).x + BALLE_R >= barre.x - barre.bonus_taille && (donnees->balle).x - BALLE_R <= barre.x + BARRE_W+ barre.bonus_taille)
    {
        if((donnees->musique).play_sfx == true)
            play_sample((donnees->musique).collision, 50, 50, 2000, 0);
        (donnees->balle).y = barre.y - BALLE_R;
        (donnees->balle).vy *= -1;
        (donnees->balle).nb_rebonds++;

        /// Pour "friter" la balle
        if(key[KEY_LEFT] && (donnees->barre).x - barre.bonus_taille > 0+1 && fabs((donnees->balle).vx+FRITTAGE_VITESSE) < 2*BALLE_R)
        {
            (donnees->balle).vx += FRITTAGE_VITESSE;
            printf("\nBalle frittee");
        }
        if(key[KEY_RIGHT] && (donnees->barre).x + BARRE_W + barre.bonus_taille < SCREEN_W-1 && fabs((donnees->balle).vx-FRITTAGE_VITESSE) < 2*BALLE_R)
        {
            (donnees->balle).vx -= FRITTAGE_VITESSE;
            printf("\nBalle frittee");
        }
    }


    /// Collisions avec les murs
    if((donnees->balle).x - BALLE_R <= 0) // Gauche
    {
        (donnees->balle).x = 0 + BALLE_R,
                inverser_vx = true;
    }
    if((donnees->balle).x + BALLE_R >= SCREEN_W) // Droite
    {
        (donnees->balle).x = SCREEN_W - 2*BALLE_R;
                inverser_vx = true;
    }

    if((donnees->balle).y - BALLE_R <= 2.5*text_height(donnees->police.myfont2)) // Haut
    {
         (donnees->balle).y = 2.5*text_height(donnees->police.myfont2) + BALLE_R;
                inverser_vy = true;
    }
    if((donnees->balle).y + BALLE_R >= SCREEN_H) // Bas
    {
        if(key[KEY_Q] || (donnees->balle).invincibilite > 0) // La balle rebondira sur le mur du dessous
        {
            (donnees->balle).y = SCREEN_H - BALLE_R;
                inverser_vy = true;
        }
        else
        {
            int i;

            printf("\nBalle perdue\n");
            strcpy(donnees->evenement, "");
            textprintf_ex(screen, donnees->police.myfont2, SCREEN_W/2 - text_length((donnees->police).myfont2, "       Balle perdue       ")/2, 5 +  text_height(donnees->police.myfont2), makecol(255,128,0), 0, "       Balle perdue       ");

            donnees->score -= MALUS_BALLE_PERDUE;
            if(donnees->score < 0)
                donnees->score = 0;
            (donnees->balle).vie--;
            (donnees->balle).y = SCREEN_H - BALLE_R;
            if((donnees->musique).play_sfx == true)
                play_sample((donnees->musique).balle_perdue, 140, 140, 1100, 0);

            reinit_balle(donnees);
            init_barre(donnees);
            for(i=0; i<BONUS_MAX; i++) // On supprime tous les bonus créés
            {
                free(donnees->bonus[i]);
                donnees->bonus[i] = NULL;
            }
            for(i=0; i<BALLE_MAX; i++) // On enlève touts les balles bonus
            {
                free(donnees->balle_bonus[i]);
                donnees->balle_bonus[i] = NULL;
            }

            rest(750);
        }
    }


    /// Collisions avec les briques
    for(i=0; i<(donnees->nb_briques); i++)
    {
        if(brique[i] != NULL)
        {
            // Dessous de la brique
            if((donnees->balle).y-BALLE_R <= (brique[i])->y+BRIQUE_H  &&  (donnees->balle).y+BALLE_R >= (brique[i])->y+BRIQUE_H  &&  (donnees->balle).x >= (brique[i])->x  &&  (donnees->balle).x <= (brique[i])->x+BRIQUE_W)
            {
                (donnees->balle).y = brique[i]->y + BRIQUE_H + BALLE_R;
                inverser_vy = true;
                donnees->score++;
                brique[i]->vie -= (donnees->balle).degats;
                printf("\nBrique touchee : +1 point");
                if((donnees->musique).play_sfx == true && brique[i]->vie > 0)
                    play_sample((donnees->musique).collision, 100, 100, 900, 0);
                sortir_boucle = true;
            }

            // Dessus de la brique
            else if((donnees->balle).y+BALLE_R >= (brique[i])->y  &&  (donnees->balle).y-BALLE_R <= (brique[i])->y  &&  (donnees->balle).x >= (brique[i])->x  &&  (donnees->balle).x <= (brique[i])->x+BRIQUE_W)
            {
                (donnees->balle).y = brique[i]->y - BALLE_R;
                inverser_vy = true;
                donnees->score++;
                brique[i]->vie -= (donnees->balle).degats;
                printf("\nBrique touchee : +1 point");
                if((donnees->musique).play_sfx == true && brique[i]->vie > 0)
                    play_sample((donnees->musique).collision, 100, 100, 900, 0);
                sortir_boucle = true;
            }

            // Gauche de la brique
            else if((donnees->balle).y >= (brique[i])->y  &&  (donnees->balle).y <= (brique[i])->y+BRIQUE_H  &&  (donnees->balle).x+BALLE_R >= (brique[i])->x  &&  (donnees->balle).x-BALLE_R < (brique[i])->x)
            {
                (donnees->balle).x = brique[i]->x - BALLE_R;
                inverser_vx = true;
                donnees->score++;
                brique[i]->vie -= (donnees->balle).degats;
                printf("\nBrique touchee : +1 point");
                if((donnees->musique).play_sfx == true && brique[i]->vie > 0)
                    play_sample((donnees->musique).collision, 100, 100, 900, 0);
                sortir_boucle = true;
            }

            // Droite de la brique
            else if((donnees->balle).y >= (brique[i])->y  &&  (donnees->balle).y <= (brique[i])->y+BRIQUE_H  &&  (donnees->balle).x-BALLE_R <= (brique[i])->x+BRIQUE_W  &&  (donnees->balle).x+BALLE_R > (brique[i])->x+BRIQUE_W)
            {
                (donnees->balle).x = brique[i]->x + BRIQUE_W + BALLE_R;
                inverser_vx = true;
                donnees->score++;
                brique[i]->vie -= (donnees->balle).degats;
                printf("\nBrique touchee : +1 point");
                if((donnees->musique).play_sfx == true && brique[i]->vie > 0)
                    play_sample((donnees->musique).collision, 100, 100, 900, 0);
                sortir_boucle = true;
            }

            if(inverser_vy == true)
            {
                (donnees->balle).vy *= -1;
                inverser_vy = false;
            }
            if(inverser_vx == true)
            {
                (donnees->balle).vx *= -1;
                inverser_vx = false;
            }
            if(sortir_boucle == true)
                break;
        }
    }
}





booleen reste_balles(t_global* donnees)
{
    if(donnees->balle.vie >= 0)
        return true;
    else
        return false;
}

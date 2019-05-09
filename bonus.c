#include "bonus.h"



void creer_bonus(t_global* donnees, t_brique* brique) // On crée un bonus si une brique bonus est détruite
{
    int i;
    t_bonus* temp = (t_bonus*)malloc(sizeof(t_bonus));
    booleen tab_plein = true;
    booleen existe_balle_bonus = false;
    booleen desalouer = true;

    for(i=0; i<BALLE_MAX; i++) // POur savoir si le tableau de balles bonus est plein ou vide
    {
        if(donnees->balle_bonus[i] == NULL)
            tab_plein = false;
        else
            existe_balle_bonus = true;
    }

    temp->x = brique->x + BRIQUE_W/2;
    temp->y = brique->y + BRIQUE_H/2;
    temp->vy = COEFF_VITESSE * (2.5);
    do // Choix aléatoire du type de bonus créé, avec certaines conditions
    {
        temp->type = rand()%NB_BONUS;
    }while((tab_plein == true && temp->type == BONUS_BALLE)  ||  ((donnees->barre).bonus_taille >= LARGEUR_FENETRE/4.5 && temp->type == BONUS_BARRE)  ||  ((donnees->balle).degats >= VIE_BONUS-1 && temp->type == BONUS_DEGAT)  ||  (existe_balle_bonus == false && temp->type == BONUS_INVINCIBILITE));

    for(i=0; i<BONUS_MAX; i++)
    {
        if(donnees->bonus[i] == NULL) // On place le bonus créé dans une case vide du tableau de bonus
        {
            donnees->bonus[i] = temp;
            desalouer = false;
            break;
        }
    }

    if(desalouer == true) // Si le tabbleau de bonus est déjà plein, on supprime le bonus créé
        free(temp);
}




void deplacer_bonus(t_global* donnees)
{
    int i;

    for(i=0; i<BONUS_MAX; i++)
    {
        if(donnees->bonus[i] != NULL)
        {
            (donnees->bonus[i])->y += (donnees->bonus[i])->vy; // Déplacement vertical vers la bas

            if((donnees->bonus[i])->y >= SCREEN_H) // On supprime le bonus s'il sort de l'écran
            {
                free(donnees->bonus[i]);
                donnees->bonus[i] = NULL;
            }
        }
    }
}




void collisions_bonus(t_global* donnees, int* p_duree_affichage_evenement)
{
    int i, j;

    for(i=0; i<BONUS_MAX; i++)
    {
        if(donnees->bonus[i] != NULL) // Si la case du tableau de bonus contient un bonus existant et que le bonus touche la barre, on exécute le bonus
        {
            if((donnees->bonus[i])->y + BONUS_R >= (donnees->barre).y && (donnees->bonus[i])->x + BONUS_R >= (donnees->barre).x - (donnees->barre).bonus_taille && (donnees->bonus[i])->x - BONUS_R <= (donnees->barre).x + BARRE_W + (donnees->barre).bonus_taille)
            {
                (*p_duree_affichage_evenement) = 0;

                if((donnees->musique).play_sfx == true)
                    play_sample((donnees->musique).bonus_taken, 75, 75, 1200, 0);

                switch((donnees->bonus[i])->type)
                {
                    case BONUS_BALLE : creer_balle_bonus(donnees, donnees->bonus[i]);
                                        strcpy(donnees->evenement, "Bonus : balle");
                                        printf("\nBonus balle");
                                    break;
                    case BONUS_BARRE : (donnees->barre).bonus_taille += BONUS_TAILLE;
                                        strcpy(donnees->evenement, "Bonus : barre");
                                        printf("\nBonus barre");
                                    break;
                    case BONUS_DEGAT : (donnees->balle).degats++;
                                        strcpy(donnees->evenement, "Bonus : puissance balle");
                                        printf("\nBonus : puissance balle");
                                    break;
                    case BONUS_VIE :    (donnees->balle).vie++;
                                        strcpy(donnees->evenement, "Bonus : vie");
                                        printf("\nBonus vie");
                                        if((donnees->musique).play_sfx == true)
                                            play_sample((donnees->musique).vie_up, 100, 100, 1000, 0);
                                    break;
                    case BONUS_POINT : donnees->score += NB_POINTS_BONUS;
                                        strcpy(donnees->evenement, "Bonus : points");
                                        printf("\nBonus points");
                                    break;
                    case BONUS_INVINCIBILITE : printf("\nBonus invincibilite");
                                               strcpy(donnees->evenement, "Bonus : rebond balle bonus");
                                               for(j=0;j<BALLE_MAX; j++)
                                               {
                                                 if(donnees->balle_bonus[j] != NULL)
                                                    (donnees->balle_bonus[j])->invincibilite++;
                                               }
                                    break;
                }
                free(donnees->bonus[i]); // ON libère le bonus une fois exécuté, pour que la case du tableau puisse contenir le suivant
                donnees->bonus[i] = NULL;
            }
        }
    }
}




void afficher_bonus(t_global* donnees)
{
    int i, r;
    int couleur;

    for(i=0; i<BONUS_MAX; i++) // Parcours du tableau de bonus
    {
        if(donnees->bonus[i] != NULL) // Si le bonus existe, on l'affiche
        {
            for(r=BONUS_R; r>0; r--)
            {
                switch((donnees->bonus[i])->type) // Chque bonus a une couleur différente
                {
                    case BONUS_BALLE : couleur = makecol(18*r, 255-18*r, 255-18*r);
                                    break;
                    case BONUS_BARRE : couleur = makecol(255-18*r, 18*r, 255-18*r);
                                    break;
                    case BONUS_DEGAT : couleur = makecol(255-18*r, 255-18*r, 18*r);
                                    break;
                    case BONUS_VIE : couleur = makecol(18*r, 255-18*r, 18*r);
                                    break;
                    case BONUS_POINT : couleur = makecol(18*r, 18*r, 255-18*r);
                                    break;
                    case BONUS_INVINCIBILITE : couleur = makecol(255-18*r, 18*r, 18*r);
                                    break;

                }
                circle(donnees->buffer, (donnees->bonus[i])->x, (donnees->bonus[i])->y, r, couleur); // Dessin du bonus
            }
        }
     }
}




void creer_balle_bonus(t_global* donnees, t_bonus* bonus)
{
    int i;
    int vx[] = {-4, -3, -2, -1, 1, 2, 3, 4};
    booleen desalouer = true;

    t_balle* temp = (t_balle*)malloc(sizeof(t_balle));

    temp->x = bonus->x;
    temp->y = (donnees->barre).y - BALLE_R -1;
    temp->vx = COEFF_VITESSE * vx[rand()%8];
    temp->vy = COEFF_VITESSE * (-4);
    temp->vie = 1;
    temp->degats = BALLE_DEGATS;
    temp->couleur = makecol(128,255,0);
    temp->nb_rebonds = 0;
    temp->invincibilite = 0;

    for(i=0; i<BALLE_MAX; i++)
    {
        if(donnees->balle_bonus[i] == NULL) // On place la balle bonus créée dans une case vide du tableau de balles bonus
        {
            donnees->balle_bonus[i] = temp;
            desalouer = false;
            break;
        }
    }

    if(desalouer == true) // Si le tableau est déjà plein, on supprime le bonus créé
        free(temp);
}




void deplacer_balles_bonus(t_global* donnees)
{
    int i;

    for(i=0; i<BALLE_MAX; i++)
    {
        if(donnees->balle_bonus[i] != NULL)
        {
            (donnees->balle_bonus[i])->x += (donnees->balle_bonus[i])->vx;
            (donnees->balle_bonus[i])->y += (donnees->balle_bonus[i])->vy;
        }
    }
}





void collisions_balles_bonus(t_global* donnees)
{
    int i, j;
    booleen desallouer = false;
    booleen inverser_vx = false;
    booleen inverser_vy = false;
    booleen sortir_boucle = false;

    for(i=0; i<BALLE_MAX; i++)
    {
        if(donnees->balle_bonus[i] != NULL)
        {
            t_brique** brique = donnees->briques;
            t_barre barre = donnees->barre;


            /// Collisions avec la barre.
            if((donnees->balle_bonus[i])->y + BALLE_R >= barre.y && (donnees->balle_bonus[i])->x + BALLE_R >= barre.x - barre.bonus_taille && (donnees->balle_bonus[i])->x - BALLE_R <= barre.x + BARRE_W+ barre.bonus_taille)
            {
                if((donnees->musique).play_sfx == true)
                    play_sample((donnees->musique).collision, 50, 50, 2000, 0);
                (donnees->balle_bonus[i])->y = barre.y - BALLE_R;
                (donnees->balle_bonus[i])->vy *= -1;
                (donnees->balle_bonus[i])->nb_rebonds++;

                /// Pour "friter" la balle
                if(key[KEY_LEFT] && (donnees->barre).x - barre.bonus_taille > 0+1 && fabs((donnees->balle_bonus[i])->vx+FRITTAGE_VITESSE) < 2*BALLE_R)
                {
                    (donnees->balle_bonus[i])->vx += FRITTAGE_VITESSE;
                    printf("\nBalle bonus frittee");
                }
                if(key[KEY_RIGHT] && (donnees->barre).x + BARRE_W + barre.bonus_taille < SCREEN_W-1 && fabs((donnees->balle_bonus[i])->vx-FRITTAGE_VITESSE) < 2*BALLE_R)
                {
                    (donnees->balle_bonus[i])->vx -= FRITTAGE_VITESSE;
                    printf("\nBalle bonus frittee");
                }
            }


            /// Collisions avec les murs
            if((donnees->balle_bonus[i])->x - BALLE_R <= 0) // Gauche
            {
                (donnees->balle_bonus[i])->x = 0 + BALLE_R,
                (donnees->balle_bonus[i])->vx *= -1;
            }
            if((donnees->balle_bonus[i])->x + BALLE_R >= SCREEN_W) // Droite
            {
                (donnees->balle_bonus[i])->x = SCREEN_W - 2*BALLE_R;
                (donnees->balle_bonus[i])->vx *= -1;
            }

            if((donnees->balle_bonus[i])->y - BALLE_R <= 2.5*text_height(donnees->police.myfont2)) // Haut
            {
                (donnees->balle_bonus[i])->y = 2.5*text_height(donnees->police.myfont2) + BALLE_R;
                (donnees->balle_bonus[i])->vy *= -1;
            }
            if((donnees->balle_bonus[i])->y + BALLE_R >= SCREEN_H) // Bas
            {
                if(key[KEY_Q] || (donnees->balle_bonus[i] != NULL && (donnees->balle_bonus[i])->invincibilite > 0))
                {
                    (donnees->balle_bonus[i])->y = SCREEN_H - BALLE_R;
                    (donnees->balle_bonus[i])->vy *= -1;
                    if((donnees->balle_bonus[i])->invincibilite > 0)
                        (donnees->balle_bonus[i])->invincibilite--;
                }
                else
                    desallouer = true;
            }



            for(j=0; j<donnees->nb_briques; j++)
            {
                if(brique[j] != NULL)
                {
                    // Dessous de la brique
                    if((donnees->balle_bonus[i])->y-BALLE_R <= (brique[j])->y+BRIQUE_H  &&  (donnees->balle_bonus[i])->y+BALLE_R >= (brique[j])->y+BRIQUE_H  &&  (donnees->balle_bonus[i])->x >= (brique[j])->x  &&  (donnees->balle_bonus[i])->x <= (brique[j])->x+BRIQUE_W)
                    {
                        (donnees->balle_bonus[i])->y = brique[j]->y + BRIQUE_H + BALLE_R;
                        inverser_vy = true;
                        donnees->score++;
                        brique[j]->vie -= (donnees->balle_bonus[i])->degats;
                        printf("\nBrique touchee : +1 point");
                        if((donnees->musique).play_sfx == true && brique[j]->vie > 0)
                            play_sample((donnees->musique).collision, 100, 100, 900, 0);
                        sortir_boucle = true;
                    }

                    // Dessus de la brique
                    else if((donnees->balle_bonus[i])->y+BALLE_R >= (brique[j])->y  &&  (donnees->balle_bonus[i])->y-BALLE_R <= (brique[j])->y  &&  (donnees->balle_bonus[i])->x >= (brique[j])->x  &&  (donnees->balle_bonus[i])->x <= (brique[j])->x+BRIQUE_W)
                    {
                        (donnees->balle_bonus[i])->y = brique[j]->y - BALLE_R;
                        inverser_vy = true;
                        donnees->score++;
                        brique[j]->vie -= (donnees->balle_bonus[i])->degats;
                        printf("\nBrique touchee : +1 point");
                        if((donnees->musique).play_sfx == true && brique[j]->vie > 0)
                            play_sample((donnees->musique).collision, 100, 100, 900, 0);
                        sortir_boucle = true;
                    }

                    // Gauche de la brique
                    else if((donnees->balle_bonus[i])->y >= (brique[j])->y  &&  (donnees->balle_bonus[i])->y <= (brique[j])->y+BRIQUE_H  &&  (donnees->balle_bonus[i])->x+BALLE_R >= (brique[j])->x  &&  (donnees->balle_bonus[i])->x-BALLE_R < (brique[j])->x)
                    {
                        (donnees->balle_bonus[i])->x = brique[j]->x - BALLE_R;
                        inverser_vx = true;
                        donnees->score++;
                        brique[j]->vie -= (donnees->balle_bonus[i])->degats;
                        printf("\nBrique touchee : +1 point");
                        if((donnees->musique).play_sfx == true && brique[j]->vie > 0)
                            play_sample((donnees->musique).collision, 100, 100, 900, 0);
                        sortir_boucle = true;
                    }

                    // Droite de la brique
                    else if((donnees->balle_bonus[i])->y >= (brique[j])->y  &&  (donnees->balle_bonus[i])->y <= (brique[j])->y+BRIQUE_H  &&  (donnees->balle_bonus[i])->x-BALLE_R <= (brique[j])->x+BRIQUE_W  &&  (donnees->balle_bonus[i])->x+BALLE_R > (brique[j])->x+BRIQUE_W)
                    {
                        (donnees->balle_bonus[i])->x = brique[j]->x + BRIQUE_W + BALLE_R;
                        inverser_vx = true;
                        donnees->score++;
                        brique[j]->vie -= (donnees->balle_bonus[i])->degats;
                        printf("\nBrique touchee : +1 point");
                        if((donnees->musique).play_sfx == true && brique[j]->vie > 0)
                            play_sample((donnees->musique).collision, 100, 100, 900, 0);
                        sortir_boucle = true;
                    }

                    if(inverser_vy == true)
                    {
                        (donnees->balle_bonus[i])->vy *= -1;
                        inverser_vy = false;
                    }
                    if(inverser_vx == true)
                    {
                        (donnees->balle_bonus[i])->vx *= -1;
                        inverser_vx = false;
                    }
                    if(sortir_boucle == true)
                        break;
                }
            }
        }

        if(desallouer == true) // Si la balle bonus a touché le mur du bas et qu'elle n'avait de "bonus invincibilité", on la détruit
        {
            free(donnees->balle_bonus[i]);
            donnees->balle_bonus[i] = NULL;
            desallouer = false;
        }
    }
}





void afficher_balles_bonus(t_global* donnees)
{
    int i;

    for(i=0; i<BALLE_MAX; i++)
    {
        if(donnees->balle_bonus[i] != NULL)
        {
            circlefill(donnees->buffer, (donnees->balle_bonus[i])->x, (donnees->balle_bonus[i])->y, BALLE_R, (donnees->balle_bonus[i])->couleur);
            circle(donnees->buffer, (donnees->balle_bonus[i])->x, (donnees->balle_bonus[i])->y, BALLE_R, BALLE_CONTOUR);
        }
    }
}

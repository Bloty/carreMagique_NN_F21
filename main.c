//tpcarremagique_NN_14/01/2019
#include <stdio.h>
#include <stdlib.h>

//const
#define MAX 5
#define VIDE 0
#define MINI 0
//enregistrement-------------------------------------------------------
typedef struct tJeton{
    int x;
    int y;
}tJeton;

typedef enum Bool{false,true} Bool;

//Prototype
void initialiser(int t[MAX][MAX],tJeton *coordonnee,int nI);
Bool recherche_vide(int t[MAX][MAX],tJeton coordonnee);
void placer (int t[MAX][MAX],int nI,tJeton coordonnee);
void affichage(int t[MAX][MAX]);
void avancerDroite(int t[MAX][MAX], tJeton *coordonnee);
void avancerGauche(int t[MAX][MAX], tJeton *coordonnee);
void corriger (int t[MAX][MAX], tJeton *coordonnee);

int main()
{
//variable
int t[MAX][MAX];

tJeton coordonnee;
int nI=1;

    initialiser(t,&coordonnee,nI);

    printf("--CARRE MAGIQUE--\n");
    printf("\n");

    for (nI=1;nI<=(MAX*MAX)-1;nI++)
    {
            avancerDroite(t,&coordonnee);
            corriger(t,&coordonnee);

            if (recherche_vide(t,coordonnee)==0){
                avancerGauche(t,&coordonnee);
                corriger(t,&coordonnee);

                if (recherche_vide(t, coordonnee)==1){
                    placer(t,nI,coordonnee);
                }
            }else{
                if (recherche_vide(t, coordonnee)==1){
                    placer(t,nI,coordonnee);
                }
            }
    }

    affichage(t);

    return 0;
}

//insitialiser
//But : Remplir le tableau de 0 et de placer la 1er valeur
//Entrer : le tableau, les coordonnées et i qui est la 1er valeur a placer
//Sortie : Le tableau modifier et placer tJeton
void initialiser(int t[MAX][MAX],tJeton *coordonnee,int nI)
{
    int nX=0,nY=0;

    for (nX=MINI;nX<MAX;nX++)
    {
        for (nY=MINI;nY<MAX;nY++)
        {
            t[nX][nY]=VIDE;
        }
    }
    coordonnee->x=2;
    coordonnee->y=1;
    t[coordonnee->x][coordonnee->y]=nI;
}


//verifier si le cellule est vide
//But : Verifier si la cellule du tableau est vide
//Entrer : le tableau, les coordonnées
//Sortie : la fonction vaut 1 si la cellule est vide sinon 0
Bool recherche_vide(int t[MAX][MAX],tJeton coordonnee)
{
Bool vide=false;

    if (t[coordonnee.x][coordonnee.y]==VIDE)
    {
        vide=true;
    }

    return vide;
}
//placer---------------------------------------------------------------
//But : Placer la valeur dans le tableau
//Entrer : le tableau, les coordonnée et i qui est la valeur a placer
//Sortie : Le tableau modifier
void placer (int t[MAX][MAX],int nI,tJeton coordonnee)
{
    t[coordonnee.x][coordonnee.y]=nI+1;
}

//affichage
//But : Afficher le tableau
//Entrer : le tableau
//Sortie : Ecrire Le tableau a l'écran
void affichage(int t[MAX][MAX])
{
int nX=0,nY=0;


    for (nX=MINI;nX<MAX;nX++)
    {
        for (nY=MINI;nY<MAX;nY++)
        {
            printf("%d ",t[nY][nX]);
        }
        printf("\n" );
    }
}

//avancer a droite
//But : Déplacer tJeton dans le tableau d'une case au nord et d'une case a droite
//Entrer : le tableau, les coordonnées
//Sortie : les coordonnées modifier
void avancerDroite(int t[MAX][MAX], tJeton *coordonnee)
{
    coordonnee->x++;
    coordonnee->y--;
}

//avancer a gauche
//But : Déplacer tJeton dans le tableau d'une case au nord et d'une case a gauche
//Entrer : le tableau, les coordonnées
//Sortie : les coordonnées modifier
void avancerGauche(int t[MAX][MAX], tJeton *coordonnee)
{
    coordonnee->x--;
    coordonnee->y--;
}

//Corriger
//But : Replacer tJeton quand il est a l'exterieur du tableau
//Entrer : le tableau, les coordonnées
//Sortie : les coordonnées modifier
void corriger (int t[MAX][MAX], tJeton *coordonnee)
{
    if(coordonnee->x >= MAX)
        coordonnee->x = MINI;

    if(coordonnee->x < MINI)
        coordonnee->x = MAX-1;

    if(coordonnee->y >= MAX)
        coordonnee->y = MINI;

    if(coordonnee->y < MINI)
        coordonnee->y = MAX-1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100
#define TAILLEMIN 3
#define TAILLEMAX 24
#define WIN 1
#define LOOSE 0
#define VIEMAX 10

//PROTOTYPES
char *EntrerMot();
char *setup(char mot[TAILLE]);
void affichage(int vie,char mottrouve[TAILLE]);
char entree ();
char* traitement(char L,char mot[TAILLE],char mottrouve[TAILLE], int* test);
int retirervie (int* test, int vie);
int testvictoire (char mot[TAILLE], char mottrouve[TAILLE]);
void victoiredefaite(int vie);

int main()
{
    int rejouer = WIN;
    char Mot[TAILLE];
    char Lettre;
    char MotTrouve[TAILLE];

    do{
        int vie = VIEMAX;
        int estPareil=0;
        int aTrouverUneLettre=0;

        do{
        strcpy(Mot, EntrerMot());
        }while (strlen(Mot)<TAILLEMIN);
         printf("le mot fait %i lettres\n", strlen(Mot));

        strcpy(MotTrouve,setup(Mot));

        do{
            affichage(vie,MotTrouve);
            Lettre=entree();
            strcpy(MotTrouve,traitement(Lettre,Mot,MotTrouve,&aTrouverUneLettre));
            vie=retirervie(&aTrouverUneLettre,vie);
            estPareil=testvictoire(Mot,MotTrouve);
        }while(estPareil != WIN && vie != LOOSE);

        victoiredefaite(vie);
        printf("Tu veut rejouer? (Oui = 1;Non = 0)");
        scanf("%d",&rejouer);
    }while(rejouer == WIN);

    return 0;
}


char *EntrerMot(){
char mot[TAILLE]={0};
            do{
                printf("Votre mot doit comporter au moins 3 lettres et au maximum 24 lettres.\n");
                printf("Entrer votre mot: ");
                gets(mot);
                mot[strlen(mot)+1]='\0';
            }while (strlen(mot) > TAILLEMAX || strlen(mot) <TAILLEMIN);
return mot;
}


char *setup(char mot[TAILLE]){
int i;
char mottrouve[TAILLE];
                for(i=0;i<=strlen(mot);i++){
                    if(i!=strlen( mot))
                        mottrouve[i] = '-';
                    if (i==strlen(mot))
                        mottrouve[i] ='\0';
    }
return mottrouve;

}

void affichage(int vie,char mottrouve[TAILLE]){
int i;
fflush(stdin);
     printf("Avancement du mot:");
        for(i=0;i<=strlen(mottrouve);i++){
                printf("%c",mottrouve[i]);
        }
 printf("Essais restants: %d\n",vie);

}

char entree (){
char L;
    printf("Entrer une lettre: ");
    scanf("%c", &L);
return L;
}


char *traitement(char L,char mot[TAILLE],char mottrouve[TAILLE], int* test){
int i;
     for(i = 0;i<= strlen(mot); i++){
                    if(L == mot[i]){
                        mottrouve[i] = L;
                        printf("Une occurence %c a ete trouve!\n", L);
                        *test = WIN;
                    }
                }
return mottrouve;
}

int retirervie (int* test, int vie){

int testeur=*test;
     if(testeur != WIN){
            vie -= 1;
            printf("Vous avez perdu une vie\n");
     }

    *test = LOOSE;
return vie;
}

int testvictoire (char mot[TAILLE], char mottrouve[TAILLE]){
 int pareil,i;
                //Tant que les lettre correspondent, la boucle continue, si on arrive à la fin alors les mots sont les mêmes et le joueur a donc gagné
                while(i < strlen(mot) && mottrouve[i] == mot[i])
                        i++;

                    if(i == strlen(mot))
                        pareil = WIN;
                    else
                        pareil = LOOSE;
return pareil;
}


void victoiredefaite(int vie){

     if(vie != LOOSE)
            printf("Bien jouer, ta gagner allez a+\n");

        else
            printf("Ca te dirais d'ouvrir un dico ?\n");
}



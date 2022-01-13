#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum
{
    Faux,
    Vrai
} Booleen;

typedef struct
{
    char libelle[30];
    char num[15];
} Tel;

typedef struct {int jours, mois, annee, heure, minute, seconde;} DateDem;

typedef struct {int jours, mois, annee;} Date;

/*Liste Chainer 
Seules les demandes de demandeurs ayant leur papier en règle et ne dépassant pas le plafond de ressources sont enregistrées*/

typedef struct
{
    int numDemande;
    int nbPoint;
    int nbPersonne;
    float revenueBrut;
    char nomDeFamille[31];
    char prenom[31];
    char nationalite[3];
    int nbNum;
    Tel *numTel;
    DateDem dateDemande;
} Menage;

typedef struct listeDem
{
    Menage demandeurs;
    struct listeDem *suivant;
}MaillonDem, *ListeDem;

/*Files*/

typedef struct {
    int numloca;
    char prenom[31];
    char nom[31];
    char nationalite[3];
    int plafond;
    float revenu;
    int numlogement;
    int nbNumTel;
    Tel *numTel;
    Date datedebutloca;
}Locataire;


typedef struct maillonloc {
    Locataire loc;
    struct maillonloc *suiv;
}MaillonLoc;

typedef MaillonLoc *Files;

/*Piles*/

typedef struct
{
    int numLogement;
    char typeLog[3];
    int nbChambre;
    float surfaceLog;
    float prixLog;
    Date dateAchat;
} Logement;

typedef struct maillonLog
{
    Logement logement;
    struct maillonLog *suivant;
} MaillonLog, *PileLog;


/* Menu */

void menu(void);

void affichMenu(void);

void MenuLogement(Logement *tLog[],int *nbLog);

void affichMenuLogement(void);

void MenuLocataire(Files lc);

void affichMenuLocataire(void);

void MenuChoixTrie (Files lc);

void affichChoixTrieLoca(void);

ListeDem MenuDemLog (ListeDem ld, int *nbD);

void affichMenuDemLog(void);

void sauvegardeTout(ListeDem ld, char *ficDem, int nbD, Files f, char *ficLoc);

/* Logement */

Logement lireLog(FILE *fe);

int chargeLogement(char *nomFich, Logement *tLog[], int taillemax);

void affichageLog(Logement *tLog[], int nb);

/* Locataire */

Locataire lireLocataire(FILE *fLoca);

Files chargementLoc (Files f, int *nbelem, char *fic2);

void AffichLocataire(Files f);

void AffichLocatairePrecis(Files f);

Files Enfillercharge (Files f, Locataire loc);

Files EnfilerLoca (Files f,int numloca, char prenom[], char nom[], char nationalite[], int plafond, float revenu, int numloge);

Files Defiler (Files f);

Files FileVide(void);

void Vider (Files *f);

Booleen EstVide (Files f);

void RechLoca (Files f, int numlocataire);

void sauvegardeLoc(Files f, FILE *fLoc);

/* Demandeur */
ListeDem initliste(void);

ListeDem lireMenage(FILE *fDem, ListeDem l);

ListeDem chargementDem(ListeDem l, int *nbD, char *fic);

void affichageDem(ListeDem l);

Booleen numExiste(ListeDem l, int value);

ListeDem insertionEnTeteDem(ListeDem l, int nbPoint, int nbPersonne, float revenueBrut, char *nomDeFamille, char *prenom, char *nationalite);

ListeDem insertionDem(ListeDem l, int nbPoint, int nbPersonne, float revenueBrut, char *nomDeFamille, char *prenom, char *nationalite);

ListeDem rechercheUnDemandeur(ListeDem l, int value);

void afficherUnDemandeur(ListeDem l, int value);

ListeDem suppressionEnTete(ListeDem l, int *nbD);

ListeDem suppression(ListeDem l, int suppDem, int *nbD);

ListeDem modification(ListeDem l, int modif);

ListeDem expirationDemEnTete(ListeDem l, int *nbD);

ListeDem expirationDem(ListeDem l, int *nbD);

void suppressionAll(ListeDem l, int *nbD);

void sauvegardeDem(ListeDem l, FILE *fDem);
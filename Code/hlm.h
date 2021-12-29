#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Faux,
    Vrai
} Booleen;

/*Liste Chainer 
Seules les demandes de demandeurs ayant leur papier en règle et ne dépassant pas le plafond de ressources sont enregistrées*/
typedef struct
{
    int   nbPoint;
    int nbPersonne;
    float ressourceAnnuel;
    char nomDeFamille[50];
    int numTel;
} Menage;

typedef struct liste
{
    Menage demandeurs;
    struct liste *suivant;
}Maillon, *Liste;

/*Files*/

 
/*Piles*/



/* Menu */

void afficheMenu(void);

void afficheMenuLogement(void);

void afficheMenuLocataire(void);

void afficheMenuLocatairePrecis(void);

void afficheMenuDemLog(void);

void menu(void);

#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <string.h>

typedef enum {DUT, DEUG, DEUST, LICENCE, MAITRISE, MASTER, CPGE} Diplome;

/**
  * Structure Etudiant
  */
typedef struct Etudiant{
    char nom[20];
    char prenom[20];

    char motDePasse[25];
    char cin[20];
    char cne[20];
    float notes[8];

    Diplome diplome;

    char etab[30];
    int nbrAns;
    int anDiplome;
} Etudiant;

/**
  * Structure Liste d'étudiants
  */
typedef struct ListeEtudiants
{
    Etudiant *data;
    struct ListeEtudiants *next;
} ListeEtudiants;

///// FONCTIONS Etudiants

Etudiant etudiant_creer(char *nom, char *prenom, char *motDePasse,
                        char *cin,  char *cne,
                        char *etab, int anDiplome, int nbreAns,
                        Diplome diplome, float notes[8])
{
    Etudiant etud;

    strcpy(etud.nom, nom);
    strcpy(etud.prenom, prenom);
    strcpy(etud.motDePasse, motDePasse);

    strcpy(etud.cin,cin);
    strcpy(etud.cne,cne);

    strcpy(etud.etab, etab);

    etud.anDiplome = anDiplome;
    etud.nbreAns = nbreAns;
    etud.diplome = diplome;

    memcpy(etud.notes, notes, sizeof(float) * 8);

    return etud;
}

int nombre_notes_diplome(Diplome dip)
{
    switch (dip) {
    case CPGE: return 1;
    case DUT:
    case DEUST:
        return 4;
    case LICENCE:
        return 6;
    case MAIRISE:
        return 8;
    }
}

#endif // ETUDIANTS_H

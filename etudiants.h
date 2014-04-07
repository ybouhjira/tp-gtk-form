#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <gtk/gtk.h>
#include "pageedudiant.h"

typedef enum {DUT, DEUG, DEUST, LICENCE, MAITRISE, MASTER, CPGE} Diplome;

/**
  * Structure Etudiant
  */
typedef struct Etudiant
{
    char nom[20];
    char prenom[20];

    char motDePasse[25];
    char cin[20];
    char cne[20];
    float notes[NOMBRE_NOTES];

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

Etudiant* etudiant_creer(const char *nom, const char *prenom,
                         const char *motDePasse,
                        const char *cin,  const char *cne,
                        const char *etab, int anDiplome, int nbrAns,
                        Diplome diplome, float notes[8]);

int nombre_notes_diplome(Diplome dip);

Diplome convertir_diplome(const char* diplome);

const char* diplome_to_char(Diplome diplome);

// Fonctions Utilisées avec GHashTables
gboolean etudiant_egaux(const void *etud1, const void *etud2);

void etudiant_detruire(void *etud);

#endif // ETUDIANTS_H

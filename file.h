#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "etudiants.h"

Etudiant* lire_etudiant(FILE *fichier)
{
    Etudiant *etudiant = malloc(sizeof(Etudiant));

    while(fgetc(fichier) != '\n');

    fscanf(fichier, "\tcne : %s", etudiant->cne);
    fscanf(fichier, "\tnom : %s", etudiant->nom);
    fscanf(fichier, "\tprenom : %s", etudiant->prenom);
    fscanf(fichier, "\tcne : %s", etudiant->cne);
    fscanf(fichier, "\tmot de passe : %s", etudiant->motDePasse);
    fscanf(fichier, "\tcin : %s", etudiant->cin);
    fscanf(fichier, "\tnotes : %s", etudiant->cne);
    fscanf(fichier, "\tdiplome : %s", etudiant->diplome);

    fscanf(fichier, "\tnotes : ");
    int nbrNotes = nombre_notes_diplome(etudiant->diplome), i;
    for(i = 0; i < nbrNotes; i++)
        fscanf(fichier, "%f,", etudiant->notes[i]);

    fscanf(fichier, "\tetablissement : %s", etudiant->etab);
    fscanf(fichier, "\tnombre d'années : %d", etudiant->nbrAns);
    fscanf(fichier, "\tannée d'obtention' : %s", etudiant->anDiplome);

    return etudiant;
}

#endif // FILE_H

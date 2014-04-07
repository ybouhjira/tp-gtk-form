#include "file.h"
#include <stdlib.h>

Etudiant* lire_etudiant(FILE *fichier)
{
    Etudiant *etudiant = malloc(sizeof(Etudiant));

    while(fgetc(fichier) != '\n');

    fscanf(fichier, "\tcne : %s", etudiant->cne);
    fscanf(fichier, "\tnom : %s", etudiant->nom);
    fscanf(fichier, "\tprenom : %s", etudiant->prenom);
    fscanf(fichier, "\tmot de passe : %s", etudiant->motDePasse);
    fscanf(fichier, "\tcin : %s", etudiant->cin);
    char diplome[100];
    fscanf(fichier, "\tdiplome : %s", diplome);
    etudiant->diplome = convertir_diplome(diplome);

    fscanf(fichier, "\tnotes : ");
    int nbrNotes = nombre_notes_diplome(etudiant->diplome), i;
    for(i = 0; i < nbrNotes; i++)
        fscanf(fichier, "%f,", &etudiant->notes[i]);

    fscanf(fichier, "\tetablissement : %s", etudiant->etab);
    fscanf(fichier, "\tnombre d'années : %d", &etudiant->nbrAns);
    fscanf(fichier, "\tannée d'obtention : %d\n", &etudiant->anDiplome);

    return etudiant;

}

void ecrire_etudiant(FILE *fichier, int num, Etudiant *etudiant)
{

    fprintf(fichier, "%d : \n", num);

    fprintf(fichier, "\tcne : %s", etudiant->cne);
    fprintf(fichier, "\tnom : %s", etudiant->nom);
    fprintf(fichier, "\tprenom : %s", etudiant->prenom);
    fprintf(fichier, "\tmot de passe : %s", etudiant->motDePasse);
    fprintf(fichier, "\tcin : %s", etudiant->cin);
    fprintf(fichier, "\tdiplome : %s", diplome_to_char(etudiant->diplome));
    fprintf(fichier, "\tnotes : %s", etudiant->cne);

    fprintf(fichier, "\tnotes : ");
    int nbrNotes = nombre_notes_diplome(etudiant->diplome), i;
    for(i = 0; i < nbrNotes; i++)
        fprintf(fichier, "%f,", etudiant->notes[i]);

    fprintf(fichier, "\tetablissement : %s", etudiant->etab);
    fprintf(fichier, "\tnombre d'années : %d", etudiant->nbrAns);
    fprintf(fichier, "\tannée d'obtention : %d", etudiant->anDiplome);
}

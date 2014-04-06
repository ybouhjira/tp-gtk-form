#ifndef FILE_H
#define FILE_H

#include "etudiants.h"
#include <stdio.h>

Etudiant* lire_etudiant(FILE *fichier);

void ecrire_etudiant(FILE *fichier, int num, Etudiant *etudiant);

#endif // FILE_H

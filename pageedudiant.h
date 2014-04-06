#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <gtk/gtk.h>
#include <assert.h>

#include "helpers.h"
#include "callbacks.h"

#define NOMBRE_NOTES 8

typedef struct PageEtudiant
{
    GtkWidget *layout;

    // Informations personnelles
    GtkWidget *infoFrame;
    GtkWidget *infoTable;

    GtkWidget *cne, *nom, *prenom, *cin;

    // Diplome
    GtkWidget *diplomeFrame;
    GtkWidget *diplomeTable;

    GtkWidget *diplome, *notes[NOMBRE_NOTES], *notesLabels[NOMBRE_NOTES], *etab, *nbrAns, *anDiplome;

} PageEtudiant;

extern PageEtudiant pageEtudiant;

/**
 * Entrees:
 *  etudiant : une a modifier  (cne = NULL)
 *  cne : cne de l'étudiant  (etudiant = NULL)
 * Description :
 *  Retourne le formulaire d'inscription/modification d'un étudiant
 */
void create_student_page();

#endif // ADDSTUDENT_H

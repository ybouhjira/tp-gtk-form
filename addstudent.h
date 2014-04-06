#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <gtk/gtk.h>
#include <assert.h>

#include "helpers.h"

#define NOMBRE_NOTES 8

typedef struct
{
    GtkWidget *layout;

    // Informations personnelles
    GtkWidget *infoFrame;
    GtkWidget *infoTable;

    GtkWidget *cne, *nom, *prenom, *cin;

    // Diplome
    GtkWidget *diplomeFrame;
    GtkWidget *diplomeTable;

    GtkWidget *diplome, *notes[8], *etab, *nbrAns, *anDiplome;

} PageEtudiant;
PageEtudiant pageEtudiant;

/**
 * Entrees:
 *  etudiant : une a modifier  (cne = NULL)
 *  cne : cne de l'étudiant  (etudiant = NULL)
 * Description :
 *  Retourne le formulaire d'inscription/modification d'un étudiant
 */
void create_student_page()
{
    pageEtudiant.layout = gtk_vbox_new(FALSE, 5);

    // Informations personnelles
    pageEtudiant.infoFrame = gtk_frame_new("Informations personelles");
    gtk_container_add(GTK_CONTAINER(pageEtudiant.layout), pageEtudiant.infoFrame);
    pageEtudiant.infoTable = gtk_table_new(4, 2, FALSE);
    gtk_container_set_border_width (GTK_CONTAINER (pageEtudiant.infoTable), 10);
    gtk_container_add(GTK_CONTAINER(pageEtudiant.infoFrame), pageEtudiant.infoTable);

    pageEtudiant.nom = gtk_entry_new();
    pageEtudiant.prenom = gtk_entry_new();
    pageEtudiant.cin = gtk_entry_new();
    pageEtudiant.cne = gtk_entry_new();

    gtk_widget_set_sensitive(pageEtudiant.cne, FALSE);


    table_attach(pageEtudiant.infoTable, gtk_label_new("Nom"), 0, 1, 0, 1);
    table_attach(pageEtudiant.infoTable, pageEtudiant.nom, 1, 2, 0, 1);
    table_attach(pageEtudiant.infoTable, gtk_label_new("Prénom"), 0, 1, 1, 2);
    table_attach(pageEtudiant.infoTable, pageEtudiant.prenom, 1, 2, 1, 2);
    table_attach(pageEtudiant.infoTable, gtk_label_new("CIN"), 0, 1, 2, 3);
    table_attach(pageEtudiant.infoTable, pageEtudiant.cin, 1, 2, 2, 3);
    table_attach(pageEtudiant.infoTable, gtk_label_new("CNE"), 0, 1, 3, 4);
    table_attach(pageEtudiant.infoTable, pageEtudiant.cne, 1, 2, 3, 4);

    // Diplome
    pageEtudiant.diplomeFrame = gtk_frame_new("Diplome");
    gtk_container_add(GTK_CONTAINER(pageEtudiant.layout), pageEtudiant.diplomeFrame);
    pageEtudiant.diplomeTable = gtk_table_new(10, 2, FALSE);
    gtk_container_set_border_width (GTK_CONTAINER(pageEtudiant.diplomeTable), 10);
    gtk_container_add(GTK_CONTAINER(pageEtudiant.diplomeFrame),
                      pageEtudiant.diplomeTable);

    pageEtudiant.diplome = gtk_combo_box_new_text();
    char *dipls[10] = {"DUT", "DEUG", "DEUST", "Licence", "Maitrise",
                             "Master", "CPGE"};
    int i;
    for(i = 0; i < 7; ++i)
        gtk_combo_box_append_text(GTK_COMBO_BOX(pageEtudiant.diplome), dipls[i]);
    gtk_combo_box_set_active(GTK_COMBO_BOX(pageEtudiant.diplome), 0);

    for(i=0; i < NOMBRE_NOTES; ++i) pageEtudiant.notes[i] = gtk_entry_new();

    pageEtudiant.etab = gtk_entry_new();
    pageEtudiant.nbrAns = gtk_entry_new();
    pageEtudiant.anDiplome = gtk_entry_new();

    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Diplome"), 0, 1, 0, 1);

    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 1"), 0, 1, 1, 2);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 2"), 0, 1, 2, 3);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 3"), 0, 1, 3, 4);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 4"), 0, 1, 4, 5);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 5"), 0, 1, 5, 6);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 6"), 0, 1, 6, 7);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 7"), 0, 1, 7, 8);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Note 8"), 0, 1, 8, 9);

    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Etablissement"), 0, 1, 9, 10);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("nomrbre d'années"), 0, 1, 10, 11);
    table_attach(pageEtudiant.diplomeTable, gtk_label_new("Année d'obtention"), 0, 1, 11, 12);

    table_attach(pageEtudiant.diplomeTable, pageEtudiant.diplome, 1, 2, 0, 1);
    for(i = 0; i < NOMBRE_NOTES; ++i)
        table_attach(pageEtudiant.diplomeTable, pageEtudiant.notes[i], 1, 2, 1 + i, 2 + i);
    table_attach(pageEtudiant.diplomeTable, pageEtudiant.etab, 1, 2, 9, 10);
    table_attach(pageEtudiant.diplomeTable, pageEtudiant.nbrAns, 1, 2, 10, 11);
    table_attach(pageEtudiant.diplomeTable, pageEtudiant.anDiplome, 1, 2, 11, 12);

    // Bouton OK
    GtkWidget *ok = gtk_button_new_with_label("OK");
    gtk_container_add(GTK_CONTAINER(pageEtudiant.layout), ok);


    GtkWidget *scrollarea = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollarea),
                                          pageEtudiant.layout);

    pageEtudiant.layout = scrollarea;

}

#endif // ADDSTUDENT_H

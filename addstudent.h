#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <gtk/gtk.h>

#define NOMBRE_NOTES 8

GtkWidget *create_student_page()
{
    GtkWidget *page = gtk_vbox_new(FALSE, 5);

    // Informations personnelles
    GtkWidget *infoFrame = gtk_frame_new("Informations personelles");
    gtk_container_add(GTK_CONTAINER(page), infoFrame);
    GtkWidget *infoTable = gtk_table_new(4, 2, FALSE);
    gtk_container_set_border_width (GTK_CONTAINER (infoTable), 10);
    gtk_container_add(GTK_CONTAINER(infoFrame), infoTable);

    GtkWidget *nom = gtk_entry_new();
    GtkWidget *prenom = gtk_entry_new();
    GtkWidget *cin = gtk_entry_new();
    GtkWidget *cne = gtk_entry_new();

#define attach(table, widget, left, right, top, bottom) \
    gtk_table_attach(GTK_TABLE(table), widget, left, right, top, bottom, \
     GTK_SHRINK, GTK_SHRINK, 5, 1)

    attach(infoTable, gtk_label_new("Nom"), 0, 1, 0, 1);
    attach(infoTable, nom, 1, 2, 0, 1);
    attach(infoTable, gtk_label_new("Prénom"), 0, 1, 1, 2);
    attach(infoTable, prenom, 1, 2, 1, 2);
    attach(infoTable, gtk_label_new("CIN"), 0, 1, 2, 3);
    attach(infoTable, cin, 1, 2, 2, 3);
    attach(infoTable, gtk_label_new("CNE"), 0, 1, 3, 4);
    attach(infoTable, cne, 1, 2, 3, 4);

    // Diplome
    GtkWidget *diplomeFrame = gtk_frame_new("Diplome");
    gtk_container_add(GTK_CONTAINER(page), diplomeFrame);
    GtkWidget *diplomeTable = gtk_table_new(10, 2, FALSE);
    gtk_container_set_border_width (GTK_CONTAINER(diplomeTable), 10);
    gtk_container_add(GTK_CONTAINER(diplomeFrame), diplomeTable);

    GtkWidget *diplome = gtk_combo_box_new_text();
    char *nomDiplomes[10] = {"DUT", "DEUG", "DEUST", "Licence", "Maitrise",
                          "Master", "CPGE"};
    int i;
    for(i = 0; i < 7; ++i)
        gtk_combo_box_append_text(GTK_COMBO_BOX(diplome), nomDiplomes[i]);
    gtk_combo_box_set_active(GTK_COMBO_BOX(diplome), 0);


    GtkWidget *notes[NOMBRE_NOTES];
    for(i=0; i < NOMBRE_NOTES; ++i) notes[i] = gtk_entry_new();

    GtkWidget *etab = gtk_entry_new();
    GtkWidget *nombreAns = gtk_entry_new();
    GtkWidget *anDiplome = gtk_entry_new();

    attach(diplomeTable, gtk_label_new("Diplome"), 0, 1, 0, 1);

    attach(diplomeTable, gtk_label_new("Note 1"), 0, 1, 1, 2);
    attach(diplomeTable, gtk_label_new("Note 2"), 0, 1, 2, 3);
    attach(diplomeTable, gtk_label_new("Note 3"), 0, 1, 3, 4);
    attach(diplomeTable, gtk_label_new("Note 4"), 0, 1, 4, 5);
    attach(diplomeTable, gtk_label_new("Note 5"), 0, 1, 5, 6);
    attach(diplomeTable, gtk_label_new("Note 6"), 0, 1, 6, 7);
    attach(diplomeTable, gtk_label_new("Note 7"), 0, 1, 7, 8);
    attach(diplomeTable, gtk_label_new("Note 8"), 0, 1, 8, 9);

    attach(diplomeTable, gtk_label_new("Etablissement"), 0, 1, 9, 10);
    attach(diplomeTable, gtk_label_new("nomrbre d'années"), 0, 1, 10, 11);
    attach(diplomeTable, gtk_label_new("Année d'obtention"), 0, 1, 11, 12);

    attach(diplomeTable, diplome, 1, 2, 0, 1);
    for(i = 0; i < NOMBRE_NOTES; ++i)
        attach(diplomeTable, notes[i], 1, 2, 1 + i, 2 + i);
    attach(diplomeTable, etab, 1, 2, 9, 10);
    attach(diplomeTable, nombreAns, 1, 2, 10, 11);
    attach(diplomeTable, anDiplome, 1, 2, 11, 12);

    // Bouton OK
    GtkWidget *ok = gtk_button_new_with_label("OK");
    gtk_container_add(GTK_CONTAINER(page), ok);


    GtkWidget *scrollarea = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollarea),
                                          page);

    return scrollarea;
}

#endif // ADDSTUDENT_H

#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <gtk/gtk.h>

void select_tab(GtkWidget *btn, void *data);

void go_home(GtkWidget *widget, void* data);

void inscrire_etudiant(GtkWidget *boutonInscription, void *notebook);

void hide_notes(GtkWidget *menu);

#endif // CALLBACKS_H

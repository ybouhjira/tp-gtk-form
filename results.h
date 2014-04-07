#ifndef RESULTS_H
#define RESULTS_H

#include <gtk/gtk.h>
#include "results.h"
#include "etudiants.h"

typedef struct
{
    GtkWidget *vueTous, *vueAcept, *vueRejete;
    GtkWidget *notebook;
}PageResult;

extern PageResult pageResult;

void create_result_page();

void init_list(GtkWidget *list);

void add_to_list(GtkWidget *list, Etudiant *etudiant);

void remplire_vue_tous();

#endif // RESULTS_H

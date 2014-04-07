#ifndef RESULTS_H
#define RESULTS_H

#include <gtk/gtk.h>
#include "results.h"

typedef struct
{
    GtkWidget *vueTous, *vueAcept, *vueRejete;
    GtkWidget *notebook;
}PageResult;

extern PageResult pageResult;

void create_result_page();


#endif // RESULTS_H

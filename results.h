#ifndef RESULTS_H
#define RESULTS_H

#include <gtk/gtk.h>

GtkWidget *create_result_page()
{
    GtkWidget *treeView = gtk_tree_view_new();

    return treeView;
}

#endif // RESULTS_H

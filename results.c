#include "results.h"

PageResult pageResult;

void create_result_page()
{
    pageResult.notebook = gtk_notebook_new();

    pageResult.vueAcept = gtk_tree_view_new();
    pageResult.vueRejete = gtk_tree_view_new();
    pageResult.vueTous = gtk_tree_view_new();

    gtk_notebook_append_page(GTK_NOTEBOOK(pageResult.notebook),
                             pageResult.vueTous,
                             gtk_label_new("Tous"));
    gtk_notebook_append_page(GTK_NOTEBOOK(pageResult.notebook),
                             pageResult.vueAcept,
                             gtk_label_new("Acceptés"));
    gtk_notebook_append_page(GTK_NOTEBOOK(pageResult.notebook),
                             pageResult.vueRejete,
                             gtk_label_new("Rejetés"));
}

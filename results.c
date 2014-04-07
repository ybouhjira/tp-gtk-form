#include "results.h"
#include "hashtable.h"

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


void init_list(GtkWidget *list)
{
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *nom, *prenom, *cne;
    GtkListStore *store;


    cne = gtk_tree_view_column_new_with_attributes("cne", renderer,
                                                      "text",
                                                      0, NULL);
    nom = gtk_tree_view_column_new_with_attributes("nom", renderer,
                                                      "text",
                                                      1, NULL);
    prenom = gtk_tree_view_column_new_with_attributes("prenom", renderer,
                                                      "text",
                                                      2, NULL);


    gtk_tree_view_append_column(GTK_TREE_VIEW(list), cne);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), nom);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), prenom);

    store = gtk_list_store_new(3, G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING);

    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));

    g_object_unref(store);
}

void add_to_list(GtkWidget *list, Etudiant *etudiant)
{
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model
                           (GTK_TREE_VIEW(list)));

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, etudiant->cne, -1);
    gtk_list_store_set(store, &iter, 1, etudiant->nom, -1);
    gtk_list_store_set(store, &iter, 2, etudiant->prenom, -1);
}

void add_to_store(gpointer key, gpointer value, gpointer data)
{
    printf("add_to_store\n");
    add_to_list((GtkWidget*)data, (Etudiant*)value);
}

void remplire_vue_tous()
{
    init_list(pageResult.vueTous);

    GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model
                           (GTK_TREE_VIEW(pageResult.vueTous)));

    gtk_list_store_clear(store);

    g_hash_table_foreach(tableCpge, add_to_store, pageResult.vueTous);
    g_hash_table_foreach(tableDut, add_to_store, pageResult.vueTous);
    g_hash_table_foreach(tableLicence, add_to_store, pageResult.vueTous);
}

#include <gtk/gtk.h>
#include <string.h>

#include "addstudent.h"
#include "callbacks.h"
#include "mainwindow.h"
#include "dialogs.h"

int main( int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    open_sign_up_dialog(NULL);
    // Fenetre
    GtkWidget *window = create_window();

    // Ajouter une vbox dans la fenetre
    GtkWidget *windowBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), windowBox);

    // Toolbar
    GtkWidget *toolbar = toolbar_create();
    gtk_box_pack_start(GTK_BOX(windowBox), toolbar, FALSE, FALSE, 5);

    // Ajouter un bouton acceuil
    GtkToolItem *home = gtk_tool_button_new_from_stock(GTK_STOCK_HOME);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), home, -1);

    // notebook
    GtkWidget *notebook = notebook_create();
    gtk_container_add(GTK_CONTAINER(windowBox), notebook);

    GtkWidget *welcomePage = create_welcome_page(notebook);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), welcomePage, NULL);

    GtkWidget *formPage = create_student_page();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), formPage, NULL);

    // Connections des signaux
    g_signal_connect_swapped(G_OBJECT(window), "destroy",
                             G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(home), "clicked", G_CALLBACK(go_home),
                     notebook);

    // Affichage de la fenetre
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

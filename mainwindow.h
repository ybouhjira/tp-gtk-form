#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtk/gtk.h>

GtkWidget *create_window()
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    gtk_window_set_title(GTK_WINDOW(window), "Inscription ILIS");
    return window;
}

GtkWidget *toolbar_create()
{
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
    gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);
    return toolbar;
}

GtkWidget *notebook_create()
{
    GtkWidget *notebook = gtk_notebook_new();
    gtk_notebook_set_show_tabs(GTK_NOTEBOOK(notebook), FALSE);
    return notebook;
}

GtkWidget *create_welcome_page(GtkWidget *notebook)
{
    GtkWidget *page = gtk_vbox_new(FALSE, 10);
    gtk_container_set_border_width(GTK_CONTAINER(page), 100);

    // Ajout de boutons
    GtkWidget *addButton = gtk_button_new_with_mnemonic("Inscription");
    GtkWidget *editButton = gtk_button_new_with_mnemonic("Modification");
    GtkWidget *adminButton = gtk_button_new_with_mnemonic("Administrateur");
    GtkWidget *resultButton = gtk_button_new_with_mnemonic("Résultats");

    gtk_box_pack_start(GTK_BOX(page), addButton, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(page), editButton, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(page), adminButton, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(page), resultButton, FALSE, FALSE, 5);

    g_signal_connect(G_OBJECT(addButton), "clicked",
                     G_CALLBACK(select_tab), notebook);
    g_signal_connect(G_OBJECT(resultButton), "clicked",
                     G_CALLBACK(select_tab), notebook);

    return page;
}
#endif // MAINWINDOW_H

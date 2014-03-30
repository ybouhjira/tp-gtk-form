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

int main( int argc, char *argv[])
{
    gtk_init(&argc, &argv);

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

    // Connections des signaux
    g_signal_connect_swapped(G_OBJECT(window), "destroy",
                             G_CALLBACK(gtk_main_quit), NULL);

    // Affichage de la fenetre
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

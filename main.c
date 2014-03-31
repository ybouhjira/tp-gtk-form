#include <gtk/gtk.h>
#include <string.h>

#define NOMBRE_NOTES 8

// Callbacks
void select_tab(GtkWidget *btn, void *data)
{
    const char *text = gtk_button_get_label(GTK_BUTTON(btn));

    GtkWidget *notebook = (GtkWidget*) data;
    if(strcmp(text, "Eudiant"))
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 1);
    else
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}

void go_home(GtkWidget *widget, void* data)
{
    GtkWidget *notebook = (GtkWidget*) data;
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}
// Fin des callbacks

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

    // Ajout de boutons
    GtkWidget *studiantButton = gtk_button_new_with_mnemonic("Etudiant");
    GtkWidget *adminButton = gtk_button_new_with_mnemonic("Administrateur");
    GtkWidget *resultButton = gtk_button_new_with_mnemonic("Resultat");


    gtk_box_pack_start(GTK_BOX(page), studiantButton, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(page), adminButton, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(page), resultButton, FALSE, FALSE, 5);

    g_signal_connect(G_OBJECT(studiantButton), "clicked",
                     G_CALLBACK(select_tab), notebook);

    return page;
}

#define attach(table, widget, left, right, top, bottom) \
    gtk_table_attach(GTK_TABLE(table), widget, left, right, top, bottom, \
     GTK_SHRINK, GTK_SHRINK, 5, 1)

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

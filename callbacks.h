#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <gtk/gtk.h>

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

//void hide_notes(GtkWidget *menu, void *data)
//{
//    GtkWidget *notes[8] = (GtkWidget*[8]) data;

//    int active = gtk_combo_box_get_active(GTK_COMBO_BOX(menu));


//    switch (active)
//    {
//    case 0:

//    case 1:
//    case 2:
//    case 3:
//    case 4:
//    case 5:
//    case 6:
//    case 7:

//        break;
//    default:
//        break;
//    }
//}

#endif // CALLBACKS_H

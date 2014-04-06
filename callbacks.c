#include "callbacks.h"
#include "dialogs.h"
#include "pageedudiant.h"
#include "etudiants.h"

#include <string.h>

void select_tab(GtkWidget *btn, void *data)
{
    const char *text = gtk_button_get_label(GTK_BUTTON(btn));

    GtkWidget *notebook = (GtkWidget*) data;

    printf("%s\n", text);
    if(strcmp(text, "Inscription") == 0)
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 1);
    else if(strcmp(text, "Résultats") == 0)
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 2);
    else
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}

void go_home(GtkWidget *widget, void* data)
{
    GtkWidget *notebook = (GtkWidget*) data;
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}

void inscrire_etudiant(GtkWidget *boutonInscription, void *notebook)
{
    GtkNotebook *gtkNoteBook = (GtkNotebook*) notebook;

    SignUp signup = open_sign_up_dialog(GTK_WINDOW(
                                            gtk_widget_get_toplevel(
                                                boutonInscription)));

    // Si l'utilisateur a cliquer sur OK et le formulaire est valide
    if(strlen(signup.cne) > 0)
    {
        gtk_notebook_set_current_page(gtkNoteBook, 1);
        gtk_entry_set_text(GTK_ENTRY(pageEtudiant.cne), signup.cne);
    }
}

void hide_notes(GtkWidget *menu)
{

    int active = gtk_combo_box_get_active(GTK_COMBO_BOX(menu));

    int nombreNotes = nombre_notes_diplome((Diplome) active), i;

    for(i = 0; i < nombreNotes; ++i)
    {
        gtk_widget_set_visible(pageEtudiant.notes[i], TRUE);
        gtk_widget_set_visible(pageEtudiant.notesLabels[i], TRUE);
    }

    for(i = nombreNotes; i < 8; ++i)
    {
        gtk_widget_set_visible(pageEtudiant.notes[i], FALSE);
        gtk_widget_set_visible(pageEtudiant.notesLabels[i], FALSE);
    }

    if(active == CPGE)
        gtk_label_set_text(GTK_LABEL(pageEtudiant.notesLabels[0]), "Classement");
    else
        gtk_label_set_text(GTK_LABEL(pageEtudiant.notesLabels[0]), "Note 1");

}

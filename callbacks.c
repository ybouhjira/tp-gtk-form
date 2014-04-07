#include "callbacks.h"
#include "dialogs.h"
#include "pageedudiant.h"
#include "etudiants.h"
#include "hashtable.h"

#include <string.h>
#include <stdlib.h>

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
    GtkWidget *gtkNoteBook = (GtkWidget*) notebook;

    SignUp signup = open_sign_up_dialog(GTK_WINDOW(
                                            gtk_widget_get_toplevel(
                                                boutonInscription)));

    // Si l'utilisateur a cliqué sur OK et le formulaire est valide
    if(strlen(signup.cne) > 0)
    {
        GHashTable *table;
        switch(convertir_diplome(gtk_combo_box_get_active_text(
                                     GTK_COMBO_BOX(pageEtudiant.diplome))))
        {
        case CPGE:
            table = tableCpge;
            break;
        case DUT:
        case DEUG:
        case DEUST:
            table = tableDut;
            break;
        default:
            table = tableLicence;
        }

        // voir si existe déja
        if(g_hash_table_lookup(table, signup.cne))
        {
            GtkWidget *errorDialog = gtk_message_dialog_new (
                        GTK_WINDOW(gtk_widget_get_toplevel(gtkNoteBook)),
                        GTK_DIALOG_MODAL,
                        GTK_MESSAGE_ERROR,
                        GTK_BUTTONS_CLOSE,
                        "Ce CNE existe déja");
            gtk_dialog_run (GTK_DIALOG (errorDialog));
            gtk_widget_destroy (errorDialog);
            return;
        }

        // Aller a la page
        gtk_notebook_set_current_page(GTK_NOTEBOOK(gtkNoteBook), 1);
        gtk_entry_set_text(GTK_ENTRY(pageEtudiant.cne), signup.cne);

        // creer un etudiant et l'inserer
        float notes[NOMBRE_NOTES];
        int i;
        for(i = 0; i <  NOMBRE_NOTES; ++i)
            notes[i] = atof(gtk_entry_get_text(GTK_ENTRY(pageEtudiant.notes[i])));


        Etudiant *etudiant = etudiant_creer(
                    gtk_entry_get_text(GTK_ENTRY(pageEtudiant.nom)),
                    gtk_entry_get_text(GTK_ENTRY(pageEtudiant.prenom)),
                    signup.password,
                    gtk_entry_get_text(GTK_ENTRY(pageEtudiant.cin)),
                    gtk_entry_get_text(GTK_ENTRY(pageEtudiant.cne)),
                    gtk_entry_get_text(GTK_ENTRY(pageEtudiant.etab)),
                    atoi(gtk_entry_get_text(GTK_ENTRY(pageEtudiant.anDiplome))),
                    atoi(gtk_entry_get_text(GTK_ENTRY(pageEtudiant.nbrAns))),
                    convertir_diplome(gtk_combo_box_get_active_text(
                                          GTK_COMBO_BOX(pageEtudiant.diplome))),
                    notes
                    );


        // Inserer l'etudiant
        g_hash_table_insert(table, etudiant->cne, etudiant);
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

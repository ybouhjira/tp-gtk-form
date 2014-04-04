#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <gtk/gtk.h>
#include "helpers.h"

typedef struct
{
    char cne[10];
    char password[35];
} SignUp;

SignUp open_sign_up_dialog(GtkWindow *parent)
{
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Inscription", parent,
                                                    GTK_DIALOG_MODAL,
                                                    GTK_STOCK_OK,
                                                    GTK_RESPONSE_OK,
                                                    NULL);

    // Insertion des widget dans une table
    GtkWidget *table = gtk_table_new(3, 2, FALSE);
    gtk_container_set_border_width (GTK_CONTAINER (table), 10);

    GtkWidget *cne = gtk_entry_new();
    GtkWidget *password = gtk_entry_new();
    GtkWidget *confirm = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);
    gtk_entry_set_visibility(GTK_ENTRY(confirm), FALSE);

    GtkWidget *cneLabel = gtk_label_new("CNE");
    GtkWidget *passwordLabel = gtk_label_new("Mot de passe");
    GtkWidget *confirmLabel = gtk_label_new("Répéter le mot de passe");

    table_attach(table, cne, 1, 2, 0, 1);
    table_attach(table, password, 1, 2, 1, 2);
    table_attach(table, confirm, 1, 2, 2, 3);

    table_attach(table, cneLabel, 0, 1, 0, 1);
    table_attach(table, passwordLabel, 0, 1, 1, 2);
    table_attach(table, confirmLabel, 0, 1, 2, 3);


    // Ajout de la table dans la fenetre dialog
    gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), table);

    // Affichage de la fenetre
    gtk_widget_show_all (dialog);
    SignUp result = {"", ""};
    gboolean passwordMatchs = FALSE; // password == confirm

    while(!passwordMatchs)
    {
        if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK)
        {
            const char *cneText = gtk_entry_get_text(GTK_ENTRY(cne));
            const char *passwordText = gtk_entry_get_text(GTK_ENTRY(password));
            const char *confirmText = gtk_entry_get_text(GTK_ENTRY(confirm));

            // confirmation de mot de passe invalide
            if(strcmp(passwordText, confirmText) != 0)
            {
                GtkWidget *errorDialog = gtk_message_dialog_new (
                            GTK_WINDOW(dialog),
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "Les deux mots de passe doivent être "
                            "identiques");
                gtk_dialog_run (GTK_DIALOG (errorDialog));
                gtk_widget_destroy (errorDialog);
                continue;
            }

            passwordMatchs = TRUE;

            strcpy(result.cne, cneText);
            strcpy(result.password, passwordText);
        }
        else
        {
            break;
        }
    }

    gtk_widget_destroy(dialog);
    return result;
}

#endif // SIGNUP_FORM_H

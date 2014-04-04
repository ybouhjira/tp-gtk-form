#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <gtk/gtk.h>

typedef struct
{
  char cne[10];
  char password[35];
} SignUp;

SignUp open_sign_up_dialog(GtkWindow *parent)
{

  SignUp result;
  GtkWidget *dialog = gtk_dialog_new_with_buttons("Inscription", parent,
                  GTK_DIALOG_MODAL,GTK_STOCK_OK, GTK_RESPONSE_OK, NULL);

  GtkWidget *table = gtk_table_new(2, 3, FALSE);
  gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG (dialog)->vbox), table);
  gtk_container_set_border_width (GTK_CONTAINER (table), 10);

  GtkWidget *cne = gtk_entry_new();
  GtkWidget *password = gtk_entry_new();
  GtkWidget *confirm = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table), gtk_label_new("CNE"), 0, 1, 0, 1,
                   GTK_SHRINK, GTK_SHRINK, 0, 0);

  gtk_table_attach(GTK_TABLE(table), gtk_label_new("Mot de passe"), 0, 1,
                   1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);

  gtk_table_attach(GTK_TABLE(table), gtk_label_new("Confirmer le mot de "
                   "passe"), 0, 1, 2, 3, GTK_SHRINK, GTK_SHRINK, 0, 0);

  gtk_table_attach(GTK_TABLE(table), cne, 1, 2, 0, 1, GTK_SHRINK,
                   GTK_SHRINK, 0, 0);

  gtk_table_attach(GTK_TABLE(table), password, 1, 2, 1, 2, GTK_SHRINK,
                   GTK_SHRINK, 0, 0);

  gtk_table_attach(GTK_TABLE(table), confirm, 1, 2, 2, 3, GTK_SHRINK,
                   GTK_SHRINK, 0, 0);
  gtk_dialog_run(GTK_DIALOG(dialog));


  gtk_widget_show_all (dialog);

  gtk_widget_destroy(dialog);

  return result;
}

#endif // SIGNUP_FORM_H

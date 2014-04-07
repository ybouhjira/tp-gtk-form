#include "hashtable.h"
#include "file.h"
#include "etudiants.h"
#include <stdio.h>

GHashTable *tableCpge = NULL;
GHashTable *tableDut = NULL;
GHashTable *tableLicence = NULL;

void lire_fichiers_etudiants(GtkWindow *mainWindow)
{
    tableCpge = g_hash_table_new_full(g_str_hash, etudiant_egaux,
                                      NULL, etudiant_detruire);
    tableLicence = g_hash_table_new_full(g_str_hash, etudiant_egaux,
                                         NULL, etudiant_detruire);
    tableDut = g_hash_table_new_full(g_str_hash, etudiant_egaux,
                                     NULL, etudiant_detruire);

    char *diplomes[7] = {
      "cpge", "dut", "deust", "deug", "licence", "master", "maitrise"
    };

    FILE *files[7];
    int i;
    for (i = 0; i < 7; ++i) {
        char filename[30];
        sprintf(filename, "%s.txt", diplomes[i]);
        files[i] = fopen(filename, "w+");

        if(!files[i])
        {
            GtkWidget *errorDialog = gtk_message_dialog_new (
                        GTK_WINDOW(mainWindow),
                        GTK_DIALOG_MODAL,
                        GTK_MESSAGE_ERROR,
                        GTK_BUTTONS_CLOSE,
                        "Impossible d'ouvrir le fichier %s", filename);
            gtk_dialog_run (GTK_DIALOG (errorDialog));
            gtk_widget_destroy (errorDialog);

            return;
        }
    }


    while(fgetc(files[0]) != EOF) // CPGE
    {
        printf("test\n");

        Etudiant *courant = lire_etudiant(files[0]);
        g_hash_table_insert(tableCpge, g_strdup(courant->cne), courant);
    }

    for (i = 1; i <= 3; ++i)
    {
        while(fgetc(files[0]) != EOF) // DUT DEUST DEUG
        {

            Etudiant *courant = lire_etudiant(files[i]);
            g_hash_table_insert(tableDut, g_strdup(courant->cne), courant);
        }
    }

    for (i = 4; i <= 6; ++i)
    {
        while(fgetc(files[0]) != EOF) // Licence master maitrise
        {

            Etudiant *courant = lire_etudiant(files[i]);
            g_hash_table_insert(tableDut, g_strdup(courant->cne), courant);
        }
    }

    for (i = 0; i < 7; ++i)  fclose(files[i]);

}

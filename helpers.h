#ifndef HELPERS_H
#define HELPERS_H

#include <gtk/gtk.h>

#define table_attach(table, widget, left, right, top, bottom) \
    gtk_table_attach(GTK_TABLE(table), widget, left, right, top, bottom,\
    GTK_SHRINK, GTK_SHRINK, 5, 5)

#endif // HELPERS_H

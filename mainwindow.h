#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gtk/gtk.h"

GtkWidget *create_window();

GtkWidget *toolbar_create();

GtkWidget *notebook_create();

GtkWidget *create_welcome_page(GtkWidget *notebook);

#endif // MAINWINDOW_H

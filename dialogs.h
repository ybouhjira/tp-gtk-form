#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <gtk/gtk.h>

typedef struct
{
    char cne[10];
    char password[35];
} SignUp;

SignUp open_sign_up_dialog(GtkWindow *parent);

#endif // SIGNUP_FORM_H

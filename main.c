#include <gnome-keyring.h>
#include <glib.h>
#include <stdio.h>

int main (int argc, char** argv) {
    GnomeKeyringResult result;
    result = gnome_keyring_store_password_sync(
            GNOME_KEYRING_NETWORK_PASSWORD, // Password type
            NULL,                           // Which keyring
            "My test password",             // Description
            "helloWorld",                   // The password
            "user", "james",
            "server", "localhost",
            NULL);
    if (result == GNOME_KEYRING_RESULT_OK) {
        g_print("Successfully stored password to default keyring");
        return 0;
    }    
    else {
        g_print("Failed to store password");
        return 1;
    }
}

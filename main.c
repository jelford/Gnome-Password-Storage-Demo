#include <gnome-keyring.h>
#include <gnome-keyring-memory.h>

#include <glib.h>
#include <stdio.h>

int main (int argc, char** argv) {
    GnomeKeyringResult result;
    gchar* password = gnome_keyring_memory_alloc(8192);
    result = gnome_keyring_store_password_sync(
            GNOME_KEYRING_NETWORK_PASSWORD, // Password type
            NULL,                           // Which keyring
            "My test password",             // Description
            "helloWorld",                   // The password
            "user", "some_user",
            "server", "localhost",
            NULL);
    if (result == GNOME_KEYRING_RESULT_OK) {
        g_print("Successfully stored password to default keyring\n");
        result = gnome_keyring_find_password_sync(
                GNOME_KEYRING_NETWORK_PASSWORD,
                &password,
                "user", "james",
                "server", "localhost",
                NULL);
        if (result == GNOME_KEYRING_RESULT_OK) {
            g_print("Successfully retrived password from memory\n");
            g_print("Password: %s\n", password);
            gnome_keyring_free_password(password);
            return 0;
        } else {
            g_print("Could not get password from memory\n");
            return 1;
        }
    } else {
        g_print("Failed to store password\n");
        return 1;
    }


}

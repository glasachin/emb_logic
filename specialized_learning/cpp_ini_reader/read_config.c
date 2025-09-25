//gcc read_config.c -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
#include <glib.h>
#include <stdbool.h>
#include <glib/gstdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ini_file_path[] = "mb_config.ini";

void print_keys()
{
    
}

void print_groups(char** groups, gsize length) {
    for (gsize i = 0; i < length; i++) {
        printf("Group: %s\n", groups[i]);
    }
}

int main()
{
    GKeyFile* key_file = g_key_file_new();
    GError* error = NULL;
    if (!g_key_file_load_from_file(key_file, ini_file_path, G_KEY_FILE_NONE, &error)) {
        // fprintf(stderr, "[ERROR] Failed to load INI file: %s\n", error->message);
        g_error_free(error);
        return 0;
    }

    // get total groups
    gsize length;
    gchar** groups = g_key_file_get_groups(key_file, &length);
    print_groups(groups, length);

    gchar** Keys = g_key_file_get_keys(key_file, groups[2], &length, &error);
    print_groups(Keys, length);

    gchar* value = g_key_file_get_value(key_file, groups[2], Keys[1], &error);
    printf("Value: %s\n", value);
    return 0;
}



#include "ACE-tools.h"

#include <gtk/gtk.h>
#include <stdlib.h>
#include <libgen.h> // dirname()

GtkBuilder* builderfromfile(char* path) {
	char ui_file_path[256];
	if (readlink("/proc/self/exe", ui_file_path, sizeof(ui_file_path)) == -1) {
		printf("Could not get location of binary. ACE-tools.h 1");
		exit(1);
	}

	dirname(ui_file_path);
	strcat(ui_file_path, "/");
	strcat(ui_file_path, path);
	return gtk_builder_new_from_file(ui_file_path);
}

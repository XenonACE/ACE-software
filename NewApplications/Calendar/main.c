#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h> // dirname()

GtkBuilder* builderfromfile(char* path) {
	char ui_file_path[256];
	if (readlink("/proc/self/exe", ui_file_path, sizeof(ui_file_path)) == -1) {
		printf("Couldn't get location of binary\n");
		exit(1);
	}

	dirname(ui_file_path);
	strcat(ui_file_path, "/");
	strcat(ui_file_path, path);
	return gtk_builder_new_from_file(ui_file_path);
}

int main(int argc, char **argv) {
	GtkWidget *window;

	gtk_init(&argc, &argv);

	GtkBuilder *builder = builderfromfile("layout.glade");

	// Get objects
	window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));

	// Signals
	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h> // dirname()

/* char* componentToHex(int c) {
	char hex[5];
	itoa(c, hex, 10);

	if (CONDITION ) {
		char tmp[2] = '0';
		return strcat(tmp, hex);
	} else {
		return hex;
	}
} */

GtkBuilder* builderfromfile(char* path) {
	char ui_file_path[256];
	if (readlink("/proc/self/exe", ui_file_path, sizeof(ui_file_path)) == -1) {
		printf("could not get locatio of binary");
		exit(1);
	}

	dirname(ui_file_path);
	strcat(ui_file_path, "/");
	strcat(ui_file_path, path);
	return gtk_builder_new_from_file(ui_file_path);
}

static void accentChange(__attribute__((unused)) GtkColorChooser *widget,
			 __attribute__((unused)) gpointer data)
{
	GdkRGBA color;
	gtk_color_chooser_get_rgba(widget, &color);
	//g_print("%s", color);
}

int main(int argc, char **argv) {
	GtkWidget *window;

	GtkWidget *colorpicker;

	gtk_init(&argc, &argv);

	GtkBuilder *builder = builderfromfile("layout.glade");

	// Get objects
	window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));

	colorpicker = GTK_WIDGET(gtk_builder_get_object(builder, "accent"));

	// Signal connects
	g_signal_connect(colorpicker, "color-set", G_CALLBACK(accentChange), NULL);

	// Window close
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

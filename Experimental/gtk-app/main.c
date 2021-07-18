#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

static void quitButtonClicked(__attribute__((unused)) GtkWidget *widget,
			      __attribute__((unused)) gpointer data)
{
	g_print("%s called.\n", __FUNCTION__);
	gtk_main_quit();
}

gboolean windowDelete(__attribute__((unused)) GtkWidget *widget,
		      __attribute__((unused)) GdkEvent *event,
		      __attribute__((unused)) gpointer data)
{
	g_print("%s called.\n", __FUNCTION__);
	return FALSE;
	gtk_main_quit();
	// Returning TRUE doesn't allow the window to close but
	// returning FALSE will
}

int main(int argc, char **argv) {

	FILE *fp;
	char path[1035];

	fp = popen("/bin/uname -r", "r");
	if (fp == NULL) {
		printf("yikes");
		exit(1);
	}

	while(fgets(path, sizeof(path), fp) != NULL) {
		printf("%s", path);
	}

	pclose(fp);

	////////////////////////

	GtkWidget *window;
	GtkWidget *quitBtn;
	GtkBuilder *builder = NULL;


	gtk_init(&argc, &argv);


	builder = gtk_builder_new();

	if (gtk_builder_add_from_file(builder, "layout.glade", NULL) == 0) {
		printf("gtk_builder_add_from_file FAILED\n");
		return(1);
	}

	window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
	quitBtn = GTK_WIDGET(gtk_builder_get_object(builder, "quitBtn"));


	g_signal_connect(quitBtn, "clicked", G_CALLBACK(quitButtonClicked), NULL);
	g_signal_connect(window, "delete_event", G_CALLBACK(windowDelete), NULL);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;

}

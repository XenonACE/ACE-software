#include <gtk/gtk.h>
#include <unistd.h>

void response(__attribute__((unused)) GtkDialog *dialog,
		      __attribute__((unused)) int id,
		      __attribute__((unused)) gpointer data) {

	g_print("%i", id);

	switch(id) {
		case 1: {
				system("sudo shutdown now");
				break;
			}
		case 2: {
				system("sudo reboot");
				break;
			}
		case 3: {
				gtk_main_quit();
				break;
			}
	}
}


int main(int argc, char **argv) {
	gtk_init(&argc, &argv);

	GtkWidget *dialog = gtk_dialog_new_with_buttons(
			"ACE OS Shutdown",	// Title
			NULL,			// Parent Window
			GTK_DIALOG_MODAL,	// Flags
			"_Shutdown",
			1,
			"_Restart",
			2,
			"_Cancel",
			3,
			NULL
		);

	GtkWidget *dialogContent = gtk_dialog_get_content_area(dialog);

	gtk_window_set_gravity(dialog, GDK_GRAVITY_CENTER);
	gtk_window_move(dialog, 0, 0);

	GtkWidget *content = gtk_label_new("Shutdown Options");
	gtk_container_add(GTK_CONTAINER(dialogContent), content);


	g_signal_connect(dialog, "response", G_CALLBACK(response), NULL);
	g_signal_connect(dialog, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(dialog);

	gtk_main();
}

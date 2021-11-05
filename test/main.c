#include <stdio.h>
#include <ACE.h>
#include <ft2build.h>

#include FT_FREETYPE_H

#define error(text) fprintf(stderr, text"\n");

FT_Library	library;
FT_Face		face;

int error = 0;

int initializeFreeType() {
	error = FT_Init_FreeType(&library);
	if (error) {
		fprintf(stderr, "\n");
		error("FreeType Library Initialization Failure! Falling back to X rendering");
	}

	error = FT_New_Face(library, "/usr/share/fonts/montserrat/Montserrat-Regular.ttf", 0, &face);
	if (error == FT_Err_Unknown_File_Format) {
		error("Access to the font file is available, but its format unsupported");
	} else if (error) {
		error("Font file couldn't be read from");
	}

	return error;
}

int main() {
	printKernelVersion();
	initializeFreeType();

	printf("%ld", face->num_glyphs);
}

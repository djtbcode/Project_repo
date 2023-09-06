#include <std.io>
#include <poppler/glib/poppler.h>


int main(int argc, char *argv[])
{
   if (argc != 3) 
   {
        printf("Usage: pdf2doc input.pdf output.doc\n");
        return 1;
   }
   GError *error = NULL;
   PopplerDocument *doc = poppler_document_new_from_file(argv[1], NULL, &error);
   if (error != NULL) 
   {
      printf("Error opening PDF: %s\n", error->message);
      g_error_free(error);
      return 1;
   }

    // Extract text and formatting from the PDF here
    // Create a DOC file and write the extracted content

    poppler_document_free(doc);
    return 0;
}

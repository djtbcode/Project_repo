#include <stdio.h>
#include <stdint.h> 
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
   // OPEN FILE
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exists

    uint8_t buffer[4];
    unint8_t signature[] = {37, 80, 68, 70}
    fread(buffer, 1, 4, file);
    for (int i = 0; i < 4; i++)
    {
        printf("%i", buffer[i]);
    }
    printf("\n");

    for (int x = 0; x < 4; x++)
    {
        if (buffer[x] != signature[x])
        {
            printf("likely not PDF");
            fclose(file);
            return 0;
        }
    }
    printf("likely a PDF! \n")
    fclose(file);
    return 0;

    // Extract text and formatting from the PDF here
    // Create a DOC file and write the extracted content

    poppler_document_free(doc);
    return 0;
}

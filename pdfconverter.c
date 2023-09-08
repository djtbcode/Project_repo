#include <stdio.h>
#include <poppler/glib/poppler.h>
#include <libreofficekit/libreofficekit.h>

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
    if (poppler_document_get_n_pages(doc) > 0) 
    {
        printf("The file is a PDF.\n");
    } 
    else 
    {
        printf("The file is not a valid PDF.\n");
    }
    // Extract text and formatting from the PDF here
   LOKdocument *doc = lok_document_new(lokit, "writer");
   // iterate through pages 
   int pageCount = poppler_get_n_pages(doc);

   for (int i = 0; i < pageCount; i++)
   {
      PopplerPage *page = poppler_document_get_page(PDFDoc, pagenum);
      gchar *text = poppler_page_get_text(page);

      //Put text into new doc
      lok_document_insert_text(doc, text);
      g_free(text);
   }

   //save doc
   lok_document_save_as(doc, docFileName, "doc");

   lok_document_free(doc);
   lok_exit(loKit);
   poppler_document_free(doc);
   
   return 0;
}

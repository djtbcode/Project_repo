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
   const char*pdfFileName = argv[1];
   const char *docFileName = argv[2]; 
   GError *error = NULL;

   if (!poppler_glib_init(&arc, &argv))
   {
      printf("Failed to initialize Poppler.\n");
      return 1;
   }

   
   PopplerDocument *pdfDoc = poppler_document_new_from_file(pdfFileName, NULL, &error);
   if (error != NULL) 
   {
      printf("Error opening PDF: %s\n", error->message);
      g_error_free(error);
      return 1;
   }
   if (poppler_document_get_n_pages(doc) <= 0) 
   {
      printf("The file is not a valid PDF.\n");
      return 1;
   }

   //Initialise Libre Office Kit
   LOKInstance *lokit = lok_init(NULL, "lokit_server, NULL);
   if (!lokit)
   {
      printf("Failed to initilise Libre Office Kit.\n");
      return 1;
   }
   //creat .doc document
   LOKdocument *doc = lok_document_new(lokit, "writer");
   // iterate through pages 
   int pageCount = poppler_get_n_pages(doc);

   for (int pageNum = 0; i < pageCount; pageNum++)
   {
      PopplerPage *page = poppler_document_get_page(pdfDoc, pageNum);
      gchar *text = poppler_page_get_text(page);

      //Put text into new doc
      lok_document_insert_text(doc, text);
      g_free(text);
   }

   //save .doc file
   lok_document_save_as(doc, docFileName, "doc");

   lok_document_free(doc);
   lok_exit(loKit);
   poppler_document_free(doc);
   
   return 0;
}

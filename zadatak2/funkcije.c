#include "funkcije.h"

void printToFile(student* student) {
   char filename[40];
   snprintf(filename, sizeof(filename), "%s_%s.txt", student->Godina, student->Oblast);

   FILE *file = fopen(filename, "w");
   if (file == NULL) {
       perror("Problem pri otvaranju fajla");
       exit(EXIT_FAILURE);
   }

   fprintf(file, "Ime: %s\n", student->Ime);
   fprintf(file, "Prezime: %s\n", student->Prezime);
   fprintf(file, "Godiste: %d\n", student->Godiste);
   fprintf(file, "Srednja skola: %s\n", student->Srednja_skola);
   fprintf(file, "Godina: %s\n", student->Godina);
   fprintf(file, "Oblast: %s\n", student->Oblast);
   fprintf(file, "Broj poena: %d\n", student->Broj_poena);

   fclose(file);
}
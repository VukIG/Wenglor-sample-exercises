#include "funkcije.h"

void printToFile(student* student, int studNum) {
    for (int i = 0; i < studNum; i++)
    {
        char filename[40];
        snprintf(filename, sizeof(filename), "%s_%s.txt", student[i].Godina, student[i].Oblast); //bug sa IIIMATEMATIKA_MATEMATIKA
        printf("%s",student[i].Godina);
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
            perror("Problem pri otvaranju fajla");
            exit(EXIT_FAILURE);
        }   
        else{
            fprintf(file,"Ucenik broj %d\n", i-1);//potencijalni bug
            fprintf(file, "Ime: %s\n ", student[i].Ime);
            fprintf(file, "Prezime: %s\n ", student[i].Prezime);
            fprintf(file, "Godiste: %d\n ", student[i].Godiste);
            fprintf(file, "Srednja: %s\n ", student[i].Srednja_skola);
            fprintf(file, "Poeni: %.2f\n ", student[i].Broj_poena);
            fprintf(file,"\n");
            fclose(file);

        }
    }

}
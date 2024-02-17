#include "funkcije.h"

void swap(student *a,student *b){
    student c = *a;
    *a = *b;
    *b = c;
}

int partition(student student[], int min, int max) {
    
    int pivot = student[max].Broj_poena;

    int i = min - 1;
    for (int j = min; j < max; j++) {
        if (student[j].Broj_poena >= pivot) {
        i++;
        swap(&student[i], &student[j]);
        }
    }
    
    swap(&student[i + 1], &student[max]);
    return (i + 1);
}

//quicksort po bodovima
void sortByPoints( student* student, int min, int max){
    if ( min < max )
    {
        int pivot = partition(student,min,max);
        sortByPoints(student, min, pivot-1);
        sortByPoints(student, pivot + 1, max);
    }
    
}

void printToFile(student* student, int studNum) {
    sortByPoints(student, 0, studNum - 1);
    for (int i = 0; i < studNum; i++)
    {
        char filename[40];
        if (strcmp(student[i].Godina,"")!=0 || strcmp(student[i].Oblast,"")!=0)
        {
            snprintf(filename, sizeof(filename), "%s_%s.txt", student[i].Godina, student[i].Oblast); //bug sa IIIMATEMATIKA_MATEMATIKA
            printf("%s",student[i].Godina);
            FILE *file = fopen(filename, "a");
            if (file == NULL) {
                perror("Problem pri otvaranju fajla");
                exit(EXIT_FAILURE);
            }   
            else{
                fprintf(file,"Ucenik broj %d\n", i);//potencijalni bug
                fprintf(file, "Ime: %s\n ", student[i].Ime);
                fprintf(file, "Prezime: %s\n ", student[i].Prezime);
                fprintf(file, "Godiste: %d\n ", student[i].Godiste);
                fprintf(file, "Srednja: %s\n ", student[i].Srednja_skola);
                fprintf(file, "Poeni: %.2f\n ", student[i].Broj_poena);
                fprintf(file,"\n");
                fclose(file);

            }
        }
        else{
            printf("GOTOVO");
        }
        
    }

}
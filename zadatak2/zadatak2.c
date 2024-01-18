#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

int main(int argc, char const *argv[])
{   
    int studNum = 1;
    int order=1;
    char userInput[100];
    char *input = fgets(userInput,sizeof(userInput),stdin);
    student* students = malloc(sizeof(student));
    while ( input != NULL )
    {
        char *prt = strtok(userInput," ");
        while (prt != NULL) {
            switch ( order )
            {
            case 1:
                strcpy(students[studNum].Ime, prt);
                break;
            case 2:
                strcpy(students[studNum].Prezime, prt);
                break;
            case 3:
                students[studNum].Godiste = atoi(prt);
                break;
            case 4:
                strcpy(students[studNum].Srednja_skola, prt);
                break;
            case 5:
                strcpy(students[studNum].Godina, prt);
                break;
            case 6:
                strcpy(students[studNum].Oblast, prt);
                break;
            case 7:
                students[studNum].Broj_poena = atoi(prt);
                break;
            
            default:
                break;
            }
            order++;        
            prt = strtok(NULL, " ");
        }
        printToFile(&students[studNum]);
        input = fgets(userInput,sizeof(userInput),stdin);
        students = realloc(students, sizeof(student)*(studNum+1));
        studNum++;//Bug?
    }

    free(students);
    free(input);

    return 0;
}

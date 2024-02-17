#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

int main(int argc, char const *argv[])
{   
    int studNum = 0;
    char userInput[100];
    student* students = NULL;
    while ( fgets(userInput,sizeof(userInput),stdin))
    {
        int len = strlen(userInput);
        if (len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
            students = realloc(students, sizeof(student)*(++studNum));
        }
        if (strcmp(userInput,"---")==0)
        {
            printToFile(students,studNum);
            break;
        }
        
        int order = 1;
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
            case 5://zasto
                if ( strcmp(prt,"I") == 0 || strcmp(prt,"II") == 0 || strcmp(prt,"III") == 0 || strcmp(prt,"IV") == 0 )
                {
                    strcpy(students[studNum].Godina, prt);
                }
                else
                {
                    printf("Za godinu neophodno je uneti I,II,III ili IV");
                }
                break;
            case 6:
                if (strcmp(prt,"Biologija") == 0 || strcmp(prt,"Matematika") == 0 || strcmp(prt,"Fizika") == 0 || strcmp(prt,"Hemija"))
                {
                    strcpy(students[studNum].Oblast, prt);
                }
                else
                {
                    printf("Ne vazeca oblast, unesite Biologija, Matematika, Fizika ili Hemija");                        
                }            
                break;
            case 7:
                if (atof(prt)>100 || atof(prt)<0)
                {
                    printf("Unesite broj bodova izmedju 0 i 100");
                }
                else
                {
                    students[studNum].Broj_poena = atof(prt);
                }
                break;                
            default:
                break;
            }
            order++;        
            prt = strtok(NULL, " ");
        }
    }
    free(students);
    return 0;
}
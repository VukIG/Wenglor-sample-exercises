
#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char Ime[20];
    char Prezime[20];
    int Godiste;
    char Srednja_skola[50];
    char Godina[3];
    char Oblast[10];
    int Broj_poena;
} student;

//Kompilacija zavisi od sistema
//Sistem koji je koristen za pravljenje i kompajlovanje ovog koda je Linux, za Windows korisnike
//#if defined(_WIN32) || defined(__WIN32__) i #endif na kraju
void printToFile(student* student);


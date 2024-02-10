#include "funkcije.h"

float aritmethic( int *numbers, int count)
{
   float result = 0.0;
   for (int i = 0; i < count; ++i) {
       result += numbers[i];
   }
   return result / count;
}


float geometric( int *numbers, int count)
{
    int result = 1;
    for (int i = 0; i < count; i++) {
        result *= numbers[i];
    }
    float tmp = 1.0 / count;
    return pow( tmp, result ); //sopstvena root funkcija pow zaokruzuje na dve decimale
}

float harmonic( int *numbers, int count)
{
    printf("%d",count);
    float result = 0.0;
    for (int i = 0; i < count; ++i) {
        result += 1.0 / numbers[i];
    }
    return count / result;
}

float calculateResult(int *numbers, int count, char operation) 
{
    printf("%c",operation);
    switch (operation) {
    case 'a':
        return aritmethic(numbers, count);
        break;
    case 'g':
        return geometric(numbers, count);
        break;
    case 'h':
        return harmonic(numbers, count);
        break;
    default:
        printf("Invalid operation\n");
        exit(EXIT_FAILURE);
    }
}

int* convertToInteger(char *line, int *len) 
{
    int *numbers = malloc(sizeof(int) * (*len));
    int numbersSize = 0;
    char *ptr = strtok(line, " ");

    while (ptr != NULL) {
        numbers[numbersSize++] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }
    *len = numbersSize;
   return numbers;
}


void printResultToFile(float result) 
{
    
    FILE *file = fopen("Rezultat.txt", "w");
    if (file == NULL) {
        perror("Problem pri otvaranju fajla");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%.3f\n", result);
    fclose(file);
}
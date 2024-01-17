#include "funkcije.h"

float aritmethic( int *numbers, int count, char operation)
{
    float result = 0.0;
    for (int i = 0; i < count; ++i) {
        result += numbers[i];
    }
    return result /= count;
}

float geometric( int *numbers, int count, char operation)
{
    float result = 1.0;
    for (int i = 0; i < count; ++i) {
        result *= numbers[i];
    }
    return pow(result, 1.0 / count);
}

float harmonic( int *numbers, int count, char operation)
{
    float result = 0.0;
    for (int i = 0; i < count; ++i) {
        result += 1.0 / numbers[i];
    }
    return count / result;
}

float calculateResult(float *numbers, int count, char operation) {
    switch (operation) {
    case 'a':
        return aritmethic(numbers, count, operation);
        break;
    case 'g':
        return geometric(numbers, count, operation);
        break;
    case 'h':
        return harmonic(numbers, count, operation);
        break;
    default:
        printf("Invalid operation\n");
        exit(EXIT_FAILURE);
    }
}

char* convertToInteger(char *line) {
    
    int num, i = 0, len;
    while (sscanf(line, "%d%n", &num, &len) == 1) {
        printf("Number %d is %d\n", i, num);
        line = realloc(line,sizeof(line)+sizeof(len));
        i++;
        line[i]=num;
    }
    return line;
}

void printResultToFile(float result) {
    
    FILE *file = fopen("Rezultat.txt", "w");
    if (file == NULL) {
        perror("Problem pri otvaranju fajla");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%f\n", result);
    fclose(file);
}
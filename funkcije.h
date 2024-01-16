#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <stdio.h>  
#include <stdlib.h>
#include <math.h>

float calculateResult(float *numbers, int count, char operation);
char* convertToInteger(char *line);
void printResultToFile(float result);
float aritmethic(int *numbers, int count, char operation);
float geometric(int *numbers, int count, char operation);
float harmonic(int *numbers, int count, char operation);

#endif
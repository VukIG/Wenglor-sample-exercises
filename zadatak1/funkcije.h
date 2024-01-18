#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

float calculateResult(int *numbers, int count, char operation);
int* convertToInteger(char *line, int *len);
void printResultToFile(float result);
float aritmethic(int *numbers, int count, char operation);
float geometric(int *numbers, int count, char operation);
float harmonic(int *numbers, int count, char operation);

#endif
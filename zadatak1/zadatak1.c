#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funkcije.h"
#include <string.h>

int main() {

    int BUFFER_SIZE = 2;
    int count = 0;
    float *numbers = NULL;
    char method[11];
    printf("Unos: ");

    int ch;
    float result;
    int index = 0;
    char avgType;
    int len = 0;
    char* input=(char*)malloc(sizeof(char));
    int a[len];
    while(1) {
        ch = getchar();
        if (len == 0 && !isdigit(ch))
        {
            printf("Neophodan je unos celobrojnog niza");
            break;
        }
        if (isdigit(ch))
        {
            input=(char*)realloc(input,sizeof(char)*(len+1));
            input[len]=ch;
            len++;
        }
        else if (ch != 'a' || ch != 'g' || ch != 'h')
        {
            float result;
            char t=fgets(method,12,stdin);
            if (strcmp(method,"ritmeticka"))
            {
                input = convertToInteger(input);
                result = aritmethic(input,len,ch);
            }
            else if(strcmp(method,"eometrijska"))
            {
                input = convertToInteger(input);                
                result = geometric(input,len,ch);
            }
            else if(strcmp(method,"armonijska"))
            {
                input = convertToInteger(input);
                result = harmonic(input,len,ch);
            }
            else if( t == NULL ){
                result = calculateResult(input,len,ch);
            }
            else{
                printf("Nevazeca metoda");
                break;
            };
        }
        else{
            printf("Sta si ti uneo sine moj?!");
            break;
        };
        len++;
    }

    printf("%s","MOMIR19");
    printResultToFile(result);
    printf("Rezultat uspesno upisan u Rezultat.txt !");

    free(numbers);
    free(input);
    return 0;
}

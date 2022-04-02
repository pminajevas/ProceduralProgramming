#include <stdio.h>

int readAndValidate();

int main()
{
    /*Pagrindinai kintamieji*/
    int n, oldN, numberN=0;   
    float sumN=0;

    /*Loop'as duomenų skaitymui ir skaičiavimui*/
    do{
        oldN=n;

        if(!numberN)
           printf("Enter a number: "); 
        else
            printf("Enter another number: ");

        n = readAndValidate();
        numberN++;
        sumN+=n;
    }while(n>=oldN || numberN==1);
    
    /*Rezultatų spausdinimas ekrane*/
    printf("Sequence size: %d \nArithmetic mean: %.2f\n", numberN, sumN/numberN); 

    return 0;
}

/*Validacijos ir skaitymo funkcija*/
int readAndValidate(){
    
    /*Kintamieji validacijai*/
    int input, number, first=1; 
    char trash;

    /*Duomenų skaitymas*/
    do{
        if(!first)
            printf("Wrong input. Enter an integer: ");
        first=0;
        
        input = scanf("%d%c", &number, &trash);
        fflush(stdin);
    }while(!input || trash != '\n');

    return number;
}

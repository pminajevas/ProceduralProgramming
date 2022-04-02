#include <stdio.h>

/* Defining UI messages */
#define wrongInput "Wrong input. Try again:"
#define enterNext "Numbers left to enter %d. Go on:"
#define maxSize 100

/* Declaration of functions */
int OneNumberReadAndValidate();
int ManyNumbersReadAndValidate(int index);
void FindCoordinates(int column, int size, int matrix[maxSize][maxSize], int *minColumn, int *minRow, int *maxColumn, int *maxRow, int *maxValue, int *minValue);

int main(){
    int size, matrix[maxSize][maxSize], row, column;
    /* User Interface */ 
    printf("This program will find the lowest and higest values in matrix row.\nAfter that it will print it on the screen\n");
    printf("Enter only one positive whole number, that is not bigger than 10:");
    /* Reading and Validating the first number */
    size = OneNumberReadAndValidate();
    /* User Interface */
    printf("Now enter %d number(s), that are no longer than 8 digits:", size * size);
    /* Loop to get all numbers that fill the matrix */
    for(row = 0; row < size; ++row){
        for(column = 0; column < size; column++){
           matrix[row][column] = ManyNumbersReadAndValidate(size*size - ((size * row) + column));
        }
    }
    /* Loop to find lowest and highest numbers in each column and then print them*/
    for(column = 0; column < size; ++column){
        int minColumn, minRow, maxColumn, maxRow, maxValue, minValue;
        FindCoordinates(column, size, matrix, &minColumn, &minRow, &maxColumn, &maxRow, &maxValue, &minValue);
        printf("%d row: ", column+1);
        printf("minimum %d: (%d ; %d) maximum %d: (%d ; %d)\n", minValue, minRow, minColumn, maxValue, maxRow, maxColumn);
    }
    
    return 0;
}

/* Function that reads and validates one number input */
int OneNumberReadAndValidate(){
    while(1){
        int number;
        char trash;
        /* Reading user input and checking if it is correct, if a problem was found the buffer gets cleaned off trash characters */
        if(scanf("%d%c", &number, &trash) != 2 || (trash != '\n' && trash != ' ' && trash != '\t') || number > 10 || number < 0){ 
            if(trash!='\n'){                                                                                                          
                scanf("%*[^\n]");
            }
            printf(wrongInput);
        /* If input was correct function returns the value also checks for White-Space and whether unnecessary characters were inputed */
        }else if (trash == '\n'){                                                                                                       
            return number;
        }else{                                                                                                                          
            scanf("%*[ \t]");
            scanf("%c", &trash);
            if(trash == '\n'){
                return number;
            }
            else{
                printf(wrongInput);
                scanf("%*[^\n]");
            }
        }
    }
}

/* Function that reads and validates list of inputs */
int ManyNumbersReadAndValidate(int index){

    int firstLoop = 1;
    int number;
    char trash;
    while(1){
        /* Checks if it is the first reading if not it removes unnecesary characters and if the last character is newline prints further instructions */
        if(!firstLoop){                                                                                                                                                                                             
            scanf("%*[ \t]");                                                                                                            
            scanf("%c", &trash);
            if(trash == '\n'){
                printf(enterNext, index);
            }else if (trash != ' ' && trash != '\t'){
                ungetc(trash, stdin);
            }
        }
        firstLoop = 0;
        /* Reading of numbers and checking if the input is correct */
        if(scanf("%8d%c", &number, &trash) != 2 || (trash != '\n' && trash != ' ' && trash != '\t')){                    
            scanf("%*[^\t \n]");
        }else{
            if(trash == '\n' && index == 1){
                printf("All numbers entered succesfully, here are the results:\n");
            }else if(trash == '\n'){
                printf(enterNext, index-1);
        /* If Input was correct sends the value back to main and checks whether it was the last character and if it is prints further instructions */
            }else{                                                                                                                      
                scanf("%*[ \t]");                                                                                                       
                scanf("%c", &trash);
                if(trash == '\n'){
                    printf(enterNext, index-1);
                }else{
                    ungetc(trash, stdin); 
                }
                
            }
            return number;
        }
    }
}

/* Function that finds coordinates of the lowest and highest values in a matrix row */
void FindCoordinates(int column, int size, int matrix[maxSize][maxSize], int *minColumn, int *minRow, int *maxColumn, int *maxRow, int *maxValue, int *minValue){
    int row = 0, value;
    /* Declaring the lowest value as the first element of the row */
    *minValue = matrix[column][row];                                                                                                
    *minRow = column;
    *minColumn = row;
    /* Declaring the highst value as the first element of the row */
    *maxValue = matrix[column][row];                                                                                                
    *minRow = column;
    *minColumn = row;
    for(row = 0; row < size; ++row){
        value = matrix[column][row];
        /* Comparing minimum value with current and if it is lower it makes the current value, minimum value */
        if(*minValue > value){                                                                                                           
            *minValue = value;                                                                                                          
            *minColumn = row;
            *minRow = column;
        }
        /* Comparing highest value with current and if it is higher it makes the current value, highest value */
        if(*maxValue < value){                                 
            *maxValue = value;                                                                                                          
            *maxColumn = row;
            *maxRow = column;
        }
    }
}


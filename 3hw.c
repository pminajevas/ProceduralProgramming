#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256
#define FIRST_SYMBOL '!'
#define LAST_SYMBOL '~'

void searchForPalindromesInLine(char line[], char **palindromes, int *currentDynamicSize);

int main(int argc, char* argv[]){
    /*Pointers to file and names from parameteres*/
    FILE *inputFile, *outputFile;
    char *inputFileName = argv[1];
    char *outputFileName = argv[2];

    /*Declaration of lineLength*/
    unsigned int lineLength;

    /*Dynamic array*/
    char *palindromes;
    int currentDynamicSize = MAX_LENGTH;
    palindromes = (char *) malloc(MAX_LENGTH);

    /*Opening input and creating output files*/
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");
    /*Checking if there weren't any errors opening file*/
    if(inputFile != NULL){
        char line[MAX_LENGTH];
        /*While not end of file read text*/
        while(!feof(inputFile)){
            fgets(line, MAX_LENGTH , inputFile);
            lineLength = strlen(line);
            /*If more than 255 characters in line skipping them*/
            if(line[lineLength-1] != '\n' && !feof(inputFile)){
                char trash;
                do{
                    trash = fgetc(inputFile);
                }while(!feof(inputFile) && trash != '\n');
            }
            searchForPalindromesInLine(line, &palindromes, &currentDynamicSize);
        }
        if(outputFile != NULL){
            /*Creating output file and printing palindromes to it*/
            fputs(palindromes, outputFile);
            free(palindromes);
            fclose(outputFile);
            printf("Program finished succesfully. Results printed in %s", outputFileName);
        }else{
            /*Printing error message*/
            printf("Could not create result's file\n");
        }
        /*Closing input file*/
        fclose(inputFile);
    }else{
        /*Printing error message*/
        printf("Could not open file. Check if you entered the name correctly and created an input file\n");
    }
    return 0;
}

void searchForPalindromesInLine(char line[], char **palindromes, int *currentDynamicSize){

    char string[MAX_LENGTH];
    char reverseString[MAX_LENGTH];
    int currentLength = 0, i, j;

    /*Looping all characters of the line*/
    for(i = 0; i <= strlen(line); ++i){

        /*If character found adding it to the string*/
        if(line[i] >= FIRST_SYMBOL && line[i] <= LAST_SYMBOL){
            string[currentLength] = line[i];
            currentLength++;
        }

        /*If no character found checking the string if it is palindrome*/
        if(i > 0 && (line[i] < FIRST_SYMBOL || line[i] > LAST_SYMBOL) && (line[i-1] != ' ' || line[i-1] != '\t')){

            if(currentLength){
                /*Reversing the string*/
                for(j = 0; j < currentLength; ++j){
                    reverseString[currentLength-j-1] = string[j];
                }

                /*Adding string space and terminator to the end of it*/
                reverseString[currentLength] = ' ';
                string[currentLength] = ' ';
                currentLength++;
                reverseString[currentLength] = '\0';
                string[currentLength] = '\0';

                /*Comparing reversed string with string*/
                if(!strcmp(string, reverseString)){
                    /*If not enough size in array reallocating it*/
                    if(strlen(*palindromes) + currentLength > *currentDynamicSize){
                        *currentDynamicSize += MAX_LENGTH;
                        *palindromes = (char *) realloc(*palindromes, *currentDynamicSize);
                    }
                    /*Copying string to array*/
                    strcat(*palindromes, string);
                }
            }
            currentLength = 0;
        }
    }
}
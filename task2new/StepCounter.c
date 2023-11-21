#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
FITNESS_DATA data[100];
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }



int createStruct(errorvalue)
{
    char date[11];
    char time[6];
    int steps;
    int count = 0;
    return 0;
}

// Complete the main function
int main() 
{
    int errorvalue = 0;
    int recordcount = 0;
    char userinput[];
    char filename[25];

    while (errorvalue == 0)
    {
        printf("A: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nFind the mean step count of all the records in the fileFind the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter input choice: ");        
        scanf(" %c", &userinput);

        switch (userinput)
        {
            case 'A':
            case 'a':
                printf("Input filename: \n");
                scanf("%s", filename);

        }
    }
    
    if (errorvalue == 0)
    {
        printf("Error: Invalid file\n");
        return 1;
    }
    return 0;
}










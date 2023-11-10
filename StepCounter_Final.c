#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
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




// Complete the main function
int main() 
{
    char userinput;
    char filename[25];
    int running = 1;
    FITNESS_DATA data_array[100];

    char date[11];
    char time[6];
    char steps[10];
    char delimiter[2] = ",";
    int count = 0;

    int buffer_size = 1024;
    char line_buffer[buffer_size];

    while(running == 1)
    {
        printf(" \n");
        printf("A: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        printf("Enter input choice: ");
        scanf("%c", &userinput);
    
        switch(userinput)
        {
            case 'A':  
                printf("Input filename: ");
                scanf("%s", filename);
                char data[25];
                strcpy(data, filename);
                FILE *file = fopen(data, "r");
                if (file == NULL)
                {
                    perror("Error: Could not find or open file");
                    return 1;
                }
                else
                {
                    printf("File successfully loaded.\n");
                    while (fgets(line_buffer, buffer_size, file) != NULL)
                        {
                            tokeniseRecord(line_buffer, delimiter, date, time, steps);
                            strcpy(data_array[count].date, date);
                            strcpy(data_array[count].time, time);
                            data_array[count].steps = atoi(steps);
                            count ++;
                        }
                }
            break;
            
            case 'B':
                printf("Total records: %d", count);
            break;

            case 'c':
                feweststeps(data_array, count);
            break;

            case 'Q': 
                running = 0;
            break;
            
            default: printf("--------------\n");
            break;
        }
    }

    return 0;
   
}










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


void feweststeps(FITNESS_DATA data[100], int count)
{
	int least;
    least = data[0].steps;
    int returnrecord = 0;

	for (int i = 0; i < count; i++)
	{
        if (data[i].steps < least)
        {
            least = data[i].steps;
            returnrecord = i;
        }
    }
    printf("Fewest steps: %s %s\n", data[returnrecord].date, data[returnrecord].time);	
}

void largeststeps(FITNESS_DATA data[100], int count)
{
	int most;
    most = data[0].steps;
    int returnrecord = 0;

	for (int i = 0; i < count; i++)
	{
        if (data[i].steps > most)
        {
            most = data[i].steps;
            returnrecord = i;
        }
    }
    printf("Largest steps: %s %s\n", data[returnrecord].date, data[returnrecord].time);	
}

void meansteps(FITNESS_DATA data[100], int count)
{
	float mean;
    int total = 0;

	for (int i = 0; i < count; i++)
	{
        total += data[i].steps;
    }
    mean = total/count;
    printf("Mean step count: %0.1f\n", mean);	
}

void longestperiod(FITNESS_DATA data[100], int count)
{
	int startrecord = 0;
    int endrecord = 0;
    int tracking = 0;
    int longestnum = 0;
    int currentnum = 0;
    int currentstart = 0;
    int currentmax = 0;

	for (int i = 0; i <= count; i++)
	{
        printf("%d ", i);
        if (data[i].steps > 500)
        {
            if (tracking == 0)
            {
                printf("Begin tracking ");
                tracking = 1;
                currentstart = i;
                currentnum += 1;
            }

            else if (data[i].steps < 500 && tracking == 1) //------------------------------------------
            {
                printf("End tracking ");
                if ( i-1 < 0)
                {
                    currentmax = 0;
                }
                else
                {
                    currentmax = i-1;
                }

                if (tracking == 1 && currentnum > longestnum)
                {
                    longestnum = currentnum;
                    startrecord = currentstart;
                    endrecord = currentmax;
                }

                tracking = 0;
                currentnum = 0;
            }

            else
            {
                printf("Update counter ");
                currentnum += 1;
            }
        }
    }

    printf("Longest period start: %s %s\n", data[startrecord].date, data[startrecord].time);
    printf("Longest period end: %s %s\n", data[endrecord].date, data[endrecord].time);	
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
        printf("A: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        printf("Enter input choice: ");
        scanf(" %c", &userinput);
    
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
                    printf("Error: Could not open file\n");
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
                getchar();
            break;
            
            case 'B':
                printf("Total records: %d\n", count);
            break;

            case 'C':
                feweststeps(data_array, count);
            break;

            case 'D':
                largeststeps(data_array, count);
            break;

            case 'E':
                meansteps(data_array, count);
            break;

            case 'F':
                longestperiod(data_array, count);
            break;

            case 'Q': 
                running = 0;
            break;
            
            default: printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
   
}










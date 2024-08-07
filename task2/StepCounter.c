#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

int datasize = 200;

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

void feweststeps(FITNESS_DATA data[datasize], int count)
{
    int least = data[0].steps;
    int leastrec = 0;

    for (int i = 0; i < count; i++)
    {
        if (data[i].steps < least)
        {
            least = data[i].steps;
            leastrec = i;
        }
    }

    printf("Fewest steps: %s %s\n", data[leastrec].date, data[leastrec].time);
}

void largeststeps(FITNESS_DATA data[datasize], int count)
{
    int max = 0;
    int maxrecord = 0;

    for (int i = 0; i < count; i++)
    {
        if (data[i].steps > max)
        {
            max = data[i].steps;
            maxrecord = i;
        }
    }
    printf("Largest steps: %s %s\n", data[maxrecord].date, data[maxrecord].time);
}

void meansteps(FITNESS_DATA data[datasize], int count)
{
    float mean;
    int total = 0;

    for (int i = 0; i < count; i++)
    {
        total += data[i].steps;
    }
    mean = (float)total / count;
    int intmean = (int)(mean + 0.5);

    printf("Mean step count: %d\n", intmean);
}

void longestperiod(FITNESS_DATA data[datasize], int count)
{
    int startrecord = 0;
    int endrecord = 0;
    int tracking = 0;
    int longestnum = 0;
    int currentnum = 0;
    int currentstart = 0;
    int currentmax = 0;

    for (int i = 0; i < count; i++)
    {
        if (data[i].steps > 500)
        {
            if (tracking == 0)
            {
                tracking = 1;
                currentstart = i;
                currentnum += 1;
            }

            else if (tracking == 1)
            {
                currentnum += 1;
            }
        }

        else if (data[i].steps < 500 && tracking == 1)
        {
            currentmax = i - 1;

            if (tracking == 1 && currentnum > longestnum)
            {
                longestnum = currentnum;
                startrecord = currentstart;
                endrecord = currentmax;
            }

            tracking = 0;
            currentnum = 0;
        }
    }

    printf("Longest period start: %s %s\n", data[startrecord].date, data[startrecord].time);
    printf("Longest period end: %s %s\n", data[endrecord].date, data[endrecord].time);
}

// Complete the main function
int main()
{
    char userinput;
    char filename[50];
    int running = 1;
    int fileopened = 0;
    FITNESS_DATA data_array[datasize];

    char date[11];
    char time[6];
    char steps[10];
    char delimiter[2] = ",";
    int count = 0;

    int buffer_size = 1024;
    char line_buffer[buffer_size];

    while (running == 1)
    {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter input choice: ");
        scanf(" %c", &userinput);

        switch (userinput)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);
            char data[50];
            strcpy(data, filename);
            FILE *file = fopen(data, "r");
            if (file == NULL)
            {
                printf("Error: Could not open file\n");
                return 1;
            }
            else
            {
                fileopened = 1;
                printf("File successfully loaded.\n");
                while (fgets(line_buffer, buffer_size, file) != NULL)
                {
                    tokeniseRecord(line_buffer, delimiter, date, time, steps);
                    strcpy(data_array[count].date, date);
                    strcpy(data_array[count].time, time);
                    data_array[count].steps = atoi(steps);
                    count++;
                }
            }
            fclose(file);
            getchar();

            /*
            for (int i = 0; i < count; i++)
            {
                printf("%s %s %d\n", data_array[i].date, data_array[i].time, data_array[i].steps);
            }
            */

            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", count);
            break;

        case 'C':
        case 'c':
            feweststeps(data_array, count);
            break;

        case 'D':
        case 'd':
            largeststeps(data_array, count);

            break;

        case 'E':
        case 'e':
            meansteps(data_array, count);

            break;

        case 'F':
        case 'f':
            longestperiod(data_array, count);
            break;

        case 'Q':
        case 'q':
            // return 0;
            running = 0;
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

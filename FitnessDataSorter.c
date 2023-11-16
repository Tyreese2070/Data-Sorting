#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() 
{
    int count = 0;
    FITNESS_DATA data_array[100];
    char filename[25];
    char date[11];
    char time[6];
    char steps[10];

    int buffer_size = 1024;
    char line_buffer[buffer_size];
    
    printf("Enter filename: ");
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

    return 0;
    
}
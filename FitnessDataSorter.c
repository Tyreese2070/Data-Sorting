#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int length(char string)
{
    int count = 0;
    while (string[i] != "/0")
    {
        count ++
    }
    count ++;
    return count
}

int getdata(char filename[15], char mode[2])
{
    FitnessData data_array[100];
    char data[25];
    char date[11];
    char time[6];
    int count = 0;
    int steps;
    //char delimiter = ",";
    int buffer_size = 1024;
    char line_buffer[buffer_size];

    strcpy(data, filename);
    FILE *file = fopen(data, mode);
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }
    else
    {
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            tokeniseRecord(filename, ",", date, time, steps);
            //if (data_array[count].date != length(data_array[count].date))
            strcpy(data_array[count].date, date);
            strcpy(data_array[count].time, time);
            strcpy(data_array[count].steps, steps);
            count ++;
        }
    }
    return 0, count;

    //return data_array;
}

/*
struct bubbleSort(struct data, int count)
{
    char temptime;
    char tempdate;
    int tempsteps;
    char temp;
    for (i = 0; i < count; i++)
    {
        for (j = 0; i < count, i++)
        {
            if (data[j].steps > data[j+1].steps)
            {
                data[j] = temp;
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
*/

int main() 
{
    FitnessData data_array[100];
    int recordcount;
    int fileread;
    char filename[15];
    printf("Input filename: ");
    scanf("%s", filename);
    fileread, recordcount = getdata(filename, "r");
    if (fileread == 1)
    {
        return 1;
    }

    //data_array[100] = bubbleSort(data_array, recordcount);
    return 0;
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

FitnessData data_array[100];

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

int getdata(char filename[30], char mode[2])
{
    //FitnessData data_array[100];
    char data[30];
    char date[11];
    char time[6];
    int count = 0;
    int steps;
    int buffer_size = 1024;
    char line_buffer[buffer_size];

    // Opening the file
    strcpy(data, filename);
    FILE *file = fopen(data, mode);
    if (file == NULL)
    {
        //printf("Error: Could not open file\n");
        return -1;
    }
    else

    // Reading from the file and adding it to the array
    {
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        tokeniseRecord(line_buffer, ',', date, time, &steps);
            strcpy(data_array[count].date, date);
            strcpy(data_array[count].time, time);
            data_array[count].steps = steps;

            if (strlen(data_array[count].date) != 10 || strlen(data_array[count].time) != 5 || data_array[count].steps <= 0)
            {
            printf("%ld %ld %d\n", strlen(data_array[count].date), strlen(data_array[count].time), data_array[count].steps);
            return -1;
            }
            count ++;
        }
        fclose(file);

    }
    return count;
}

// Bubble sort function in descending order
void bubble_sort(FitnessData data_array[], int recordcount)
{
    char temptime[6] = "";
    char tempdate[11] = "";
    int tempsteps;
    for (int i = 0; i < recordcount - 1; i++)
    {
        for (int j = 0; j < recordcount - i - 1; j++)
        {
            if (data_array[j].steps < data_array[j + 1].steps)
            {
                // Swapping time
                strcpy(temptime, data_array[j].time);
                strcpy(data_array[j].time, data_array[j+1].time);
                strcpy(data_array[j+1].time, temptime);

                // Swapping dates
                strcpy(tempdate, data_array[j].date);
                strcpy(data_array[j].date, data_array[j+1].date);
                strcpy(data_array[j+1].date, tempdate);

                // Swapping Steps
                tempsteps = data_array[j].steps;
                data_array[j].steps = data_array[j+1].steps;
                data_array[j+1].steps = tempsteps;
            }
        }
    }
}

int main() 
{
    //FitnessData data_array[100];
    int recordcount;
    char filename[30];

    // Getting the users filename and adding it to an array
    printf("Input filename: ");
    scanf("%s", filename);
    recordcount = getdata(filename, "r");

    // Returning an error if given filename isn't valid
    if (recordcount == -1)
    {
        printf("Error: Invalid File\n");
        return 1;
    }

    // Printing sorted array
    bubble_sort(data_array, recordcount);
    strcat(filename, ".tsv");

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    for (int i = 0; i < recordcount; i++)
    {
        fprintf(file, "%s\t%s\t%d\n", data_array[i].date, data_array[i].time, data_array[i].steps);
    }
    fclose(file);

    printf("Data sorted and written to: %s\n", filename);

    return 0;
    
}
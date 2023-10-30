#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
int main() {
    char data[] = "FitnessData_2023.csv";
    FILE *file = fopen(data, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    FITNESS_DATA data_array[100];

    char date[11];
    char time[6];
    char steps[10];
    char delimiter[2] = ",";
    int count = 0;

    int buffer_size = 1024;
    char line_buffer[buffer_size];

    //Get first three lines
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        tokeniseRecord(line_buffer, delimiter, date, time, steps);
        strcpy(data_array[count].date, date);
        strcpy(data_array[count].time, time);
        strcpy(data_array[count].steps, atoi(steps));
        printf("%s/%s/%d\n", date, time, atoi(steps));
        count ++;
    }

    for (int i; i < 3; i++)
    {
        printf("%s/%s/%d\n", data_array[i].date, data_array[i].time, data_array[i].steps);
    }

    printf("Number of records in file: %d\n", count);
    fclose(file);
    return 0;
}
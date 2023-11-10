
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

char feweststeps(struct data, int count)
{
	int least = 0;
	
	for (int i = 0; i < count; i++)
	{
		printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
	}
}

#endif // FITNESS_DATA_STRUCT_H

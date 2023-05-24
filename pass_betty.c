#include <stdio.h>

/**
 * calculate_average - Calculates the average of an array of scores
 * @scores: The array of scores
 * @num_scores: The number of scores in the array
 *
 * Return: The average score as a float
 */
float calculate_average(int scores[], int num_scores)
{
	int i, sum = 0;
	float average;

	for (i = 0; i < num_scores; i++)
	{
		sum += scores[i];
	}

	average = (float) sum / num_scores;

	return (average);
}

/**
 * task_main - Entry point for the program
 *
 * Return: Always 0 (Success)
 */
int task_main(void)
{
	int num_scores, i;
	int scores[100];
	float average_score;

	printf("Enter the number of scores: ");
	scanf("%d", &num_scores);

	printf("Enter the scores: ");
	for (i = 0; i < num_scores; i++)
	{
		scanf("%d", &scores[i]);
	}

	average_score = calculate_average(scores, num_scores);

	printf("The average score is: %.2f\n", average_score);

	return (0);
}

// Sean Szumlanski
// COP 3502, Fall 2020

// =========================
// SneakyRooks: testcase01.c
// =========================
// Boundary check to make sure the difficultyRating() and hoursSpent() functions
// are implemented correctly.


#include <stdio.h>
#include "SneakyRooks.h"

int main(int argc, char **argv)
{
	int success = 1;

	if (difficultyRating() < 1.0 || difficultyRating() > 5.0)
		success = 0;
	if (hoursSpent() <= 0.0 || hoursSpent() > 60.0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}

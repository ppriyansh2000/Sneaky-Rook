// Sean Szumlanski
// COP 3502, Fall 2020

// =========================
// SneakyRooks: testcase04.c
// =========================
// A simple test case for allTheRooksAreSafe(). At least two of the rooks on the
// main chess board in this test case can attack one another.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SneakyRooks.h"


// The following function ensures that allTheRooksAreSafe() is not simply always
// returning the same value or a random value in an attempt to game the system
// for free points. This function must return 1 (success) in order for you to
// be allowed to pass the main test case down in main().
//
// A similar function will act as a guardian in the grading of this assignment,
// but the rook configurations will be different. You will want to test your
// program very thoroughly to ensure there's no chance of failing a baseline
// function like this during grading.

int baseline(void)
{
	int i, success = 1;

	int numRooks = 3;
	int boardSize = 4;

	char *safeRooks[3];
	char *unsafeRooks[3];

	safeRooks[0] = "a3";
	safeRooks[1] = "b1";
	safeRooks[2] = "d4";

	unsafeRooks[0] = "a3";
	unsafeRooks[1] = "c3";
	unsafeRooks[2] = "d4";

	// Randomly toggle between calling the function on the safe rooks and the
	// unsafe rooks.
	for (i = 0; i < 32; i++)
	{
		if (rand() % 2 == 0)
		{
			if (allTheRooksAreSafe(safeRooks, numRooks, boardSize) != 1)
				return 0;  // fail whale
		}
		else
		{
			if (allTheRooksAreSafe(unsafeRooks, numRooks, boardSize) != 0)
				return 0;  // fail whale
		}
	}

	return success;
}

int main(void)
{
	int success = 1;

	int numRooks = 6;
	int boardSize = 10;

	char *rooks[6];

	rooks[0] = "a5";
	rooks[1] = "b2";
	rooks[2] = "d4";
	rooks[3] = "f10";
	rooks[4] = "h7";
	rooks[5] = "j2";

	srand(time(NULL));

	if (!baseline())
		success = 0;

	if (allTheRooksAreSafe(rooks, numRooks, boardSize) != 0)
		success = 0;

	// Verify that allTheRooksAreSafe did not corrupt any of these strings.
	if (strcmp(rooks[0], "a5") != 0)
		success = 0;
	else if (strcmp(rooks[1], "b2") != 0)
		success = 0;
	else if (strcmp(rooks[2], "d4") != 0)
		success = 0;
	else if (strcmp(rooks[3], "f10") != 0)
		success = 0;
	else if (strcmp(rooks[4], "h7") != 0)
		success = 0;
	else if (strcmp(rooks[5], "j2") != 0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}

// Sean Szumlanski
// COP 3502, Fall 2020

// =========================
// SneakyRooks: testcase02.c
// =========================
// A simple test of the parseCoordinateString() function.

#include <stdio.h>
#include <stdlib.h>
#include "SneakyRooks.h"

int main(void)
{
	int success = 1;

	Coordinate rook;
	rook.col = 0;
	rook.row = 0;
	parseCoordinateString("fancy58339", &rook);

	if (rook.col != 2768999 || rook.row != 58339)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}

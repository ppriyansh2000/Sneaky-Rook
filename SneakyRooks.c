// Priyansh Patel
// COP 3502c
// NID - pr348838
// Assignment 5 - SneakyRooks

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SneakyRooks.h"

int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize)
{
  int *row, *column;
  Coordinate *rook_coordinates;
  int i, flag, counter;

  flag = 1;
  counter = 0;

  // checks if all rookString are empty
  for(i = 0; i < numRooks; i++)
  {
    if(strcmp(rookStrings[i], "") == 0)
    {
      counter++;
    }
  }

  // there are no rooks on the board
  if (counter == numRooks)
  {
    return 0;
  }

  // allocate memory
  rook_coordinates = malloc(sizeof(Coordinate));
  row = calloc((boardSize + 1), sizeof(int));
  column = calloc((boardSize + 1), sizeof(int));

  // this loop checks and flags each of the row and column
  for(i = 0; i < numRooks; i++)
  {
    // if one or more rookstrings are empty
    if(strcmp(rookStrings[i], "") == 0)
    {
      continue;
    }

    // find the coordinates for each of the rooks
    parseCoordinateString(rookStrings[i], rook_coordinates);

    // checks the flags in rows and columns
    // if true then the rooks are not safe
    if (row[rook_coordinates->row] == flag || column[rook_coordinates->col] == flag)
    {
      free(rook_coordinates);
      free(row);
      free(column);
      return 0;
    }

    // flag the row and column coordinates
    row[rook_coordinates->row] = flag;
    column[rook_coordinates->col] = flag;
  }

  // free the allocated memory
  free(rook_coordinates);
  free(row);
  free(column);

  return 1;
}

void parseCoordinateString(char *rookString, Coordinate *rookCoordinate)
{
  int i, len;
  int alpha_to_num, int_num;
  char buffer[1001];

  // initlize the rows and columns
  rookCoordinate->row = 0;
  rookCoordinate->col = 0;

  len = strlen(rookString);
  int_num = 0;
  alpha_to_num = 0;

  // loop through the string to split row and column
  for(i = 0; i < len; i++)
  {
    if(isdigit(rookString[i]))
    {
      // copied row number from a char* into a char[] buffer
      strcpy(buffer, &rookString[i]);
      break;
    }
    else
    {
      // alpha_to_num gives a value of the alphabet in numbers
      // exmaple - a = 1, b = 2, ... , z = 26
      alpha_to_num = (rookString[i] - 'a') + 1;

      // finds the column number of the rook
      // multipies previous alpha_to_num value with 26 to represent base 26
      rookCoordinate->col = (rookCoordinate->col * 26) + alpha_to_num;
    }
  }
  // used atoi() to parse into int
  // atoi() has an O(n), n is length of the string
  int_num = atoi(buffer);
  rookCoordinate->row = int_num;

  return;
}

double difficultyRating(void)
{
  return 3.8;
}

double hoursSpent(void)
{
  return 14.0;
}

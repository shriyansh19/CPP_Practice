#ifndef RACE_H
#define RACE_H

// Finish line position
const int FINISH_LINE = 70;

// Function prototypes
void moveTortoise(int* pos);
void moveHare(int* pos);
void printRace(const int* tortoisePos, const int* harePos);

#endif

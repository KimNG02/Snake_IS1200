#ifndef MODEL_H_ 
#define MODEL_H_

#include <stdint.h>
#include "libs.h"
#include <stdbool.h>


typedef struct Coord{
    int x;
    int y;
}Coord;

typedef struct Snake{
    Coord bodies[100];
    int length;
}Snake;

Snake snake;
Coord fruit;
Coord direction;

int step ();
void initNewGame();
void setDirection(int x, int y);

#endif // MODEL_H_

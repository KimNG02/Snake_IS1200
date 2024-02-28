#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */


#include "model.h"  /* Declatations for these labs */



void initNewGame(){
    snake.bodies[0].x = 64;
    snake.bodies[0].y = 16;
    snake.length = 1;
    
    fruit.x = 12;
    fruit.y = 12;

    direction.x = 0;
    direction.y = -1;
}

void setDirection(int x, int y){
    if(x == 0 && y != 0 && direction.x != 0 && direction.y == 0){
        direction.x = 0;
        direction.y = y;
    }
    if(y == 0 && x != 0 && direction.y != 0 && direction.x == 0){
        direction.y = 0;
        direction.x = x;
    }
}

//0 nothing happend
//1 got fruit
//-1 died
int step () {
    int score = 0;

    Coord newHead;
    newHead.x = snake.bodies[0].x + direction.x;
    newHead.y = snake.bodies[0].y + direction.y;

    if(newHead.x > 126 || newHead.x < 1)
        return -1;

    if(newHead.y > 30 || newHead.y < 1)
        return -1;

    if(newHead.x == fruit.x && newHead.y == fruit.y){
        snake.length++;
        fruit.x = (snake.bodies[snake.length-2].y * 3241) % 125 +1;
        fruit.y = (snake.bodies[snake.length-2].x * 1231) % 29 +1;
        score = 1;
    }



    int i;
    for(i = snake.length-1; i > 0; i--){
        snake.bodies[i] = snake.bodies[i-1];

        if(newHead.x == snake.bodies[i].x && newHead.y == snake.bodies[i].y)
            return -1;
    }

    snake.bodies[0] = newHead;
    return score;
}

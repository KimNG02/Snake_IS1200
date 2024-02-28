/* mipslabmain.c

   This file written 2015 by Axel Isaksson,
   modified 2015, 2017 by F Lundevall

   Latest update 2017-04-21 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "libs.h"  /* Declatations for these labs */
#include "view.h"
#include "model.h"

int main(void) {
	system_init();
	display_init();
	enableIO();
	enableTimer2();
	enableLed();
    
	Coord newDirection;
	unsigned long int time = 0;
    bool isInGame = false;
	unsigned int score = 0;


	while( 1 )
	{
		if(IFS(0) & 0x100){
			IFSCLR(0) = 0x100;
			time ++;	
		}else{
			continue;
		}

		while(!isInGame){
            if(getbtns() == 0){
				display_string(1, "Welcome to SNAKE");
				display_string(3, "Let's play");
				display_update();
				continue;
			}

            
            isInGame = true;
			initNewGame();
			score = 0;
			newDirection.x = direction.x;
	        newDirection.y = direction.y;
		}

		getNewDirection(&newDirection);

		if(time % 10 != 0)
		    continue;

		setDirection(newDirection.x, newDirection.y);
        
		int r = step();
		if(r == -1)
		    isInGame = false;
		else
		    score += r;

		clearBuffer();

		int i;
		for(i = 0; i < snake.length; i++){
            bufferPixel(snake.bodies[i].x, snake.bodies[i].y);
		}
		bufferPixel(fruit.x, fruit.y);

		renderGame();
		viewScore(score);
	}
	return 0;
}

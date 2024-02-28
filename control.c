#include "control.h"


void getNewDirection(Coord *newDirection){
    int btn_state = getbtns();
        if(btn_state & 0b1000){//1
			newDirection->x = -1;
			newDirection->y = 0;
		}

		if(btn_state & 0b100){//1
			newDirection->x = 0;
			newDirection->y = 1;
		}

		if(btn_state & 0b10){//3
			newDirection->x = 0;
			newDirection->y = -1;
		}

		if(btn_state & 0b1){//3
			newDirection->x = 1;
			newDirection->y = 0;
		}
}
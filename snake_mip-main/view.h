#ifndef VIEW_H_ 
#define VIEW_H_

#include <stdint.h>
#include "libs.h"

void renderGame(void);
void clearBuffer();
void bufferPixel(int x, int y);
void viewScore(unsigned int value);
void display_string(int line, char *s);
void display_update(void);

#endif // VIEW_H_

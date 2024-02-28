#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "view.h"  /* Declatations for these labs */


#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

#define DISPLAY_ACTIVATE_RESET (PORTGCLR = 0x200)
#define DISPLAY_DO_NOT_RESET (PORTGSET = 0x200)

#define DISPLAY_ACTIVATE_VDD (PORTFCLR = 0x40)
#define DISPLAY_ACTIVATE_VBAT (PORTFCLR = 0x20)

#define DISPLAY_TURN_OFF_VDD (PORTFSET = 0x40)
#define DISPLAY_TURN_OFF_VBAT (PORTFSET = 0x20)


#define _PORTE ((volatile unsigned int *)0xbf886110)


volatile uint8_t buffer[4][128] = {{0}};



void viewScore(unsigned int value){
    *_PORTE = value;  // Update the LEDs to show the new value
}


uint8_t _spi_send_recv(uint8_t data) {
	while(!(SPI2STAT & 0x08));
	SPI2BUF = data;
	while(!(SPI2STAT & 1));
	return SPI2BUF;
}

void clearBuffer(){
    int row, col;
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 128; col++) {
            buffer[row][col] = 0x0; 

            if(row == 0)
                buffer[row][col] = 0x1; 

            if(row == 3)
                buffer[row][col] = 0x80; 

            if(col == 0 || col == 127)
                buffer[row][col] = 0xff; 
        }
    }
}

void bufferPixel(int x, int y){
    int row = y/8;
    int offset = y%8;
    buffer[row][x] = buffer[row][x] | (1 << offset);
}

void renderGame() {
    int row, col;
    for(row = 0; row < 4; row++){
        DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);
		spi_send_recv(row);
		
		spi_send_recv(0x0);
		spi_send_recv(0x10);
		
		DISPLAY_CHANGE_TO_DATA_MODE;

        for(col = 0; col < 128; col++) {
            spi_send_recv(buffer[row][col]);
        }
    } 
}



void display_string(int line, char *s) {
	int i;
	if(line < 0 || line >= 4)
		return;
	if(!s)
		return;
	
	for(i = 0; i < 16; i++)
		if(*s) {
			textbuffer[line][i] = *s;
			s++;
		} else
			textbuffer[line][i] = ' ';
}


void display_update(void) {
	int i, j, k;
	int c;
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);
		spi_send_recv(i);
		
		spi_send_recv(0x0);
		spi_send_recv(0x10);
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 16; j++) {
			c = textbuffer[i][j];
			if(c & 0x80)
				continue;
			
			for(k = 0; k < 8; k++)
				spi_send_recv(font[c*8 + k]);
		}
	}
}
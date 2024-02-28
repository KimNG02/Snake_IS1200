#ifndef LIBS_H_ 
#define LIBS_H_

void system_init(void);
void display_init(void);
uint8_t spi_send_recv(uint8_t data);
void enableIO();
int getbtns(void);
void enableTimer2();
void enableLed();

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

#endif // LIBS_H_
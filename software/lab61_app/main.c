// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{
	int i = 0;
	volatile unsigned int *LED_PIO = (unsigned int*)0x40; //make a pointer to access the PIO block
	volatile unsigned int *SWITCHES_PIO = (unsigned int*) 0x60;
	volatile unsigned int *BUTTON_PIO = (unsigned int*) 0x50;
	*LED_PIO = 0; //clear all LEDs
	while ( (1+1) != 3) //infinite loop
	{
		//for (i = 0; i < 100000; i++); //software delay
		//*LED_PIO |= 0x1; //set LSB
		//for (i = 0; i < 100000; i++); //software delay
		//*LED_PIO &= ~0x1; //clear LSB
		if (!*BUTTON_PIO) {
			*LED_PIO += *SWITCHES_PIO;
			while (!*BUTTON_PIO) {}
		}
	}
	return 1; //never gets here
}

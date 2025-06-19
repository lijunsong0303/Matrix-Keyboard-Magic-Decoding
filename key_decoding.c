#include "reg51.h "// AT89S51 MCU

unsigned char keymapone[16] = {0xFF,0x00,0x01,0xFF,0x02,0xFF,0xFF,0xFF,0x03,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// Returns the key value when only one key is pressed. Returns 1 through 16.
unsigned char Key4x4SignedRead(void){
	unsigned char keypush;

	P1 = 0x0F; // Reads the low 4 bit pins. Modify it to suit your own hardware.
	keypush = keymapone[((~(P1))&0x0F)];
	keypush = (keypush << 2);
	
	P1 = 0xF0; // Reads the high 4 bit pins. Modify it to suit your own hardware.
	keypush |= keymapone[(((~(P1))&0xF0) >> 4)];
	
	if(keypush & 0xC0)return 0; // Returns 0 if more than one is pressed at the same time.
	else return (keypush + 1); // If the button is pressed Returns 1 through 16. else renturn 0
}

/* // Recognize that both buttons are pressed at the same time. Use as required.
unsigned int keymapdouble(unsigned char indata){
	unsigned int temp;
	switch(indata){
		case 0x01: temp=0x00;break;
		case 0x02: temp=0x01;break;
		case 0x04: temp=0x02;break;
		case 0x08: temp=0x03;break;
		case 0x03: temp=0x10;break;
		case 0x05: temp=0x11;break;
		case 0x06: temp=0x12;break;
		case 0x09: temp=0x13;break;
		case 0x0A: temp=0x20;break;
		case 0x0C: temp=0x21;break;
		default:temp=0xFFFF;break;
	}
	return temp;
}

// Recognize that both buttons are pressed at the same time. Use as required.
unsigned char Key4x4DoubleRead(void){
	unsigned int keypush;
	
	P1 = 0x0F; // Reads the low 4 bit pins. Modify it to suit your own hardware.
	keypush = keymapdouble(((~(P1))&0x0F));
	keypush = (keypush << 2);
	
	P1 = 0xF0; // Reads the high 4 bit pins. Modify it to suit your own hardware.
	keypush |= keymapdouble((((~(P1))&0xF0) >> 4));
	
	if(keypush & 0xC000)return 0;
	else return (keypush + 1); // Returns 1 through 166.
}
*/

void main(void){
  	unsigned char key4x4old, flage, keynum;
  
    while(1){
        keynum = Key4x4SignedRead(); // read 4x4 KeyBoard
        // keynum = Key4x4DoubleRead();
    		if(key4x4old != keynum){
    			key4x4old = keynum;
    			if(flage){ flage =0;led(0x0);}// open led
    			else{led(0x1); flage =1;}// colse led
    			OLED_ShowNum(16,7, keynum,7);// oled displays the key value.
    		}
    }
}

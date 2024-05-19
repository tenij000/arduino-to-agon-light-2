
//KBD stuff
#include <ps2dev.h>  // to emulate a PS/2 device
PS2dev keyboard(3,2);  // PS2dev object (2:data, 3:clock)
int enabled = 0;  // pseudo variable for state of "keyboard"
unsigned char c;  //char stores data recieved from computer for KBD
int shift = 0;



void ack()
{
  //acknowledge commands
  while(keyboard.write(0xFA));
}

int keyboardcommand(int command)
{
  unsigned char val;
  switch (command)
  {
  case 0xFF: //reset
    ack();
    //the while loop lets us wait for the host to be ready
    while(keyboard.write(0xAA)!=0);
    break;
  case 0xFE: //resend
    ack();
    break;
  case 0xF6: //set defaults
    //enter stream mode
    ack();
    break;
  case 0xF5: //disable data reporting
    //FM
    enabled = 0;
    ack();
    break;
  case 0xF4: //enable data reporting
    //FM
    enabled = 1;
    ack();
    break;
  case 0xF3: //set typematic rate
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  case 0xF2: //get device id
    ack();
    keyboard.write(0xAB);
    keyboard.write(0x83);
    break;
  case 0xF0: //set scan code set
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  case 0xEE: //echo
    //ack();
    keyboard.write(0xEE);
    break;
  case 0xED: //set/reset LEDs
    ack();
    keyboard.read(&val); //do nothing with the rate
    ack();
    break;
  }
  return 0;
}

void setup()
{
  // send the keyboard start up
  while(keyboard.write(0xAA)!=0);
  delay(10);
  
  // initialize the serial port:
  Serial.begin(9600);
  
}

void loop()
{
if (Serial.available()) {
    // Read the next key
    char c = Serial.read();
    
   
    
    if (c == 'a') {
      delay(100);
      keyboard.write(0x1C);// a
    }
     
    if (c == 'A') {  
        delay(100);
      keyboard.write(0x12); // shift up
      delay(100);
      keyboard.write(0x1C); // 
      delay(100);
      keyboard.write(0xF0);
      delay(100);
      keyboard.write(0x1C); // 
      delay(100);
      keyboard.write(0xF0);/// shift down
      delay(100);
      keyboard.write(0x12); // /shift down
      //--------------------------------------
      
    }
    
    if (c == 'b') {
      delay(100);
      keyboard.write(0x32);// b
        
    }
     
      
    
    if (c == 'c') {
      keyboard.write(0x21);// c
      
    }
    if (c == 'd') {
      keyboard.write(0x23);// d
      
    }
    if (c == 'e') {
      keyboard.write(0x24);// e
      
    }
    if (c == 'f') {
      keyboard.write(0x2B);// f
      
    }
    if (c == 'g') {
      keyboard.write(0x34);// g
      
    }
    if (c == 'h') {
      keyboard.write(0x33);// h
      
    }
    if (c == 'i') {
      keyboard.write(0x43);// i
      
    }
    if (c == 'j') {
      keyboard.write(0x3B);// j
      
    }
    if (c == 'k') {
      keyboard.write(0x42);// k
      
    }
    if (c == 'l') {
      keyboard.write(0x4B);// l
      
    }
    if (c == 'n') {
      keyboard.write(0x31);// n
      
    }
    if (c == 'm') {
      keyboard.write(0x3A);// m
      
    }
    if (c == 'o') {
      keyboard.write(0x44);// o
      
    }
    if (c == 'p') {
      keyboard.write(0x4D);// p
      
    }
    if (c == 'q') {
      keyboard.write(0x15);// q
      
    }
    if (c == 'r') {
      keyboard.write(0x2D);// r
      
    }
    if (c == 's') {
      keyboard.write(0x1B);// s
      
    }
    if (c == 't') {
      keyboard.write(0x2C);// t
      
    }
    if (c == 'u') {
      keyboard.write(0x3C);// u
      
    }
    if (c == 'v') {
      keyboard.write(0x2A);// v
      
    }
    if (c == 'w') {
      keyboard.write(0x1D);// w
      
    }
    if (c == 'x') {
      keyboard.write(0x22);// x
      
    }
    if (c == 'y') {
      keyboard.write(0x35);// y
      
    }
    if (c == 'z') {
      keyboard.write(0x1A);// z 
      
    }
    if (c == ' ') {
      keyboard.write(0x29);// space
      delay(50);
    }
    
    if (c == '2') {
      keyboard.write(0x66);// backspace
      delay(50);
    }
    
    if (c == '=') {
      keyboard.write(0x55);// .
      delay(50);
    }
    if (c == '+') {
      keyboard.write(0x79);// +
      delay(50);
    }
    if (c == '.') {
      keyboard.write(0x49);// .
      delay(50);
    }
    if (c == ',') {
      keyboard.write(0x41);// ,
      delay(50);
    }
    if (c == '1') {
      keyboard.write(0x5A);// , enter
      delay(50);
    }
    if (c == '3') {
      shift = 2;
      delay(50);
    }
    if (c == '"') {
      //keyboard.write(0xE0);
      delay(100);
      keyboard.write(0x12); // shift up
      delay(100);
      keyboard.write(0x52); // "
      delay(100);
      keyboard.write(0xF0);
      delay(100);
      keyboard.write(0x52); // "
      delay(100);
      keyboard.write(0xF0);/// shift down
      delay(100);
      keyboard.write(0x12); // /shift down
    }

  Serial.println(shift);
  }

}

void test()
{
 keyboard.write(0x1A);// z 
}




#ifndef InteractionChannel_h
#define InteractionChannel_h 0x00

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "HardwareSerial.h"
#include "LiquidCrystal.h"
#include "Keypad.h"

class InteractionChannel {

private:
  Stream &stream;

public:

	/* Stream only constructor */
  InteractionChannel(Stream &_stream);

	/* Custom read and write function consturctors */
	InteractionChannel(Stream &_stream,char (*getKey)());
	InteractionChannel(Stream &_stream,void (*writeChar)(String s));
	InteractionChannel(char (*getKey)(),void (*writeChar)(String s));

	/* Keypad and LCD constructors */
	InteractionChannel(Stream &_stream,Keypad keypad);
	InteractionChannel(Stream &_stream,LiquidCrystal &lcd);
	InteractionChannel(Keypad* keypad,LiquidCrystal* lcd);

	char (*readFunction)();
	void (*printFunction)(String s);

	void* reader;
	void* writer;

  char read();
  int available();
  int peek();

  void write(byte b);
  void println(String string);
	void println(int n);
	void println(char c);
  void print(String string);
	void print(char c);

};

#endif

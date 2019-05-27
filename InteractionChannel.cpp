#include "InteractionChannel.h"

InteractionChannel::InteractionChannel(Stream &_stream) : stream(_stream)
{
	this->readFunction = NULL;
	this->printFunction = NULL;
}

InteractionChannel::InteractionChannel(Stream &_stream,char (*getKey)()) : stream(_stream)
{
	this->readFunction = getKey;
	this->printFunction = NULL;
}

InteractionChannel::InteractionChannel(Stream &_stream,void (*writeChar)(String s)) : stream(_stream)
{
	this->readFunction = NULL;
	this->printFunction = writeChar;
}

InteractionChannel::InteractionChannel(char (*getKey)(),void (*writeChar)(String s))
{
	this->readFunction = getKey;
	this->printFunction = writeChar;
}

InteractionChannel::InteractionChannel(Stream &_stream,Keypad keypad) : stream(_stream)
{

	auto func = [] (Keypad* keypad) { return (char (*)())&keypad->getKey; };

	this->readFunction = (char (*)())&keypad.getKey; //func(keypad);
	this->printFunction = NULL;

	char c;
	// Serial.println("test");
	// while((c = func()) < 1) { }
	// Serial.println(c);
	// delay(2000);
	Serial.println("test2");
	while((c = this->readFunction()) < 1) { }
	Serial.println(c);
	delay(2000);
}

InteractionChannel::InteractionChannel(Stream &_stream,LiquidCrystal &lcd) : stream(_stream)
{
	auto func = [lcd] (String s) {
		lcd.clear();
		lcd.print(s);
	};

	this->readFunction = NULL;
	this->printFunction = (void (*)(String s))&func;
}

InteractionChannel::InteractionChannel(Keypad* keypad,LiquidCrystal* lcd)
{
	auto rfunc = [keypad] () { return keypad->getKey(); };

	this->readFunction = (char (*)())&rfunc;

	auto wfunc = [lcd] (String s) {
			Serial.println(s);
			lcd->clear();
			lcd->print(s);
		};
	this->printFunction = (void (*)(String s))&wfunc;
}

char InteractionChannel::read() {

	if(this->readFunction == NULL)
	{
		return stream.read();
	} else {
		return this->readFunction();
	}

}

int InteractionChannel::available() {
	return stream.available();
}

int InteractionChannel::peek() {
	return stream.peek();
}

void InteractionChannel::write(byte b) {
	stream.write(b);
}

void InteractionChannel::println(String string) {

	if(this->printFunction == NULL)
	{
		stream.println(string);
	} else {
		this->printFunction(string);
		// int l = string.length();
		// Serial.println(string);
		// Serial.println(l);
		// for(int i = 0; i < l; i++)
		// {
		// 	Serial.println(i);
		// 	this->printFunction(string.charAt(i));
		//
		// }
	}

}

void InteractionChannel::println(int n) {
	stream.println(n);
}

void InteractionChannel::println(char c) {

	if(this->printFunction == NULL)
	{
		stream.print(c);
	} else {
		this->printFunction(String(c));
	}

}

void InteractionChannel::print(String string) {

	if(this->printFunction == NULL)
	{
		stream.print(string);
	} else {
		this->printFunction(string);
	}

}

void InteractionChannel::print(char c) {

	if(this->printFunction == NULL)
	{
		stream.print(c);
	} else {
		this->printFunction(String(c));
	}

}

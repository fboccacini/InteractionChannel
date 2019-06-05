#include "InteractionChannel.h"
#include "ChannelTypes.h"

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

InteractionChannel::InteractionChannel(Stream &_stream,Keypad* keypad) : stream(_stream)
{

	this->readFunction = NULL;
	this->printFunction = NULL;

	this->reader = keypad;
	this->readerFunction = &readKeypad;

}

InteractionChannel::InteractionChannel(Stream &_stream,LiquidCrystal* lcd) : stream(_stream)
{

	this->readFunction = NULL;
	this->printFunction = NULL;

	this->writer = lcd;
	this->writerFunction = &lcdPrint;

}

InteractionChannel::InteractionChannel(Keypad* keypad,LiquidCrystal* lcd)
{
	// TODO: It would be nice to find a solution with lambdas like following, so that
	// an extra header like ChannelTypes.h wouldn't be required.
	// This one does not work because passing a pointer to a capturing lambda is not allowed.
	// I also tried a non-capturing solution with the pointer as argument, it compiled,
	// but it didn't work due to some overflow (I guess..). I'll come back here in a while.
	//
	// auto rfunc = [keypad] () { return keypad->getKey(); };
	//
	// this->readFunction = (char (*)())&rfunc;
	//
	// auto wfunc = [lcd] (String s) {
	// 		Serial.println(s);
	// 		lcd->clear();
	// 		lcd->print(s);
	// 	};
	// this->printFunction = (void (*)(String s))&wfunc;

	this->readFunction = NULL;
	this->printFunction = NULL;

	this->reader = keypad;
	this->readerFunction = &readKeypad;

	this->writer = lcd;
	this->writerFunction = &lcdPrint;

}

char InteractionChannel::read() {

	if(this->readerFunction == NULL)
	{
		if(this->readFunction == NULL)
		{
			return stream.read();
		} else {
			return this->readFunction();
		}
	} else {
		return this->readerFunction(this->reader);
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

	if(this->writerFunction == NULL)
	{
		if(this->printFunction == NULL)
		{
			stream.println(string);
		} else {
			printFunction(string);
		}
	} else {
		writerFunction(this->writer, string);
	}
	// if(this->printFunction == NULL)
	// {
	// 	stream.println(string);
	// } else {
	// 	this->printFunction(string);
		// int l = string.length();
		// Serial.println(string);
		// Serial.println(l);
		// for(int i = 0; i < l; i++)
		// {
		// 	Serial.println(i);
		// 	this->printFunction(string.charAt(i));
		//
		// }
	// }

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

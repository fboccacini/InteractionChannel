#include "InteractionChannel.h"


void consolePrint(message)
{
	Serial.println(message);
}
/* Output channels for sensor interaction */
PrintChannel::PrintChannel(short int pins[], char name[], short int channelType,void (*printFunction)());
{

	char* _name = name;
	short int* _pins = pins;
	void (*print)() = printFunction;

};


/* Control input channer for sensor interaction */
ControlChannel::ControlChannel(int pins[], char name[], control_input controlInput)
{



		char lastReadChar;
		char* lastReadSentence;

		char* _name = name;
		short int* _pins = pins;
		control_input specialButtons = controlInput;

};

// Reads a single charachter
char ControlChannel::readChar()
{

}

// Reads a single character and transforms it in an integer
short int ControlChannel::readSingleInt()
{

}

// Reads characters until it reads the accept char from the configuration
char* ControlChannel::readSentence()
{

}

// Like readSentence, but it convert the output to an integer
int ControlChannel::readInt()
{

}

 // Same again, but it converts to float. The dot button marks the decimal point
float ControlChannel::readFloat()
{

}

/* InteractionChannel is a combo of a PrintChannel and a ControlChannel */
InteractionChannel::InteractionChannel(ControlChannel controlChannel, PrintChannel printChannel)
{

    ControlChannel _controlChannel = controlChannel;
    PrintChannel _printChannel = printChannel;
};

// Prints a message on its print channel
void InteractionChannel::print(char* message)
{

}

// Reads a single charachter from its control channel
char InteractionChannel::readChar()
{

}

// Reads a single character from its control channel and transforms it in an integer
short int InteractionChannel::readSingleInt()
{

}

// Reads characters from its control channel until it reads the accept char from the configuration
char* InteractionChannel::readSentence()
{

}

// Like readSentence, but it convert the output to an integer
int InteractionChannel::readInt()
{

}

// Same again, but it converts to float. The dot button marks the decimal point
float InteractionChannel::readFloat()
{

}


#endif

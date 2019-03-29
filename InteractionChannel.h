#ifndef INTERACTION_CHANNEL_H
#define INTERACTION_CHANNEL_H

#define CONSOLE 1
#define KEYPAD 2

#include "Arduino.h"

/* Output channels for sensor interaction */
class PrintChannel
{
	public:
		PrintChannel(short int pins[], char name[], short int channelType,void (*printFunction)());
		void (*print)();

	private:
		char* _name;
		short int* _pins;

};


/* Control channel special characters */
typedef struct control_input {
	char accept;
	char back;
	char exit;
	char next;
	char previous;
  char dot;
};

//////////////////////////////////////////////////////////////////////////////////////////
/*																																											*/
/* Definition of control_input for specific controllers.																*/
/*																																											*/
/* Values describe, respectively: 																											*/
/* Accept button, used normally to choose an option or enter a menu											*/
/* Back button, used to get back to the previous menu																		*/
/* Exit button, used to get out of all menus to the home display												*/
/* Next button, used to select the next option																					*/
/* Previous button, used to select the previous option																	*/
/* Dot button, used to set decimal point in a float number 															*/
/*																																											*/
/* TODO: set correct defaults for all control channels																	*/
/*																																											*/
//////////////////////////////////////////////////////////////////////////////////////////
control_input keypadSpecialChars = {'A','B','C','D','E','F'};


/* Control input channer for sensor interaction */
class ControlChannel
{
	public:
		ControlChannel(int pins[], char name[], control_input controlInput);

		char readChar();              // Reads a single charachter
    short int readSingleInt();    // Reads a single character and transforms it in an integer

		char* readSentence();         // Reads characters until it reads the accept char from the configuration
    int readInt();                // Like readSentence, but it convert the output to an integer
    float readFloat();            // Same again, but it converts to float. The dot button marks the decimal point

		char lastReadChar;
		char* lastReadSentence;

	private:
		char* _name;
		short int* _pins;
		control_input specialButtons;

};

/* InteractionChannel is a combo of a PrintChannel and a ControlChannel */
class InteractionChannel
{
  public:
    InteractionChannel(ControlChannel controlChannel, PrintChannel printChannel);
    void print(char* message);    // Prints a message on its print channel
    char readChar();              // Reads a single charachter from its control channel
    short int readSingleInt();    // Reads a single character from its control channel and transforms it in an integer

		char* readSentence();         // Reads characters from its control channel until it reads the accept char from the configuration
    int readInt();                // Like readSentence, but it convert the output to an integer
    float readFloat();            // Same again, but it converts to float. The dot button marks the decimal point


  private:
    ControlChannel controlChannel;
    PrintChannel printChannel;
};

#endif

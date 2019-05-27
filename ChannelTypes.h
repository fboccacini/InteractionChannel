
//////////////////////////////////////////////////////////////////////////////////////////
/*																																											*/
/* Definition of printing functions for specific print channels.												*/
/*																																											*/
//////////////////////////////////////////////////////////////////////////////////////////
void consolePrint(const char* message)
{
	Serial.println(message);
}



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

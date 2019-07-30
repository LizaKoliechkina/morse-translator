#pragma once

/**

	morseTranslator.h

	Class, given a different types of data, translates information into Morse code
	and reproduces the code by means of sound

	@author Yelyzaveta Koliechkina
	@version 1.0 11/05/2019

*/


#ifndef morseTranslator_h
#define morseTranslator_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <windows.h>

class morseTranslator
{
protected:
	int Freq;
	int Pause;
	int DotTime;
	int DashTime;
	int CharPause;
	std::string kod;	 											
public:
	morseTranslator();						 						
	const morseTranslator & operator = (const morseTranslator &A);	
	~morseTranslator();   									

	// function to translate Morse code
	void translate(std::string text);

	// function to reproduces the code by means of sound
	void sound();


	// Setters and getters 

	void setFrequency(int value);				
	void setPause(int value);					
	void setDotTime(int value);					
	void setDashTime(int value);				
	void setCharPause(int value);				

	int getFrequency();							
	int getPause();								
	int getDotTime();							
	int getDashTime();							
	int getCharPause();							

	template <typename T>

	// friend operator which takes any data types
	friend morseTranslator & operator << (morseTranslator& m, const T & value); 

	// friend operator which takes a function pointer
	friend morseTranslator & operator << (morseTranslator& out, morseTranslator& (*manip) (morseTranslator& out));

	// friend manipulator which makes a pause when playing Morse code
	friend morseTranslator & pause(morseTranslator& out);
};

template <typename T> 	
inline morseTranslator & operator << (morseTranslator & m, const T & value)    {

	std::ostringstream stream;
	stream << std::setprecision(12);
	stream << value;
	std::string str = stream.str();

	m.translate(str);
	m.sound();
	return m;
}

inline morseTranslator & operator << (morseTranslator& out, morseTranslator& (*manip)(morseTranslator& out))    
{
	return manip(out);
}

inline morseTranslator & pause(morseTranslator & out)  	  
{
	Sleep(out.getCharPause());
	return out;
};

#endif /* morseTranslator_h */
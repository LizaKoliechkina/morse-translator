#pragma once

//
//  morseTranslator.h
//  
//	Class, given a different types of data, translates information to Morse code and play the code with a sound
//
//  Created by Yelyzaveta Koliechkina on 11/05/2019.
//  Copyright © 2019 Yelyzaveta Koliechkina. All rights reserved.
//

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

	void translate(std::string text);  			// function to translate Morse code
	void sound();								// function to play Morse code with a sound

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
	friend morseTranslator & operator << (morseTranslator& m, const T & value);
	friend morseTranslator & operator << (morseTranslator& out, morseTranslator& (*manip) (morseTranslator& out));
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
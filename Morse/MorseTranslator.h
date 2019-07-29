#pragma once

#ifndef morseTranslator_h
#define morseTranslator_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <windows.h>

class morseTranslator
{
protected:
	int Pause;
	int DotTime;
	int DashTime;
	int CharPause;
	std::string kod;	 											// zmienna dla przechowywania kodu w postaci Morsea  - systemowa zmienna
public:
	int Freq;
	morseTranslator();						 						// konstruktor bezparametrowy
	const morseTranslator & operator = (const morseTranslator &A);	// operator '='
	~morseTranslator();   									// destruktor virtualny (virtualny dla tego zeby nie bylo zadnych problemow przy dziedziczeniu) 

	void translate(std::string text);  			// ta metoda tlumaczy otrzymane dane na kod Morsea i przypisuje wynik do zmiennej systemowej 'kod'
	void sound();								// odtwarza kod Morsea za pomoca dzwieku, wykorzystajac funkcje Beep(Hz,t)

	void setFrequency(int value);				// pobiera wartosc zmiennej chronionej Freq
	void setPause(int value);					// pobiera wartosc zmiennej chronionej Pause
	void setDotTime(int value);					// pobiera wartosc zmiennej chronionej DotTime
	void setDashTime(int value);				// pobiera wartosc zmiennej chronionej DashTime
	void setCharPause(int value);				// pobiera wartosc zmiennej chronionej CharPause

	int getFrequency();							// zwraca wartosc zmiennej chronionej Freq
	int getPause();								// zwraca wartosc zmiennej chronionej Pause
	int getDotTime();							// zwraca wartosc zmiennej chronionej DotTime
	int getDashTime();							// zwraca wartosc zmiennej chronionej DashTime
	int getCharPause();							// zwraca wartosc zmiennej chronionej CharPause

};


#endif // morseTranslator_h
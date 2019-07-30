#include "pch.h"
#include "MorseTranslator.h"
#include <windows.h>

morseTranslator::morseTranslator()
{
	Freq = 500;
	Pause = 50;
	DotTime = 50;
	DashTime = 100;
	CharPause = 100;
	kod = "";
}

morseTranslator::~morseTranslator()
{
	delete this;
}

const morseTranslator &morseTranslator :: operator = (const morseTranslator &A)
{
	if (&A != this)
	{
		this->Freq = A.Freq;
		this->Pause = A.Pause;
		this->DotTime = A.DotTime;
		this->DashTime = A.DashTime;
		this->CharPause = A.CharPause;
		this->kod = A.kod;
	}

	return *this;
}

void morseTranslator::translate(std::string text)      
{
	std::string kod_morse;
	const char symbols[64] = {
		' ',
		'1','2','3','4','5','6','7','8','9','0',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'.',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
	};
	const std::string morseLetters[64] = { " ", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-","-...","-.-.","-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", ".-","-...","-.-.","-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	for (unsigned int i = 0; i < text.size(); i++) {          
		for (unsigned int j = 0; j < 64; j++) {
			if (text[i] == symbols[j]) {
				kod_morse += morseLetters[j];
				break;
			}
		}
	}
	kod = kod_morse;
	std::cout << text << ": ";
}

void morseTranslator::sound()							
{
	for (int i = 0; i < kod.length(); i++)
	{
		switch (kod[i])
		{
		case '.':
			Beep(Freq, DotTime);
			Sleep(Pause);
			std::cout << ".";
			break;
		case '-':
			Beep(Freq, DashTime);
			Sleep(Pause);
			std::cout << "-";
			break;
		case ' ':
			Sleep(CharPause);
			std::cout << " ";
			break;
		default:
			std::cout << "Blad";
		}
	}

	Sleep(CharPause);
	std::cout << " " << std::endl;
}


void morseTranslator::setFrequency(int value)
{
	if (value > 0)
		Freq = value;
}
void morseTranslator::setPause(int value)
{
	if (value > 0)
		Pause = value;
}
void morseTranslator::setDotTime(int value)
{
	if (value > 0)
		DotTime = value;
}
void morseTranslator::setDashTime(int value)
{
	if (value > 0)
		DashTime = value;
}
void morseTranslator::setCharPause(int value)
{
	if (value > 0)
		CharPause = value;
}

int morseTranslator::getFrequency() { return Freq; }
int morseTranslator::getPause() { return Pause; }
int morseTranslator::getDotTime() { return DotTime; }
int morseTranslator::getDashTime() { return DashTime; }
int morseTranslator::getCharPause() { return CharPause; }
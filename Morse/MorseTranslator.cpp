#include "pch.h"
#include "MorseTranslator.h"

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

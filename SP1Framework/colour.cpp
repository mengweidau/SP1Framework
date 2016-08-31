#include "colour.h"

//return the colour 
WORD getColour(int selected, int current)//word is the colour 
{
	if (selected == current)
	{
		return 0x74;//selected colour
	}
	else
	{
		return 0x47;//ohers colour
	}
}
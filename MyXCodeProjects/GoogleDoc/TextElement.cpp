#include "TextElement.h"

TextElement::TextElement(string &s) : text(s){}
string TextElement::render()
{
    return text;
}

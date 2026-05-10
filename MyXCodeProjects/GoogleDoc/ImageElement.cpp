#include "ImageElement.h"

ImageElement::ImageElement(string& s)
{
    image = s;
}
string ImageElement::render()
{
    return "[Image:"+image+"]";
}

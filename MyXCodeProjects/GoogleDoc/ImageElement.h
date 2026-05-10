#include "DocumentElement.h"

class ImageElement : public DocumentElement
{
    string image;
public:
    ImageElement(string& s);
    virtual string render();
    
};

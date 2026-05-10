#include "DocumentElement.h"
using namespace std;

class TextElement : public DocumentElement
{
    string text;
public:
    TextElement(string &s);
    virtual string render();
};

#include "DocumentElement.h"
#include<vector>

class Document
{
    vector<DocumentElement*> documentElements;
public:
    //Document(Element* element, Storage* storage) : element(element), storage(storage){}
    void addElement(DocumentElement* element);
    string render();
};

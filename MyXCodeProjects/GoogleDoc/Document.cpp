#include "DocumentElement.h"
#include "Document.h"

void Document::addElement(DocumentElement* element)
{
    documentElements.push_back(element);
}
string Document::render()
{
    string result;
    for(DocumentElement* element: documentElements)
    {
        result +=element->render();
    }
    return result;
}

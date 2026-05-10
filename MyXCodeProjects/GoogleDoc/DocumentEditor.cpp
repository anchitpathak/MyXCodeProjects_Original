#include "DocumentEditor.h"
#include "TextElement.h"
#include "ImageElement.h"

DocumentEditor::DocumentEditor(Storage* storage, Document* document): storage(storage), document(document){}

void DocumentEditor::addText(string& s)
{
    document->addElement(new TextElement(s));
}

void DocumentEditor::addImage(string& s)
{
    document->addElement(new ImageElement(s));
}

string& DocumentEditor::renderDocument()
{
    if(renderredDocument.empty())
        renderredDocument = document->render();
    return renderredDocument;
}

void DocumentEditor::saveDB()
{
    storage->save(renderDocument());
}

void DocumentEditor::saveFile()
{
    storage->save(renderDocument());
}

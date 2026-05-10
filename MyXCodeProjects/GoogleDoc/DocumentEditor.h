#include "Storage.h"
#include "Document.h"
class DocumentEditor
{
    Storage* storage;
    Document* document;
    string renderredDocument;
public:
    DocumentEditor(Storage* storage, Document* document);
    virtual void addText(string& s);
    virtual void addImage(string& s);
    virtual string& renderDocument();
    virtual void saveDB();
    virtual void saveFile();
};

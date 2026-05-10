#include "Storage.h"

class FileStorage : public Storage
{
public:
    virtual void save(string& data);
};

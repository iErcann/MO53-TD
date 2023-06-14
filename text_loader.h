#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>
using namespace std;

class text_loader : public loader
{
public:
    text_loader() : loader("texte.txt"){};
    text_loader(const string &s) : loader(s){};
    virtual ~text_loader() {}

    storage_type &load(storage_type &storage);
};

#endif // TEXT_LOADER_H

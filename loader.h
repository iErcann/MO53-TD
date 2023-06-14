#ifndef LOADER_H
#define LOADER_H

#include "storage_type.h"
#include <string>
using namespace std;

class loader
{
protected:
    string source;

public:
    loader() : source("texte.txt"){};
    loader(const string &s) : source(s){};
    virtual ~loader(){};

    virtual storage_type &load(storage_type &storage) = 0;
};

#endif // LOADER_H

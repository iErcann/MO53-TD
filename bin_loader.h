#ifndef BIN_LOADER_H
#define BIN_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>

using namespace std;

class bin_loader : public loader
{
public:
    bin_loader() : loader("loader.bin"){};
    bin_loader(const string &s) : loader(s){};
    virtual ~bin_loader() {}

    storage_type &load(storage_type &storage);
};

#endif // BIN_LOADER_H

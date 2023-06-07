#include "bin_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std;

storage_type &bin_loader::load(storage_type &storage)
{
    // Create a copy of storage
    storage_type &returned_storage{storage};
    // Open the source bin file
    ifstream f{source, std::ios::binary};

    if (!f.is_open())
    {
        throw ios_base::failure("File cannot be opened for reading.");
    }
    // store in returned_storage the data of f
    double buffer;
    while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double)))
    {
        returned_storage.push_back(buffer);
    }

    return returned_storage;
}
#include "text_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std;

storage_type &text_loader::load(storage_type &storage)
{
    storage_type &returned_storage = storage;
    ifstream f(source);

    if (!f.is_open())
    {
        throw ios_base::failure("Can't open the file.");
    }

    string line;
    while (getline(f, line))
    {
        returned_storage.push_back(stold(line));
    }

    return returned_storage;
}

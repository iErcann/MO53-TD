/**

@file text_loader.cpp
@brief Implementation of the text_loader class.
*/
#include "text_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std;

/**

@brief Loads data from a text file into the storage.

This function reads each line from the specified text file

and converts it to a numerical value, which is then stored

in the provided storage container.

@param storage The storage container to load the data into.

@return The updated storage container with the loaded data.

@throws std::ios_base::failure If the file cannot be opened.
*/
storage_type& text_loader::load(storage_type& storage)
{
storage_type& returned_storage = storage;
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
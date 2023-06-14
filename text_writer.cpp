#include "text_writer.h"
#include "storage_type.h"
#include <iostream>
#include <fstream>

using namespace std;

text_writer &text_writer::operator=(const text_writer &p_text_writer)
{
    this->destination = p_text_writer.destination;
    return *this;
}

void text_writer::write(storage_type &storage)
{
    // Open the destination file
    ofstream f{destination};

    // Write into f the data stored in storage
    for (size_t i = 0; i < storage.size(); ++i)
    {
        f << storage.get_element(i) << endl;
    }
}
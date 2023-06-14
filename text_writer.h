#ifndef TEXT_WRITER_H
#define TEXT_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std;

/**
 * Text_writer implements the writer class to write data from a storage_type object to a text file.
 * @see writer
 * @see writer_type
 */
class text_writer : public Writer
{
private:
    /**
     * path to the destination text file
     */
    string destination;

public:
    /**
     * default constructor
     */
    text_writer() : destination("testoutput.txt"){};
    /**
     * constructor used to set the the path to the destination text file
     * @param s path for the source bin file used by the write function
     */
    text_writer(const string &p_destination) : destination(p_destination){};
    /**
     * copy constructor
     * @param p_text_writer text_writer to copy from
     */
    text_writer(const text_writer &p_text_writer) : destination(p_text_writer.destination){};
    /**
     * copy operator
     * @param p_text_writer text_writer to copy from
     */
    text_writer &operator=(const text_writer &p_text_writer);
    /**
     * destructor function
     */
    virtual ~text_writer(){};

    /**
     * Function that writes data from a storage_type object into a bin file.
     * Use to set the path to the destination bin file.
     * @param storage object that stores the data the write function uses
     */
    virtual void write(storage_type &storage);
};

#endif // TEXT_WRITER_H

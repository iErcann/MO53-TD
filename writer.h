#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"
#include <string>
#include <stdexcept>

using namespace std;

/**

@brief Exception used by the descendants of the writer class when a writing error occurs.
@see writer
**/
class WriteException : public runtime_error
{
public:
    /**
    @brief Constructor for WriteException.
    @param message The error message.
    **/
    WriteException(const string &message) : runtime_error(message) {}
};
/**

@brief The writer class is an abstract class used to write data from an object that inherits from storage_type.

@see storage_type
*/
class Writer
{
public:
    // @brief Default constructor for Writer.
    Writer() {}
    /**

    @brief Destructor for Writer.
    */
    virtual ~Writer() {}
    /**

    @brief Pure virtual function that writes data from a storage_type object.
    @param storage The object that stores the data to be written.
    @throws WriteException when a writing error occurs.
    */
    virtual void write(storage_type &storage) = 0;
};
#endif // WRITER_H
#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

#include <string>

class process
{ // raw pointers may be improved
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    Writer *_writer;

public:
    process(storage_type *stor, loader *load, calculation *calc, writer *write);
    void execute();
};
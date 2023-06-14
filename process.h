#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

/**
 * @brief Manage the data flux process
 * 
 */
class process {
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:
    /**
     * @brief Construct a new process object
     * 
     * @param stor ptr to a storage_type object
     * @param load ptr to a loader object
     * @param calc ptr to a calculation object
     * @param write ptr to a writer object
     */
    process(storage_type *stor, loader *load, calculation *calc, writer *write);
    
    /**
     * @brief Makes the calls to the different stages of the data flux
     * 
     */
    void execute();
};

#endif // PROCESS_H
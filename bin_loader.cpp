/**
 * @file bin_loader.h
 * @brief Definition of the bin_loader class.
 */

#ifndef BIN_LOADER_H
#define BIN_LOADER_H

#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

/**
 * @class bin_loader
 * @brief The bin_loader class loads data from a binary file into a storage_type container.
 */
class bin_loader
{
public:
    /**
     * @brief Loads data from a binary file into a storage_type container.
     * @param storage The storage_type container to load the data into.
     * @return The loaded storage_type container.
     * @throws std::ios_base::failure if the file cannot be opened for reading.
     */
    storage_type &load(storage_type &storage);
};

#endif // BIN_LOADER_H
/**
 * @file storage_type.h
 * @brief Definition of the storage_type class.
 */

#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

#include <vector>

using storage_type = std::vector<double>;

#endif // STORAGE_TYPE_H
#include "bin_loader.h"

/**
 * @brief Loads data from a binary file into a storage_type container.
 * @param storage The storage_type container to load the data into.
 * @return The loaded storage_type container.
 * @throws std::ios_base::failure if the file cannot be opened for reading.
 */
storage_type &bin_loader::load(storage_type &storage)
{
    // Create a copy of storage
    storage_type &returned_storage{storage};
    // Open the source bin file
    std::ifstream f{source, std::ios::binary};

    if (!f.is_open())
    {
        throw std::ios_base::failure("File cannot be opened for reading.");
    }

    // Read data from the binary file and store it in returned_storage
    double buffer;
    while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double)))
    {
        returned_storage.push_back(buffer);
    }

    return returned_storage;
}

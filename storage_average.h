#ifndef STORAGE_AVERAGE_H
#define STORAGE_AVERAGE_H

#include "storage_type.h"
#include "calculation.h"

/**

@brief The storage_average class calculates the average of data.
**/

class storage_average : public calculation
{
public:
    /*

    @brief Constructor.
    */
    storage_average() {}
    /**

    @brief Computes the average for all the data that is stored.
    The outcome swaps out the data kept in storage.
    @param storage The input data.
    */
    virtual void calculate(storage_type &storage);
};
#endif // STORAGE_AVERAGE_H
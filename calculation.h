#ifndef CALCULATION_H
#define CALCULATION_H

#include "storage_type.h"

/**

\class calculation
\brief Represents the calculation.
/

**/
class calculation
{
public:
    /*
    \brief Calculates a result based on the data stored in storage.
    The calculated result will replace the data stored in storage.
    \param storage The input data.
    */
    virtual void calculate(storage_type &storage) = 0;
};
#endif // CALCULATION_H
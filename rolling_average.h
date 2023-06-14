#ifndef ROLLING_AVERAGE_H
#define ROLLING_AVERAGE_H

#include "calculation.h"

class rolling_average : public calculation {
    int window_size;

public:
    rolling_average(int size);
    virtual double calculate(const storage_type& storage);
};

#endif  // ROLLING_AVERAGE_H

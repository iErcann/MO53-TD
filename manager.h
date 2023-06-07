#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "data_table.h"
#include "data_list.h"

class Manager
{
private:
    data_list _dataList;

public:
    Manager();

    data_list &getDataList();

    void createObjects();
    void runCalculations();
    void saveResults();
};

#endif // MANAGER_H

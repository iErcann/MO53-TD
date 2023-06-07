#include <iostream>
#include "data_table.h"
#include "data_list.h"
#include "manager.h"

using namespace std;

int main()
{
    Manager manager;

    manager.createObjects();
    manager.runCalculations();
    manager.saveResults();

    return 0;
}

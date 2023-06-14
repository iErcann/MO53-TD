#include "storage_average.h"
#include "storage_type.h"

void storage_average::calculate(storage_type &storage)
{
    // Check that the storage is not empty
    if (storage.size() == 0)
    {
        return;
    }

    // Calculate the avg of the data stored in the storage
    double sum = 0.0;
    for (int i = 0; i < storage.size(); ++i)
    {
        sum += storage.get_element(i);
    }
    // Calculate the average by dividing the sum by the number of elements
    double average = sum / storage.size();

    // Clear the storage and add the average as the only element
    storage.clear();
    storage.push_back(average);
}
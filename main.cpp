#include "list_storage.h"
#include <iostream>

int main()
{
    // Create an instance of list_storage
    list_storage storage;

    // Push some elements into the storage
    storage.push_back(5.3);
    storage.push_back(2.7);
    storage.push_back(8.1);

    // Get the size of the storage
    int size = storage.size();
    std::cout << "Size of the storage: " << size << std::endl;

    // Get and print the elements in the storage
    // for (int i = 0; i < size; i++)
    // {
    //     double element = storage.get_element(i);
    //     // std::cout << "Element at position " << i << ": " << element << std::endl;
    // }

    // Pop an element from the storage
    // double poppedElement = storage.pop_element();
    // std::cout << "Popped element: " << poppedElement << std::endl;

    // // Sort the storage in ascending order
    // storage.sort_storage(true);

    // // Get and print the sorted elements in the storage
    // std::cout << "Sorted elements in ascending order:" << std::endl;
    // for (int i = 0; i < size; i++)
    // {
    //     double element = storage.get_element(i);
    //     std::cout << "Element at position " << i << ": " << element << std::endl;
    // }

    return 0;
}

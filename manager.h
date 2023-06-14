/**

@file manager.h
@brief Header file for the Manager class.
*/
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "data_table.h"
#include "data_list.h"

/**

@class Manager
@brief Represents a manager for data operations.
*/
class Manager
{
private:
data_list _dataList; /**< The data list object. */
public:
/**
* @brief Default constructor for the Manager class.
*/
Manager()
/**
 * @brief Retrieves the data list.
 * @return A reference to the data list object.
 */
data_list &getDataList();

/**
 * @brief Creates objects.
 */
void createObjects();

/**
 * @brief Runs calculations.
 */
void runCalculations();

/**
 * @brief Saves results.
 */
void saveResults();
};

#endif // MANAGER_H
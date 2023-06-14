/**

@file data_table.h
@brief Contains the declaration of the data_table class and its member functions.
*/
#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <vector>
#include <string>

/**

@class data_table
@brief Represents a table of data.
*/
class data_table {
std::vector<double> _table;
public:
/**
* @brief Default constructor for the data_table class.
*/
data_table();
/**
 * @brief Destructor for the data_table class.
 */
~data_table() {}

/**
 * @brief Reads data from a text source and populates the table.
 * @param source The source file name.
 */
void from_text(const std::string &source);

/**
 * @brief Reads data from a binary source and populates the table.
 * @param source The source file name.
 */
void from_binary(const std::string &source);

/**
 * @brief Writes the table data to a text file.
 * @param destination The destination file name.
 */
void to_text(const std::string &destination);

/**
 * @brief Writes the table data to a binary file.
 * @param destination The destination file name.
 */
void to_binary(const std::string &destination);

/**
 * @brief Prints the data in the table.
 */
void print_data() const;

/**
 * @brief Computes the moving average of the table.
 * @param window_width The width of the moving average window.
 * @return A new instance of data_table containing the moving average.
 */
data_table moving_average(size_t window_width);

/**
 * @brief Sorts the table in ascending or descending order.
 * @param ascending If true, sorts the table in ascending order. If false, sorts in descending order.
 * @return A new instance of data_table containing the sorted table.
 */
data_table sort_table(bool ascending = true);

/**
 * @brief Computes the average of the values in the table.
 * @return A new instance of data_table containing the average as a single value.
 */
data_table average();

/**
 * @brief Computes the sum of the values in the table.
 * @return A new instance of data_table containing the sum as a single value.
 */
data_table table_sum();

/**
 * @brief Computes the count of the values in the table.
 * @return A new instance of data_table containing the count as a single value.
 */
data_table table_count();
};

#endif // DATA_TABLE_H
#include "gtest/gtest.h"
#include "data_table.h"

// Test case for loading data from a text file
TEST(DataTableTest, FromText) {
    data_table table;
    table.from_text("data.txt");

    EXPECT_EQ(table.size(), 5);
    EXPECT_EQ(table.get_element(0), 10.0);
    EXPECT_EQ(table.get_element(1), 20.0);
    EXPECT_EQ(table.get_element(2), 30.0);
    EXPECT_EQ(table.get_element(3), 40.0);
    EXPECT_EQ(table.get_element(4), 50.0);
}

// Test case for loading data from a binary file
TEST(DataTableTest, FromBinary) {
    data_table table;
    table.from_binary("data.bin");

    EXPECT_EQ(table.size(), 5);
    EXPECT_EQ(table.get_element(0), 10.0);
    EXPECT_EQ(table.get_element(1), 20.0);
    EXPECT_EQ(table.get_element(2), 30.0);
    EXPECT_EQ(table.get_element(3), 40.0);
    EXPECT_EQ(table.get_element(4), 50.0);
}

// Test case for saving data to a text file
TEST(DataTableTest, ToText) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    table.to_text("output.txt");

    // TODO: Add assertions to check the content of the output.txt file
}

// Test case for saving data to a binary file
TEST(DataTableTest, ToBinary) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    table.to_binary("output.bin");

    // TODO: Add assertions to check the content of the output.bin file
}

// Test case for computing moving average
TEST(DataTableTest, MovingAverage) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    data_table movingAvg = table.moving_average(3);

    EXPECT_EQ(movingAvg.size(), 3);
    EXPECT_EQ(movingAvg.get_element(0), 20.0);
    EXPECT_EQ(movingAvg.get_element(1), 30.0);
    EXPECT_EQ(movingAvg.get_element(2), 40.0);
}

// Test case for sorting the table in ascending order
TEST(DataTableTest, SortTableAscending) {
    data_table table;
    table.push_back(50.0);
    table.push_back(40.0);
    table.push_back(30.0);
    table.push_back(20.0);
    table.push_back(10.0);

    data_table sortedTable = table.sort_table(true);

    EXPECT_EQ(sortedTable.size(), 5);
    EXPECT_EQ(sortedTable.get_element(0), 10.0);
    EXPECT_EQ(sortedTable.get_element(1), 20.0);
    EXPECT_EQ(sortedTable.get_element(2), 30.0);
    EXPECT_EQ(sortedTable.get_element(3), 40.0);
    EXPECT_EQ(sortedTable.get_element(4), 50.0);
}

// Test case for sorting the table in descending order
TEST(DataTableTest, SortTableDescending) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    data_table sortedTable = table.sort_table(false);

    EXPECT_EQ(sortedTable.size(), 5);
    EXPECT_EQ(sortedTable.get_element(0), 50.0);
    EXPECT_EQ(sortedTable.get_element(1), 40.0);
    EXPECT_EQ(sortedTable.get_element(2), 30.0);
    EXPECT_EQ(sortedTable.get_element(3), 20.0);
    EXPECT_EQ(sortedTable.get_element(4), 10.0);
}

// Test case for computing the average of the table
TEST(DataTableTest, Average) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    data_table avgTable = table.average();

    EXPECT_EQ(avgTable.size(), 1);
    EXPECT_EQ(avgTable.get_element(0), 30.0);
}

// Test case for computing the sum of the table
TEST(DataTableTest, TableSum) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    data_table sumTable = table.table_sum();

    EXPECT_EQ(sumTable.size(), 1);
    EXPECT_EQ(sumTable.get_element(0), 150.0);
}

// Test case for computing the count of elements in the table
TEST(DataTableTest, TableCount) {
    data_table table;
    table.push_back(10.0);
    table.push_back(20.0);
    table.push_back(30.0);
    table.push_back(40.0);
    table.push_back(50.0);

    data_table countTable = table.table_count();

    EXPECT_EQ(countTable.size(), 1);
    EXPECT_EQ(countTable.get_element(0), 5.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

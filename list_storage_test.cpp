#include "gtest/gtest.h"
#include "list_storage.h"

// Test case for copying a list_storage object
TEST(ListStorageTest, CopyConstructorAndAssignmentOperator) {
    list_storage storage1;
    storage1.push_back(1.0);
    storage1.push_back(2.0);
    storage1.push_back(3.0);

    // Test copy constructor
    list_storage storage2(storage1);
    EXPECT_EQ(storage2.size(), 3);
    EXPECT_EQ(storage2.get_element(0), 1.0);
    EXPECT_EQ(storage2.get_element(1), 2.0);
    EXPECT_EQ(storage2.get_element(2), 3.0);

    // Test assignment operator
    list_storage storage3;
    storage3 = storage1;
    EXPECT_EQ(storage3.size(), 3);
    EXPECT_EQ(storage3.get_element(0), 1.0);
    EXPECT_EQ(storage3.get_element(1), 2.0);
    EXPECT_EQ(storage3.get_element(2), 3.0);
}

// Test case for pushing elements to the list_storage
TEST(ListStorageTest, PushBack) {
    list_storage storage;
    EXPECT_EQ(storage.size(), 0);

    storage.push_back(1.0);
    EXPECT_EQ(storage.size(), 1);
    EXPECT_EQ(storage.get_element(0), 1.0);

    storage.push_back(2.0);
    EXPECT_EQ(storage.size(), 2);
    EXPECT_EQ(storage.get_element(1), 2.0);
}

// Test case for popping an element from the list_storage
TEST(ListStorageTest, PopElement) {
    list_storage storage;
    storage.push_back(1.0);
    storage.push_back(2.0);
    storage.push_back(3.0);

    EXPECT_EQ(storage.pop_element(), 1.0);
    EXPECT_EQ(storage.size(), 2);
    EXPECT_EQ(storage.get_element(0), 2.0);

    EXPECT_EQ(storage.pop_element(), 2.0);
    EXPECT_EQ(storage.size(), 1);
    EXPECT_EQ(storage.get_element(0), 3.0);

    EXPECT_EQ(storage.pop_element(), 3.0);
    EXPECT_EQ(storage.size(), 0);
}

// Test case for sorting the list_storage
TEST(ListStorageTest, SortStorage) {
    list_storage storage;
    storage.push_back(3.0);
    storage.push_back(1.0);
    storage.push_back(2.0);

    // Sort in ascending order
    storage.sort_storage(true);
    EXPECT_EQ(storage.size(), 3);
    EXPECT_EQ(storage.get_element(0), 1.0);
    EXPECT_EQ(storage.get_element(1), 2.0);
    EXPECT_EQ(storage.get_element(2), 3.0);

    // Sort in descending order
    storage.sort_storage(false);
    EXPECT_EQ(storage.size(), 3);
    EXPECT_EQ(storage.get_element(0), 3.0);
    EXPECT_EQ(storage.get_element(1), 2.0);
    EXPECT_EQ(storage.get_element(2), 1.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

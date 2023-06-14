#include "gtest/gtest.h"
#include "text_loader.h"
#include "bin_loader.h"
#include "list_storage.h"

// Test case for loading data from a text file
TEST(LoaderTest, LoadTextFile) {
    text_loader loader("texte.txt");
    list_storage storage;

    EXPECT_NO_THROW({
        loader.load(storage);
    });

    EXPECT_EQ(storage.size(), 3);
    EXPECT_EQ(storage.get_element(0), "Hello");
    EXPECT_EQ(storage.get_element(1), "World");
    EXPECT_EQ(storage.get_element(2), "Test");
}

// Test case for loading data from a binary file
TEST(LoaderTest, LoadBinaryFile) {
    bin_loader loader("binary.bin");
    list_storage storage;

    EXPECT_NO_THROW({
        loader.load(storage);
    });

    EXPECT_EQ(storage.size(), 3);
    EXPECT_EQ(storage.get_element(0), "Binary");
    EXPECT_EQ(storage.get_element(1), "File");
    EXPECT_EQ(storage.get_element(2), "Test");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

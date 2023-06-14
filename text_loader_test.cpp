#include "gtest/gtest.h"
#include "text_loader.h"
#include "storage_type.h"

// Test case for successful loading of data from a text file
TEST(TextLoaderTest, Load_Success) {
    storage_type storage;
    text_loader loader("data.txt");

    EXPECT_NO_THROW({
        loader.load(storage);
    });

    // Verify the loaded data
    EXPECT_EQ(storage.size(), 3);
    EXPECT_DOUBLE_EQ(storage[0], 1.0);
    EXPECT_DOUBLE_EQ(storage[1], 2.0);
    EXPECT_DOUBLE_EQ(storage[2], 3.0);
}

// Test case for loading data from a non-existent file
TEST(TextLoaderTest, Load_FileNotFound) {
    storage_type storage;
    text_loader loader("nonexistent.txt");

    EXPECT_THROW({
        loader.load(storage);
    }, std::ios_base::failure);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

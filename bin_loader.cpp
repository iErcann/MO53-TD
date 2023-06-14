#include "bin_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std;

storage_type &bin_loader::load(storage_type &storage)
{
    // Create a copy of storage
    storage_type &returned_storage{storage};
    // Open the source bin file
    ifstream f{source, std::ios::binary};

    if (!f.is_open())
    {
        throw ios_base::failure("File cannot be opened for reading.");
    }
    // store in returned_storage the data of f
    double buffer;
    while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double)))
    {
        returned_storage.push_back(buffer);
    }

    return returned_storage;
}


#include <fstream>
#include <vector>
#include <stdexcept>
#include "bin_loader.h" // Assuming bin_loader.h contains the declaration of bin_loader class and storage_type typedef

// Fixture class for setting up common test data
class BinLoaderTest : public ::testing::Test {
protected:
    std::string test_file_name;

    void SetUp() override {
        // Create a test binary file with some sample data
        test_file_name = "test.bin";
        std::ofstream test_file(test_file_name, std::ios::binary);
        double sample_data[] = {1.0, 2.0, 3.0};
        test_file.write(reinterpret_cast<char*>(sample_data), sizeof(sample_data));
        test_file.close();
    }

    void TearDown() override {
        // Delete the test binary file
        std::remove(test_file_name.c_str());
    }
};

// Test case for successful file loading
TEST_F(BinLoaderTest, Load_Success) {
    bin_loader loader;
    storage_type storage;

    EXPECT_NO_THROW({
        storage = loader.load(storage, test_file_name);
    });

    // Verify the loaded data
    EXPECT_EQ(storage.size(), 3);
    EXPECT_DOUBLE_EQ(storage[0], 1.0);
    EXPECT_DOUBLE_EQ(storage[1], 2.0);
    EXPECT_DOUBLE_EQ(storage[2], 3.0);
}

// Test case for file open failure
TEST_F(BinLoaderTest, Load_FileOpenFailure) {
    bin_loader loader;
    storage_type storage;

    std::string non_existing_file = "non_existing.bin";

    EXPECT_THROW({
        storage = loader.load(storage, non_existing_file);
    }, std::ios_base::failure);
}
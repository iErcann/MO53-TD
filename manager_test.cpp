#include "gtest/gtest.h"
#include "data_list.h"
#include "manager.h"
#include <fstream>
#include <sstream>

// Test case for createObjects function in Manager class
TEST(ManagerTest, CreateObjects) {
    Manager manager;
    manager.createObjects();

    data_list& dataList = manager.getDataList();
    ASSERT_EQ(dataList.size(), 3);
    EXPECT_DOUBLE_EQ(dataList.get_value(0), 1.0);
    EXPECT_DOUBLE_EQ(dataList.get_value(1), 2.0);
    EXPECT_DOUBLE_EQ(dataList.get_value(2), 3.0);
}

// Test case for runCalculations function in Manager class
TEST(ManagerTest, RunCalculations) {
    Manager manager;
    manager.createObjects();

    testing::internal::CaptureStdout();
    manager.runCalculations();
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream expectedOutput;
    expectedOutput << "t:" << std::endl;
    expectedOutput << "1" << std::endl;
    expectedOutput << "2" << std::endl;
    expectedOutput << "3" << std::endl;
    expectedOutput << "t2:" << std::endl;
    expectedOutput << "1.5" << std::endl;
    expectedOutput << "2.5" << std::endl;

    EXPECT_EQ(output, expectedOutput.str());
}

// Test case for saveResults function in Manager class
TEST(ManagerTest, SaveResults) {
    Manager manager;
    manager.createObjects();

    std::ofstream outputFile("output_test.txt");

    if (outputFile.is_open()) {
        manager.saveResults();
        outputFile.close();

        std::ifstream inputFile("output_test.txt");
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        inputFile.close();

        std::stringstream expectedOutput;
        expectedOutput << "1" << std::endl;
        expectedOutput << "2" << std::endl;
        expectedOutput << "3" << std::endl;

        EXPECT_EQ(buffer.str(), expectedOutput.str());
    }
    else {
        FAIL() << "Unable to open output_test.txt for writing.";
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

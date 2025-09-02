#include "gtest/gtest.h"
#include  "Vector/myvector.h"
class VectorTest : public ::testing::Test {
protected:

   Vector<int> dataInput={1,2,3,4,5,7};
   Vector<std::string> dataString={"1232","sdafa","kska"};
};

TEST_F(VectorTest,check_of_size) {
    ASSERT_EQ(dataInput.size_(), 6);
    ASSERT_EQ(dataString.size_(), 3);
}
TEST_F(VectorTest,check_of_element) {
    ASSERT_EQ(dataInput.at(3), 4);
    ASSERT_EQ(dataString.at(2), "kska");
}
TEST_F(VectorTest,check_of_capas) {
    ASSERT_EQ(dataInput.capacity_(),6);
    ASSERT_EQ(dataString.capacity_(), 3);
}
TEST_F(VectorTest,push_back) {
    dataInput.push_back(1);
    dataInput.push_back(2);
    dataInput.push_back(3);
    ASSERT_EQ(dataInput.size_(),9);
    ASSERT_EQ(dataInput.capacity_(),12);
    ASSERT_EQ(dataInput.at(7),2);
    dataString.push_back());
}
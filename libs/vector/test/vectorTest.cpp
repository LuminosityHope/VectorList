#include "vector/myvector.h"

#include "gtest/gtest.h"


using namespace myvector;

TEST(VectorTest,sizeCap_sizeCapString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
}
TEST(VectorTest,pushBack_pushBackString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    dataInput2.push_back("home");
    dataOutput2.push_back("home");
    dataInput.push_back(1);
    dataOutput.push_back(1);
    ASSERT_EQ(dataInput.size_(),dataOutput.size());
    ASSERT_EQ(dataInput.capacity_(),dataOutput.capacity());
    ASSERT_EQ(dataInput[6],dataOutput[6]);
    ASSERT_EQ(dataInput.at(6),dataOutput.at(6));
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
    ASSERT_EQ(dataInput2[4],dataOutput2[4]);
    ASSERT_EQ(dataInput2.at(4),dataOutput2.at(4));
}

TEST(VectorTest,popBack_popBackString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    dataInput2.pop_back();
    dataOutput2.pop_back();
    dataInput.pop_back();
    dataOutput.pop_back();
    ASSERT_EQ(dataInput.size_(),dataOutput.size());
    ASSERT_EQ(dataInput.capacity_(),dataOutput.capacity());
    ASSERT_EQ(dataInput[5],dataOutput[5]);
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
    ASSERT_EQ(dataInput[2],dataOutput[2]);
}
TEST(VectorTest,intReserve_stringReserve_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    dataInput2.reserve(15);
    dataOutput2.reserve(15);
    dataInput.reserve(10);
    dataOutput.reserve(10);
    ASSERT_EQ(dataInput.size_(),dataOutput.size());
    ASSERT_EQ(dataInput.capacity_(),dataOutput.capacity());
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
}
TEST(VectorTest,emplaceBack_emplaceBackString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    dataInput.emplace_back(1);
    dataOutput.emplace_back(1);
    dataInput2.emplace_back("home");
    dataOutput2.emplace_back("home");
    ASSERT_EQ(dataInput2.size_(),dataOutput2.size());
    ASSERT_EQ(dataInput2.capacity_(),dataOutput2.capacity());
    ASSERT_EQ(dataInput2.at(4),dataOutput2.at(4));
    ASSERT_EQ(dataInput.size_(),dataOutput.size());
    ASSERT_EQ(dataInput.capacity_(),dataOutput.capacity());
    ASSERT_EQ(dataInput[6],dataOutput[6]);
}
TEST(VectorTest,backFront_backFrongString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataOutput2={"hello","world","hello","world"};
    std::vector dataInput2={"hello","world","hello","world"};
    ASSERT_EQ(dataInput.back(),dataOutput.back());
    ASSERT_EQ(dataInput.front(),dataOutput.front());
    ASSERT_EQ(dataInput2.back(),dataOutput2.back());
    ASSERT_EQ(dataInput2.front(),dataOutput2.front());
}
TEST(VectorTest,squareBrackets_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<std::string> dataInput2={"hello","world","hello","world"};
    std::vector dataOutput2={"hello","world","hello","world"};
    ASSERT_EQ(dataInput[3],dataOutput[3]);
    ASSERT_EQ(dataInput2[2],dataOutput2[2]);
}
TEST(VectorTest,methodAt_SuccessCompareThrowWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    EXPECT_THROW(dataInput.at(7),std::out_of_range);
    EXPECT_THROW(dataOutput.at(7),std::out_of_range);
}
TEST(VectorTest,copy_CopyString_SuccessCompareWithStdVector) {
    Vector<int> dataInput={1,2,3,4,5,7};
    std::vector dataOutput={1,2,3,4,5,7};
    Vector<int> copy(dataInput);
    std::vector copyOut(dataOutput);
    ASSERT_EQ(copy.size_(),copyOut.size());
    ASSERT_EQ(copy.capacity_(),copyOut.capacity());
    ASSERT_EQ(copy.at(5),copyOut.at(5));
}
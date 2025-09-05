#include "list/list.h"

#include "gtest/gtest.h"

#include <list>

using  namespace linkedlist;

TEST(ListTest,frontBackSize_frontBackSizeString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<std::string> dataInput2={"Home","Popi","Home","Popi"};
    std::list<std::string> dataOutput2={"Home","Popi","Home","Popi"};
    ASSERT_EQ(dataInput.front(),dataOutput.front());
    ASSERT_EQ(dataInput.back(),dataOutput.back());
    ASSERT_EQ(dataInput.size(),dataOutput.size());
    ASSERT_EQ(dataInput2.front(),dataOutput2.front());
    ASSERT_EQ(dataInput2.back(),dataOutput2.back());
    ASSERT_EQ(dataInput2.size(),dataOutput2.size());
}
TEST(ListTest,pushFront_pushStringData_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<std::string> dataInput2={"Home","Popi","Home","Popi"};
    std::list<std::string> dataOutput2={"Home","Popi","Home","Popi"};
    dataInput2.push_front("Koko");
    dataOutput2.push_front("Koko");
    ASSERT_EQ(dataInput2.front(),dataOutput2.front());
    ASSERT_EQ(dataInput2.size(),dataOutput2.size());
    dataInput.push_front(2);
    dataOutput.push_front(2);
    ASSERT_EQ(dataInput.front(),dataOutput.front());
    ASSERT_EQ(dataInput.size(),dataOutput.size());
}
TEST(ListTest,pushBack_pushBackString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<std::string> dataInput2={"Home","Popi","Home","Popi"};
    std::list<std::string> dataOutput2={"Home","Popi","Home","Popi"};
    dataInput.push_back(4);
    dataOutput.push_back(4);
    dataInput2.push_back("Koko");
    dataOutput2.push_back("Koko");
    ASSERT_EQ(dataInput.size(),dataOutput.size());
    ASSERT_EQ(dataInput.back(),dataOutput.back());
    ASSERT_EQ(dataInput2.size(),dataOutput2.size());
    ASSERT_EQ(dataInput2.back(),dataOutput2.back());
}
TEST(ListTest,copy_copyString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<int> lstInput=dataInput;
    std::list<int> lstOutput=dataOutput;
    ASSERT_EQ(lstInput.size(),lstOutput.size());
    ASSERT_EQ(lstInput.front(),lstOutput.front());
    ASSERT_EQ(lstInput.back(),lstOutput.back());
}
TEST(ListTest,emplaceBack_emplaceBackString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    dataInput.emplace_back(4);
    dataOutput.emplace_back(4);
    ASSERT_EQ(dataInput.size(),dataOutput.size());
    ASSERT_EQ(dataInput.back(),dataOutput.back());
}
TEST(ListTest,popBack_popBackString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<std::string> dataInput2={"Home","Popi","Home","Popi"};
    std::list<std::string> dataOutput2={"Home","Popi","Home","Popi"};
    dataInput2.pop_back();
    dataOutput2.pop_back();
    dataInput.pop_back();
    dataOutput.pop_back();
    ASSERT_EQ(dataInput.size(),dataOutput.size());
    ASSERT_EQ(dataInput.back(),dataOutput.back());
    ASSERT_EQ(dataInput2.size(),dataOutput2.size());
    ASSERT_EQ(dataInput2.back(),dataOutput2.back());
}
TEST(ListTest,popFront_popFrontString_SuccessCompareWithStdList) {
    LinkedList<int> dataInput={1,2,3,4,5,7};
    std::list<int> dataOutput={1,2,3,4,5,7};
    LinkedList<std::string> dataInput2={"Home","Pipi","Home","Popi"};
    std::list<std::string> dataOutput2={"Home","Pipi","Home","Popi"};
    dataInput.pop_front();
    dataOutput.pop_front();
    dataInput2.pop_front();
    dataOutput2.pop_front();
    ASSERT_EQ(dataInput.size(),dataOutput.size());
    ASSERT_EQ(dataInput.front(),dataOutput.front());
    ASSERT_EQ(dataInput2.size(),dataOutput2.size());
    ASSERT_EQ(dataInput2.front(),dataOutput2.front());
}
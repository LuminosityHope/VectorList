#include "../Include/myvector.h"
#include "gtest/gtest.h"
#include<string>
class VectorTest : public ::testing::Test {
protected:
    virtual void SetUp(void) {
        Vector<int> dataInput={1,2,3,4,5,7};
    }
    Vector<int> dataInput;

};

TEST_F(VectorTest,checkOfSize) {
    ASSERT_EQ(dataInput.size_(), 6);
}
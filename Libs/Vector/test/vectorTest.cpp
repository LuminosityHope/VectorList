#include "../Include/myvector.h"
#include "gtest/gtest.h"

class VectorTest : public ::testing::Test {
protected:

    Vector<int> dataInput={1,2,3,4,5,7};

};

TEST_F(VectorTest,checkOfSize) {
    ASSERT_EQ(dataInput.size_(), 6);
}

#include "../../lib/ds/MonotonyQueue.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(MonotonyQueueTest, MonotonyQueueTest1)
{
    std::vector<int32_t> vin{1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int32_t> vout{-1, -1, 2, 3, 3, 3, 5, 5};
    agoh::MonotonyQueue mq(vin.begin(), vin.end(), 3);
    ASSERT_EQ(mq.get(), vout);
}

TEST(MonotonyQueueTest, MonotonyQueueTest2)
{
    std::vector<int32_t> vin{1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int32_t> vout{-1, -1, 1, 1, 4, 4, 6, 7};
    agoh::MonotonyQueue<std::greater<>> mq(vin.begin(), vin.end(), 3);
    ASSERT_EQ(mq.get(), vout);
}

#include <gtest/gtest.h>
#include "neonlab.h"

template <int N>
struct aligned_buf {
    uint8_t raw[2 * N];
    uint8_t* get() { return (uint8_t*)(((((uint64_t)raw - 1) >> 4) + 1) << 4); }
    uint8_t& operator[](int i) { return *(get() + i); }
    void set_zero() { memset(get(), 0, N); }
};

struct neonlab_test : ::testing::Test {};

TEST_F(neonlab_test, contains_all_zeros) {
    aligned_buf<32> buf{};
    EXPECT_TRUE(testz(buf.get(), 32));
};

TEST_F(neonlab_test, not_all_zeros) {
    aligned_buf<32> buf{};
    buf[4] = 1;
    EXPECT_FALSE(testz(buf.get(), 32));

    buf[0] = 0;
    buf[7] = 1;
    EXPECT_FALSE(testz(buf.get(), 32));

    buf[7] = 0;
    buf[15] = 1;
    EXPECT_FALSE(testz(buf.get(), 32));

    buf[15] = 0;
    buf[23] = 1;
    EXPECT_FALSE(testz(buf.get(), 32));

    buf[23] = 0;
    buf[31] = 1;
    EXPECT_FALSE(testz(buf.get(), 32));
};

TEST_F(neonlab_test, comprehensive_nonzero_test) {
    aligned_buf<32> buf{};
    for (int i = 0; i < 32; ++i) {
        buf.set_zero();
        buf[i] = 0xff;
        EXPECT_FALSE(testz(buf.get(), 32));
    }
}

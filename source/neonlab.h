#include <cassert>

const void* memnz_naive(const void* x, int len) {
    auto p = (uint8_t*)x;
    auto end = p + len;

    while (p < end && *p) {
        ++p;
    }

    return p == end ? nullptr : p;
    ;
}

uint32_t testnz(const void* x, int len) {
    assert(((uint64_t)x & 0xf) == 0);
    uint32_t result;
    asm volatile(R"(
        mov r2, #16
        vld1.8 {q0}, [%1]
        add %1, #16
        vld1.8 {q1}, [%1]
        vorr q2, q0, q1
        vorr d0, d4, d5
        vmov.32 r0, d0[0]
        vmov.32 r1, d0[1]
        orr %0, r0, r1
    )"
                 : "=r"(result)
                 : "r"(x), "r"(len));
    return result;
}

uint32_t testz(const void* x, int len) { return !testnz(x, len); }

const void* memnz_neon(const void* x, int len) {
    const void* result;
    return result;
}

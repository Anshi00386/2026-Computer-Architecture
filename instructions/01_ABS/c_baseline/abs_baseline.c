#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

// ABS 核心函數：計算 32-bit 有號整數之絕對值
int32_t abs_custom(int32_t rs1) {
    // 邊界條件處理：-2^31 (INT32_MIN) 溢位 wrap-around 為 -2^31
    if (rs1 == INT32_MIN) {
        return INT32_MIN;
    }
    return (rs1 < 0) ? -rs1 : rs1;
}

// 測試向量結構體
typedef struct {
    int32_t input;
    int32_t expected;
    const char *description;
} TestCase;

int main() {
    // 至少 10 組測試向量 (含正數、負數、零、極值與邊界條件)
    TestCase test_cases[10] = {
        {-5,          5,           "一般負數"},
        {0,           0,           "零 (Zero)"},
        {INT32_MIN,   INT32_MIN,   "邊界值：INT32_MIN (-2147483648)"},
        {INT32_MAX,   INT32_MAX,   "邊界值：INT32_MAX (2147483647)"},
        {100,         100,         "一般正數"},
        {-100,        100,         "一般負數"},
        {-1,          1,           "相鄰零負數"},
        {1,           1,           "相鄰零正數"},
        {-1234567,    1234567,     "大數負數"},
        {1234567,     1234567,     "大數正數"}
    };

    int passed = 0;
    int total = 10;

    printf("=========================================\n");
    printf("         CP1: ABS C Baseline Test        \n");
    printf("=========================================\n");

    for (int i = 0; i < total; i++) {
        int32_t result = abs_custom(test_cases[i].input);
        bool is_pass = (result == test_cases[i].expected);

        printf("[%s] Test %2d: %s\n", is_pass ? "PASS" : "FAIL", i + 1, test_cases[i].description);
        printf("     Input: %d (0x%08X)\n", test_cases[i].input, (uint32_t)test_cases[i].input);
        printf("     Expected: %d | Got: %d\n\n", test_cases[i].expected, result);

        if (is_pass) passed++;
    }

    printf("Test Summary: %d / %d Passed.\n", passed, total);
    return (passed == total) ? 0 : 1;
}
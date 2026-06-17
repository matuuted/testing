// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "build/vendor/unity/src/unity.h"
#include "src/dispenser_logic.h"
#include "src/hx711_reader.h"
#include "mock_hx711_reader.h"

TEST_SOURCE_FILE("hx711_logic.c")

void setUp(void)
{
    mock_hx711_reader_Init();
}

void tearDown(void)
{
    mock_hx711_reader_Verify();
    mock_hx711_reader_Destroy();
}

void test_read_weight_converts(void)
{
    hx711_reader_ready_CMockExpectAndReturn(29, 0U,
   1
   );
    hx711_reader_read_CMockExpectAndReturn(30, 0U, 42000);

    float g = read_weight_grams(0U, 0, 420.0f);

    UnityAssertFloatsWithin((UNITY_FLOAT)((0.01f)), (UNITY_FLOAT)((100.0f)), (UNITY_FLOAT)((g)), (
   ((void *)0)
   ), (UNITY_UINT)(34));
}

void test_read_weight_timeout_returns_error(void)
{
    hx711_reader_ready_CMockExpectAndReturn(40, 0U,
   0
   );

    float g = read_weight_grams(0U, 0, 420.0f);

    UnityAssertFloatsWithin((UNITY_FLOAT)((0.01f)), (UNITY_FLOAT)((-1.0f)), (UNITY_FLOAT)((g)), (
   ((void *)0)
   ), (UNITY_UINT)(44));
}
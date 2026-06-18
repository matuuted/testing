/**
  * @file  test_hx711_logic.c
  * Tests de la lectura de peso usando un mock en lugar del driver del HX711. 
 */

#include "unity.h"
#include "dispenser_logic.h"
#include "hx711_reader.h"
#include "mock_hx711_reader.h"

TEST_SOURCE_FILE("hx711_logic.c")

#define HX711_CH_TANK_  0

void setUp(void)
{
    mock_hx711_reader_Init();
}

void tearDown(void)
{
    mock_hx711_reader_Verify();
    mock_hx711_reader_Destroy();
}

/* Lectura valida: el sensor devuelve 42000 y se obtienen 100 g */
void test_read_weight_converts(void)
{
    hx711_reader_ready_ExpectAndReturn(HX711_CH_TANK_, true);
    hx711_reader_read_ExpectAndReturn(HX711_CH_TANK_, 42000);

    float g = read_weight_grams(HX711_CH_TANK_, 0, 420.0f);

    TEST_ASSERT_FLOAT_WITHIN(0.01f, 100.0f, g);
}

/* Timeout del sensor -> devuelve -1. */
void test_read_weight_timeout_returns_error(void)
{
    hx711_reader_ready_ExpectAndReturn(HX711_CH_TANK_, false);

    float g = read_weight_grams(HX711_CH_TANK_, 0, 420.0f);

    TEST_ASSERT_FLOAT_WITHIN(0.01f, -1.0f, g);
}

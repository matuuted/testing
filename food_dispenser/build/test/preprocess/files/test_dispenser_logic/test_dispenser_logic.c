// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "build/vendor/unity/src/unity.h"
#include "src/dispenser_logic.h"

void setUp(void)
{}
void tearDown(void)
{}

void test_sm_init_boot(void)
{
    UnityAssertEqualNumber((UNITY_INT)((ST_IDLE)), (UNITY_INT)((sm_next_state(ST_INIT, EVT_NONE,
   1
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_ERROR)), (UNITY_INT)((sm_next_state(ST_INIT, EVT_NONE,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);
}

void test_sm_idle_to_dispensing(void)
{
    UnityAssertEqualNumber((UNITY_INT)((ST_DISPENSING)), (UNITY_INT)((sm_next_state(ST_IDLE, EVT_BUTTON,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_DISPENSING)), (UNITY_INT)((sm_next_state(ST_IDLE, EVT_SCHEDULED,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_IDLE)), (UNITY_INT)((sm_next_state(ST_IDLE, EVT_NONE,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);
}

void test_sm_dispensing_and_terminal_states(void)
{
    UnityAssertEqualNumber((UNITY_INT)((ST_IDLE)), (UNITY_INT)((sm_next_state(ST_DISPENSING, EVT_NONE,
   0
   ,
   1
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_DISPENSING)), (UNITY_INT)((sm_next_state(ST_DISPENSING, EVT_BUTTON,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_ERROR)), (UNITY_INT)((sm_next_state(ST_ERROR, EVT_BUTTON,
   1
   ,
   1
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((ST_INIT)), (UNITY_INT)((sm_next_state((SM_State)99, EVT_NONE,
   0
   ,
   0
   ))), (
   ((void *)0)
   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);
}

void test_convert_to_grams(void)
{
    UnityAssertFloatsWithin((UNITY_FLOAT)((0.01f)), (UNITY_FLOAT)((100.0f)), (UNITY_FLOAT)((hx711_convert_to_grams(42000, 0, 420.0f))), (
   ((void *)0)
   ), (UNITY_UINT)(44));
    UnityAssertFloatsWithin((UNITY_FLOAT)((0.01f)), (UNITY_FLOAT)((0.0f)), (UNITY_FLOAT)((hx711_convert_to_grams(-4200, 0, 420.0f))), (
   ((void *)0)
   ), (UNITY_UINT)(45));
    UnityAssertFloatsWithin((UNITY_FLOAT)((0.01f)), (UNITY_FLOAT)((50.0f)), (UNITY_FLOAT)((hx711_convert_to_grams(42000, 21000, 420.0f))), (
   ((void *)0)
   ), (UNITY_UINT)(46));
}
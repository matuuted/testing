/**
 * @file  test_dispenser_logic.c
 * Tests de la logica del dispensador. Se prueban las transiciones de la SM y la conversion de peso.
 */

#include "unity.h"
#include "dispenser_logic.h"

void setUp(void)    {}
void tearDown(void) {}

/* SM: INIT pasa a IDLE si el boot esta ok, y a ERROR si el boot falla. */
void test_sm_init_boot(void)
{
    TEST_ASSERT_EQUAL(ST_IDLE,  sm_next_state(ST_INIT, EVT_NONE, true, false));
    TEST_ASSERT_EQUAL(ST_ERROR, sm_next_state(ST_INIT, EVT_NONE, false, false));
}

/* SM: el boton o el evento programado arrancan el disoensado. Sin evento, sigue en IDLE. */
void test_sm_idle_to_dispensing(void)
{
    TEST_ASSERT_EQUAL(ST_DISPENSING, sm_next_state(ST_IDLE, EVT_BUTTON, false, false));
    TEST_ASSERT_EQUAL(ST_DISPENSING, sm_next_state(ST_IDLE, EVT_SCHEDULED, false, false));
    TEST_ASSERT_EQUAL(ST_IDLE, sm_next_state(ST_IDLE, EVT_NONE, false, false));
}

/*
 * SM: cubre las salidas de DISPENSING y los estados terminales.
 *  - DISPENSING: solo pasa a IDLE cuando la dispensa termina.
 *  - ERROR: es terminal, se queda en ERROR ante cualquier evento.
 *  - Estado desconocido: vuelve a INIT por el caso default.
 */
void test_sm_dispensing_and_terminal_states(void)
{
    TEST_ASSERT_EQUAL(ST_IDLE, sm_next_state(ST_DISPENSING, EVT_NONE, false, true));
    TEST_ASSERT_EQUAL(ST_DISPENSING, sm_next_state(ST_DISPENSING, EVT_BUTTON, false, false));
    TEST_ASSERT_EQUAL(ST_ERROR, sm_next_state(ST_ERROR, EVT_BUTTON, true, true));
    TEST_ASSERT_EQUAL(ST_INIT, sm_next_state((SM_State)99, EVT_NONE, false, false));
}

/* Conversion de valores leidos a gramos: conversion de un valor normal, recorte negativo y valor con offset de tara. */
void test_convert_to_grams(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 100.0f, hx711_convert_to_grams(42000, 0, 420.0f));
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 0.0f,   hx711_convert_to_grams(-4200, 0, 420.0f));
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 50.0f,  hx711_convert_to_grams(42000, 21000, 420.0f));
}
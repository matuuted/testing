/**
 * @file  dispenser_logic.c
 * Contiene la transicion de la maquina de estados y conversion de peso del dispensador.
 */

#include "dispenser_logic.h"

/* -------------------------------------------------------------------------- */
/* SM                                                                         */
/* -------------------------------------------------------------------------- */

SM_State sm_next_state(SM_State state, SM_Event evt, bool boot_ok, bool dispense_done)
{
    switch (state)
    {
        case ST_INIT:
            return boot_ok ? ST_IDLE : ST_ERROR;

        case ST_IDLE:
            if (evt == EVT_BUTTON || evt == EVT_SCHEDULED)
                return ST_DISPENSING;
            return ST_IDLE;

        case ST_DISPENSING:
            return dispense_done ? ST_IDLE : ST_DISPENSING;

        case ST_ERROR:
            return ST_ERROR;

        default:
            return ST_INIT;
    }
}


/* -------------------------------------------------------------------------- */
/* HX711                                                                      */
/* -------------------------------------------------------------------------- */
float hx711_convert_to_grams(int32_t raw, int32_t offset, float scale)
{
    float result = (float)(raw - offset) / scale;

    /* Si la lectura cae por debajo de -5 g se considera invalida y se reporta 0. De lo contrario se devuelve el valor calculado. */
    return (result < -5.0f) ? 0.0f : result;
}

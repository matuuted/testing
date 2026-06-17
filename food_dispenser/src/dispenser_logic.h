#ifndef DISPENSER_LOGIC_H
#define DISPENSER_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

/* Estados de la SM */
typedef enum {
    ST_INIT       = 0,
    ST_IDLE       = 1,
    ST_DISPENSING = 2,
    ST_ERROR      = 3,
} SM_State;

/* Eventos de la SM */
typedef enum {
    EVT_NONE      = 0,
    EVT_BUTTON    = 1,
    EVT_SCHEDULED = 2,
} SM_Event;

/* Devuelve el siguiente estado de la FSM dependiendo del estado actual, el evento y las banderas de HW. */
SM_State sm_next_state(SM_State state, SM_Event evt, bool boot_ok, bool dispense_done);

/* Convierte una lectura del HX711 a gramos. Las lecturas por debajo de -5 g se fuerzan a 0. */
float hx711_convert_to_grams(int32_t raw, int32_t offset, float scale);

/* Lee una celda de carga y convierte el valor a gramos. Si hay timeout, devuelve -1. */
float read_weight_grams(uint8_t ch, int32_t offset, float scale);

#endif /* DISPENSER_LOGIC_H */

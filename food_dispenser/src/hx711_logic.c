/**
 * @file  hx711_logic.c
 * Contiene la logica de lectura de peso del HX711.
 * Esta funcion depende del hardware, por lo que en los tests el driver se reemplaza por un mock.
 */

#include "dispenser_logic.h"
#include "hx711_reader.h"

float read_weight_grams(uint8_t ch, int32_t offset, float scale)
{
    /* Si el sensor no tiene la información lista dentro del timeout -> error (HX711_TIMEOUT) */
    if (!hx711_reader_ready(ch))
        return -1.0f;

    int32_t raw = hx711_reader_read(ch);
    return hx711_convert_to_grams(raw, offset, scale);
}

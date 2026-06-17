#ifndef HX711_READER_H
#define HX711_READER_H

#include <stdint.h>
#include <stdbool.h>

/* Lee un valor con signo del HX711. Canal 0 = tanque, 1 = plato. */
int32_t hx711_reader_read(uint8_t ch);

/* Devuelve true si el HX711 respondio en tiempo. */
bool hx711_reader_ready(uint8_t ch);

#endif /* HX711_READER_H */

#ifndef _TESLA_CAR_H
#define _TESLA_CAR_H 

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <car_common.h>
#include <electric_car.h>

typedef struct tesla_electric_car {
    electric_car_ctx_t *parent;

    // tesla_electric_car func
    void (*autopilot)();

    // tesla_electric_car property
    int has_ludicrous_mode;
} tesla_electric_car_ctx_t;



tesla_electric_car_ctx_t* tesla_electric_car_constructor();
void tesla_electric_car_destructor(tesla_electric_car_ctx_t* t_car_obj);

#endif  // _TESLA_CAR_H
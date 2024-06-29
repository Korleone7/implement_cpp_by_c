#ifndef _OIL_CAR_H
#define _OIL_CAR_H 

#include <car_common.h>

typedef struct oil_car {
    car_common_ctx_t *parent;

    // oil_car func
    float (*get_fuel_efficiency)(int oil_car_type);
} oil_car_ctx_t;

oil_car_ctx_t* oil_car_constructor();
void oil_car_destructor(oil_car_ctx_t* o_car_obj);

#endif  // _OIL_CAR_H
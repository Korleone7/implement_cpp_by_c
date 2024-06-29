#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <car_common.h>
#include <oil_car.h>



static void oid_car_get_fuel_efficiency() {
    // implement the function
}


oil_car_ctx_t* oil_car_constructor() {
    oil_car_ctx_t* o_car_obj = (oil_car_ctx_t*)malloc(sizeof(oil_car_ctx_t));
    if (o_car_obj != NULL) {
        o_car_obj->parent = car_common_constructor();
        o_car_obj->get_fuel_efficiency = oid_car_get_fuel_efficiency;
    }
    return o_car_obj;
}


void oil_car_destructor(oil_car_ctx_t* o_car_obj) {
    if (NULL != o_car_obj) {
        // call the destructor of the parent class
        car_common_destructor(o_car_obj->parent);

        // free the memory of the current object
        free(o_car_obj);
    }
}

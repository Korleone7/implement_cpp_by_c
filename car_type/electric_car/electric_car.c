#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <car_common.h>
#include <electric_car.h>



static int electric_car_get_charge_timecost(electric_car_ctx_t* this) {
    int timecost = (int)(this->battery_capacity / this->charge_speed);

    return timecost;
}


static void electric_car_check_battery_status() {
    // implement the function
}


static void electric_car_start() {
    // implement the function
}

electric_car_ctx_t* electric_car_constructor() {
    electric_car_ctx_t* e_car_obj = (electric_car_ctx_t*)malloc(sizeof(electric_car_ctx_t));
    if (e_car_obj != NULL) {
        e_car_obj->parent = car_common_constructor();
        e_car_obj->battery_capacity = 100; 
        e_car_obj->charge_speed = 20;
        e_car_obj->get_battery_charge_timecost = electric_car_get_charge_timecost;
        e_car_obj->check_battery_status = electric_car_check_battery_status;

        e_car_obj->parent->start = electric_car_start;
    }
    return e_car_obj;
}

void electric_car_destructor(electric_car_ctx_t* e_car_obj) {
    if (NULL != e_car_obj) {
        // call the destructor of the parent class
        car_common_destructor(e_car_obj->parent);

        // free the memory of the current object
        free(e_car_obj);
    }
}


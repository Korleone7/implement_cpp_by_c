#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <event_bus.h>

#include <electric_car.h>
#include <tesla_electric_car.h>

static void tesla_electric_car_autopilot() {
    // implement the function
}

static void tesla_electric_car_check_battery_status() {
    // implement the function
}

static void tesla_electric_car_stop() {
    // implement the function
}


static error_t tesla_electric_car_handle_test_event(data, data_len) {
    // implement the function
}


static error_t tesla_electric_car_handle_event(event_t evt, void *data, int data_len) {
    error_t err = SUCCESS;

    do {
        switch (evt) {
            case EVENT_TEST: {
                err = tesla_electric_car_handle_test_event(data, data_len);
                break;
            }
            default: {
                break;
            }
        }
    } while (0);
    
    return err;
}

tesla_electric_car_ctx_t* tesla_electric_car_constructor() {
    tesla_electric_car_ctx_t* t_car_obj = (tesla_electric_car_ctx_t*)malloc(sizeof(tesla_electric_car_ctx_t));

    if(NULL != t_car_obj) {
        t_car_obj->parent = electric_car_constructor();
        t_car_obj->has_ludicrous_mode = 1;
        t_car_obj->autopilot = tesla_electric_car_autopilot;

        // update parent func pointer for simulate cpp override
        t_car_obj->parent->check_battery_status = tesla_electric_car_check_battery_status;
        t_car_obj->parent->parent->stop = tesla_electric_car_stop; 
    }

    event_register_handler(EVENT_TEST, tesla_electric_car_handle_event);

    return t_car_obj;
}

void tesla_electric_car_destructor(tesla_electric_car_ctx_t* t_car_obj) {
    if(NULL != t_car_obj) {
        // call the destructor of the parent class
        electric_car_destructor(t_car_obj->parent);

        // free the memory of the current object
        free(t_car_obj);
    }

    event_deregister_handler(EVENT_TEST, tesla_electric_car_handle_event);
}

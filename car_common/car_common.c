#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <car_common.h>

static void car_start() {
    // implement the function
}

static void car_set_speed(int val) {
    // implement the function
}

static void car_stop() {
    // implement the function
}
	
car_common_ctx_t* car_common_constructor() {
    car_common_ctx_t* car_com_obj = malloc(sizeof(car_common_ctx_t));

    if (car_com_obj != NULL) {
        // initialize the function pointers
        car_com_obj->start = car_start;
        car_com_obj->set_speed = car_set_speed;
        car_com_obj->stop = car_stop;
    }

    return car_com_obj;
}


void car_common_destructor(car_common_ctx_t* car_com_obj) {
    if (NULL != car_com_obj) {
        free(car_com_obj);
    }
}

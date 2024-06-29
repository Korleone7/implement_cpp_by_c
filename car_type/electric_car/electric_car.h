#ifndef _ELECTRIC_CAR_H
#define _ELECTRIC_CAR_H 

#include <car_common.h>

typedef struct electric_car {
    car_common_ctx_t *parent;

    // electric car func
    int (*get_battery_charge_timecost)(electric_car_ctx_t *);
    void (*check_battery_status)();

    // electric car property
    int battery_capacity;
    int charge_speed;
} electric_car_ctx_t;

electric_car_ctx_t* electric_car_constructor();
void electric_car_destructor(electric_car_ctx_t* e_car_obj);

#endif  // _ELECTRIC_CAR_H
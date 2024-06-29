#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <event_bus.h>

#include <car_common.h>
#include <electric_car.h>
#include <oil_car.h>
#include <tesla_electric_car.h>


int main() {
    tesla_electric_car_ctx_t *tesla_e_car = (tesla_electric_car_ctx_t *)tesla_electric_car_constructor();
    electric_car_ctx_t *e_car = (electric_car_ctx_t *)tesla_e_car;
    car_common_ctx_t *car = (car_common_ctx_t *)tesla_e_car;

    car->start();

    e_car->check_battery_status();

    tesla_e_car->autopilot();
    event_send(EVENT_TEST, NULL, 0);

    car->stop();

    tesla_electric_car_destructor(tesla_e_car);

    return 0;
}

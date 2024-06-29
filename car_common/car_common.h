#ifndef _CAR_COMMON_H
#define _CAR_COMMON_H

#include <stdlib.h>


typedef struct car_common {
    void (*start)();
	void (*set_speed)(int val);
	void (*stop)();
} car_common_ctx_t;

car_common_ctx_t* car_common_constructor();
void car_common_destructor(car_common_ctx_t* car_common_obj);

#endif  // _CAR_COMMON_H
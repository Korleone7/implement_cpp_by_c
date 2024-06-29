#ifndef _EVENT_BUS_H_
#define _EVENT_BUS_H_

typedef enum error {
    SUCCESS = 1000,
    ERROR_BAD_PARAMS,
    ERROR_INVALID_DATA,
    EVENT_MAX
} error_t;

typedef enum event {
    EVENT_BASE = 0,
    EVENT_TEST,
    EVENT_MAX
} event_t;

#define NULL_BREAK(ptr, err) { if (NULL == (ptr)) { (err) = ERROR_BAD_PARAMS; break; }}

typedef error_t (*handle_event)(event_t evt, void *data, int data_len);

error_t event_send(event_t evt, void *data, int data_len);
error_t event_register_handler(event_t evt, handle_event handler);
error_t event_deregister_handler(event_t evt, handle_event handler);

# endif  // _EVENT_BUS_H_
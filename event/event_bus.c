#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <event_bus.h>
#include <list.h>

#define LOG_TAG "[event_bus]"

static struct list *g_handlers[EVENT_MAX] = { NULL };

error_t event_send(event_t evt, void *data, int data_len) {    
    error_t err = SUCCESS;
    struct list *entry = NULL;

    do {
        struct list *evt_list = NULL;
        if (evt < EVENT_BASE || evt >= EVENT_MAX) {
            err = ERROR_BAD_PARAMS;
            break;
        }

        evt_list = g_handlers[evt];
        LIST_FOREACH(evt_list, entry) {
            handle_event handler = (handle_event)entry->data;
            err = handler(evt, data, data_len);
            if (err != SUCCESS) {
                break;
            }
        }
    } while (0);

    return err;
}

error_t event_register_handler(event_t evt, handle_event handler) {
    error_t err = SUCCESS;
    
    do {
        NULL_BREAK(handler, err);

        if (evt < EVENT_BASE || evt >= EVENT_MAX) {
            err = ERROR_BAD_PARAMS;
            break;
        }

        // if has been registered
        if (NULL != list_find(g_handlers[evt], handler)) {
            err = ERROR_INVALID_DATA;
            break;
        }

        {
            struct list *evt_list = g_handlers[evt];
            struct list *entry = list_alloc();
            NULL_BREAK(entry, err);
            entry->data = handler;
            g_handlers[evt] = list_add_tail(evt_list, entry);
        }
    } while (0);

    return err;
}

error_t event_deregister_handler(event_t evt, handle_event handler) {
    error_t err = SUCCESS;
    
    do {
        if (evt < EVENT_BASE || evt >= EVENT_MAX) {
            err = ERROR_BAD_PARAMS;
            break;
        }

        {
            struct list *evt_list = g_handlers[evt];
            if (NULL == evt_list) {
                err = ERROR_INVALID_DATA;
                break;                
            }
            g_handlers[evt] = list_delete_ext(evt_list, handler);
        }
    } while (0);

    return err;
}
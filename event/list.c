#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <event_bus.h>

struct list *list_find(struct list *list, void *data)
{
    struct list *ptr = NULL;
    LIST_FOREACH(list, ptr)
    {
        if(ptr->data == data)
            break;
    }

    return ptr;
}

struct list *list_add_tail(struct list *list, struct list *new_node)
{
    struct list *last = NULL;
    if(list) {
        last = list_last(list);
        list_add_after(last, new_node);
        return list;
    } else {
        return new_node;
    }
}



struct list {
    struct list *next;
    struct list *prev;

    void *data;
};

#define LIST_FOREACH(list, ptr) \
    for (ptr = list;            \
         ptr != NULL;           \
         ptr = list_next(ptr))
    
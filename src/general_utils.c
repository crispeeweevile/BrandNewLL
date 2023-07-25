#include "general_utils.h"

void *smalloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Failed to allocate: %zu bytes", size);
        // crash gen >:D
        (*ptr);
    } 

    return ptr;
}

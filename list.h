#pragma once

// Example usage:
//
// #include <stdio.h>
// #include <stdlib.h>
//
// #include "list.h"
//
// int main() {
//     List(int) xs = {0};
//
//     for (int i = 0; i < 10; ++i) list_append(xs, i);
//
//     list_foreach(xs) {
//         printf("xs[%lu] = %s\n", it.idx, it.value);
//     }
//
//     return 0;
// }

#define List(type) struct { type *items; size_t count; size_t capacity; }

#define list_append(l, item)                                           \
    do {                                                               \
        if (l.count >= l.capacity) {                                   \
            if (l.capacity == 0) l.capacity = 10;                      \
            else                 l.capacity *= 2;                      \
            l.items = realloc(l.items, l.capacity * sizeof(*l.items)); \
        }                                                              \
        l.items[l.count++] = item;                                     \
    } while (0)

#define list_foreach(l) if (l.count > 0) for (struct { size_t idx; typeof(*l.items) value; } it = { 0, l.items[0] }; it.idx < l.count; it.value = l.items[++it.idx])

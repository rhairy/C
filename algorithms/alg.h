void bubble_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y));
void insertion_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y));
void selection_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y));
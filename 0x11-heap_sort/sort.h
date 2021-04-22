#ifndef _SORT_H
#define _SORT_H

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void set_max_heap(int *array, size_t size); 
int collate(int a, int b);
void swap(int *a, int *b);
void sift_down(int *array, size_t i, size_t heapsize);

#endif

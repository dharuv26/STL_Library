#ifndef sort_h
#define sort_h

int defaultCmp(int a, int b);
void swap(int *arr, int i, int j);
void sort(int *arr, int n, int(*cmp)(int, int));
void insertion_sort(int *arr, int n, int(*cmp)(int, int));
void selection_sort(int *arr, int n, int(*cmp)(int, int));
void bubble_sort(int *arr, int n, int(*cmp)(int, int));
void merge_sort(int *arr, int n, int(*cmp)(int, int));
void quick_sort(int *arr, int n, int(*cmp)(int, int));

#endif

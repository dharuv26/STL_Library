#ifndef sort_h
#define sort_h

int defaultCmp(int a, int b);
void swap(int *arr, int i, int j);
void sort(int *arr, int n, int(*cmp)(int, int) = defaultCmp);
void insertion_sort(int *arr, int n, int(*cmp)(int, int) = defaultCmp);
void selection_sort(int *arr, int n, int(*cmp)(int, int) = defaultCmp);
void bubble_sort(int *arr, int n, int(*cmp)(int, int)) = defaultCmp;
void merge_sort(int *arr, int n, int(*cmp)(int, int) = defaultCmp);
void quick_sort(int *arr, int n, int(*cmp)(int, int) = defaultCmp);

#endif

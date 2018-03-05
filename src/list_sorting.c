#include "list_sorting.h"

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Quicksort implementation.
//Quicksort paritions list by choosing a pivot p, swapping elements in the list
//so for 0 < i < p, list[i] < list[p] and for p < j < n, list[p] < list[j].
//Then it recursively is called on list[0...p-1], list[p+1...n-1]

//Swap two elements.
static inline void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

//Partitions the list on pivot of last element.
//list[0..i] < pivot, list[j+1..n-1] >= pivot.
int partition(int* list, int n) {
    int pivot = list[n - 1];
    int i = -1, j = n - 1;
    //Invariant list[0..i] < pivot <= list[j+1...n-1]
    for (int j = 0; j < n - 1; j++) {
        //If list[j] < pivot, swap with list[i] and i--
        if (list[j] < pivot) {
            i++;
            swap(list + i, list + j);
        }
    }
    //Check if pivot is greater than list[i + 1].
    if (list[i + 1] > list[n - 1])
        swap(list + i + 1, list + n - 1);
    return i + 1;
}

//Sorts the portion of the list from pointer to list to list + n - 1.
void quick_sort(int* list, int n) {
    if (n == 0)
        return;
    //Partitions list so, list[0..pi - 1] < list[pi] < list[p-1,...n-1]
    int pi = partition(list, n);
    //Recursively sort both partitions of list.
    quick_sort(list, pi);
    quick_sort(list + pi + 1, n - pi - 1);
}


//Mergesort implementation.
//Mergesort is recursively called on the two halves of the list, and then it
//merges the two halves by sorting them based on the leftmost element of each
//list which has not been merged.

//Merges the two sublists into a single list.
void merge(int* l1, int* l2, int n, int n2, int* ret) {
    //Keep pointers to respective locations in each list.
    int i = 0, j = 0, k = 0;
    while (i != n || j != n2) {
        //If the end of one of the lists is reached.
        if (i == n) {
            memcpy(ret + k, l2 + j, (n2 - j) * sizeof(int));
            break;
        }
        //If the end of the other list is reached.
        else if (j == n2) {
            memcpy(ret + k, l1 + i, (n - i) * sizeof(int));
            break;
        }
        //Add the smallest of the leftmost elements of the two lists.
        else {
            if (l1[i] < l2[j]) {
                ret[k] = l1[i];
                i++;
            }
            else {
                ret[k] = l2[j];
                j++;
            }
        }
        k++;
    }
}

void merge_sort(int* list, int n) {
    //Base case.
    if (n < 2) {
        return;
    }
    //Copy both sublists. (Optimized versions have been suggested to reduce
    //copying lists).
    int l1[n/2], l2[n - n/2];
    memcpy(l1, list, (n/2) * sizeof(int));
    memcpy(l2, list + n/2, (n - n/2) * sizeof(int));
    //Recursively sort both halves.
    merge_sort(l1, n/2);
    merge_sort(l2, n - n/2);
    //Merge both halves.
    merge(l1, l2, n/2, n - n/2, list);
}


//Heapsort implementation.
//Heapsort calls heapify to turn the list into a maxheap, then pops the first
//element of the heap, which is the largest element, and places it at the front
//of the sorted list.

//Sift down implementation.
void sift_down(int* list, int start, int n) {
    //Bubble down from start position.
    int parent = start;
    //While there is a valid child, check all possible children.
    while (2 * parent + 1 < n) {
        int child1 = 2 * parent + 1;
        int child2 = 2 * parent + 2;
        //Get the minimum child to compare to parent.
        int max_child;
        if (child2 < n) {
            max_child = list[child1] > list[child2] ? child1 : child2; 
        }
        else {
            max_child = child1;
        }
        //If parent is larger than child, swap parent and child and continue.
        if (list[parent] < list[max_child]) {
            swap(&list[parent], &list[max_child]);
            parent = max_child;
        }
        else {
            break;
        }
    }
}

//Turns the array into a maxheap in 0(n) time.
void heapify(int* list, int n) {
    int at = n - 1; //Start at leaves to minimize number of swaps.
    while (at >= 0) {
        sift_down(list, at, n);
        at--;
    }
}

void heap_sort(int* list, int n) {
    //Turn the array into a maxheap.
    heapify(list, n);
    //Add the largest element in minheap to the beginning of the sorted array.
    int at = n;
    while(at > 1) {
        swap(&list[0], &list[at - 1]);
        at--;
        //Sift down to preserve heap.
        sift_down(list, 0, at);
    }
}


//Insertion sort implementation.
//Insertion sort partitions the list into sorted and unsorted elements, and
//for each iteration, takes the first of the unsorted elements, and inserts it
//in the position where every element to the right is greater and every element
//to the left is less than or equal.

//Simple implementation.
void insertion_sort(int* list, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while(j >= 1 && list[j] <= list[j - 1]) {
            swap(list + j, list + j - 1);
            j--;
        }
    }
}


//Introsort implementation.
//Introsort partitions the list in the same way that quicksort is called, and
//then it is then recursively called on both parts, to a depth of 2*log(n).
//After this it calls heap sort on the segments. This allows the algorithm
//to avoid quicksort's worst case.

//Recursive part of introsort (Technically this is the introsort algorithm.)
void introsort_rec(int* list, int n, double max_depth) {
    if (n < 2) {
        return;
    }
    //Heap sort if maximum depth for quicksort reached.
    if (max_depth == 0) {
        heap_sort(list, n);
    }
    //Otherwise run quicksort.
    else {
        int pi = partition(list, n);
        introsort_rec(list, pi, max_depth - 1);
        introsort_rec(list + pi + 1, n - pi - 1, max_depth - 1);
    }
}

//Run introsort with initial depth of 2*log(n).
void introsort(int* list, int n) {
    introsort_rec(list, n, 2 * log(n));
}


//Selection sort implementation.
//Find the smallest element in list(start...n).
int least_element_index(int* list, int start, int n) {
    int least = list[start], least_index = start;
    for (int i = start + 1; i < n; i++) {
        if (list[i] < least) {
            least = list[i];
            least_index = i;
        }
    }
    return least_index;
}

//list(0...i-1) is sorted, list(i...n) is not sorted.
void selection_sort(int* list, int n) {
    //Swap smallest element in unsorted list with list[i] and increment i.
    for (int i = 0; i < n; i++) {
        int to_swap = least_element_index(list, i, n);
        swap(&list[i], &list[to_swap]);
    }
}


//Bubble sort implementation.
//Bubble sort divides the list into list(0...i) of unsorted elements and
//list(i+1...n-1) of sorted. In each pass, the algorithm iterates over the
//unsorted parts, and swaps elements which are in the wrong order. At the end
//of each pass, the largest element in the unsorted part is at the end of the
//list, so i is decremented.

//Bubble sort
void bubble_sort(int* list, int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}

//Comb sort implementation.
//Comb sort works similarly to bubble sort, except that it iterates over the
//list with a gap size >= 1, whereas bubble sort uses a gap size = 1. This
//helps comb sort deal more efficiently with small values at the end. In each
//pass, comb sort swaps elements seperated by the gap size which are in the
//wrong order. The gap size is decreased each iteration by dividing it by
//the shrink factor. When the gap size is 1, the algorithm combs over the
//list until there are no more swaps, in which case the list is sorted.

//Comb sort
void comb_sort(int* list, int n) {
    double shrink = 1.3; //Suggested from empirical evidence.
    int gap = n; //Gap size of comparison (Divide by shrink each iteration).
    bool sorted = 0; //Needed as list is still combed when gap is 1.
    while (!sorted) {
        gap = floor(gap / shrink);
        //Cannot have gap size of less than 1.
        if (gap <= 1) {
            gap = 1;
            sorted = true;  //If gap is 1 and no swaps, then list is sorted.
        }
        //Comb over list with the gap size.
        for (int i = 0; i + gap < n; i++) {
            if (list[i] > list[i + gap]) {
                sorted = false; //If this is not executed when gap is 1, then
                                //the list is sorted.
                swap(&list[i], &list[i + gap]);
            }
        }
    }
}

//Gnome sort implementation.
//Gnome sort is similar to insertion sort, except that it moves the element
//to its proper place by a series of swaps. An optimized version can be used
//which keeps track of the first position which was used before swapping back
//to the beginning of the array.

//Unoptimized gnome sort.
void gnome_sort(int* list, int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || list[i] > list[i - 1]) {
            i++;
        }
        else {
            swap(&list[i], &list[i - 1]);
            i--;
        }
    }
}

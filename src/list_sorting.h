#ifndef LIST_SORTING_HPP
#define LIST_SORTING_HPP
//Stable sorting algorithms retain the relative ordering of records with equal
//keys.

//Quick sorting algorithm for list of size n.
//Time complexity: Average O(nlog(n)), Worst O(n^2).
//Worst case is when pivot divides lists into sublists of size 0 and n-1.
//Best and average case: Pivot divides list into nearly equal lists.
//Space complexity: Average O(log(n)), Worst O(n).
void quick_sort(int* list, int n);


//Merge sorting algorithm for list of size n.
//Time complexity: Average O(nlog(n)), Worst O(nlog(n)).
//Space complexity: O(n).
void merge_sort(int* list, int n);


//Heap sorting algorithm for list of size n.
//Time compleixty: O(nlog(n)).
//Space complexity: O(1).
//Good for small computers without much cache space.
//Not stable!
void heap_sort(int* list, int n);


//Insertion sort algorithm for list of size n.
//Time complexity: Best case O(n), Worst and Average case O(n^2).
//Best case already sorted.
//Space complexity: O(1).
void insertion_sort(int* list, int n);


//Introsort algorithm for list of size n.
//Time complexity: O(nlog(n))
//Space complexity: O(log(n))
//Not stable!
void introsort(int* list, int n);


//Selection sort algorithm for list of size n.
//Time complexity: O(n^2).
//Space complexity: O(1).
//Not stable!
void selection_sort(int* list, int n);


//Bubble sort algorithm for list of size n.
//Time complexity: Best case O(n), Worst and average case O(n^2).
//Best case is already sorted.
//Space complexity: O(1).
void bubble_sort(int* list, int n);


//Comb sort algorithm for list of size n.
//Time complexity: Best case Theta(n log n). Average Omega(n^2/2^p), Worst
//O(n^2).
//Space complexity: O(1).
//Improvement on bubble sort.
void comb_sort(int* list, int n);


//Gnome sort algorithm for list of size n.
//Time complexity: Best case Omega(n) Worst and Average O(n^2).
//Best case is with nearly sorted or sorted lists.
//Space complexity: O(1).
void gnome_sort(int* list, int n);

#endif

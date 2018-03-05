#include "../src/list_sorting.h"
#include <assert.h>
#include <stdio.h>

void test_quick_sort() {
    int n[] = {2, -4, 4, 11, -50};
    quick_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    quick_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    quick_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    quick_sort(list3, 1);
    assert(list3[0] == 2);
}

void test_merge_sort() {
    int n[] = {2, -4, 4, 11, -50};
    merge_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    merge_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    merge_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    merge_sort(list3, 1);
    assert(list3[0] == 2);

}

void test_heap_sort() {
    int n[] = {2, -4, 4, 11, -50};
    heap_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    heap_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    heap_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    heap_sort(list3, 1);
    assert(list3[0] == 2);
}

void test_insertion_sort() {
    int n[] = {2, -4, 4, 11, -50};
    insertion_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    insertion_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    insertion_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    insertion_sort(list3, 1);
    assert(list3[0] == 2);
}

void test_introsort() {
    int n[] = {2, -4, 4, 11, -50};
    introsort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    introsort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    introsort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    introsort(list3, 1);
    assert(list3[0] == 2);

}

void test_selection_sort() {
    int n[] = {2, -4, 4, 11, -50};
    selection_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    selection_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    selection_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    selection_sort(list3, 1);
    assert(list3[0] == 2);

}

void test_bubble_sort() {
    int n[] = {2, -4, 4, 11, -50};
    bubble_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    bubble_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    bubble_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    bubble_sort(list3, 1);
    assert(list3[0] == 2);
    int list4[2] = {5, 4};
    bubble_sort(list4, 2);
    assert(list4[0] == 4);
    assert(list4[1] == 5);
}

void test_comb_sort() {
    int n[] = {2, -4, 4, 11, -50};
    comb_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    comb_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    comb_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    comb_sort(list3, 1);
    assert(list3[0] == 2);
    int list4[2] = {5, 4};
    comb_sort(list4, 2);
    assert(list4[0] == 4);
    assert(list4[1] == 5);
}

void test_gnome_sort() {
    int n[] = {2, -4, 4, 11, -50};
    gnome_sort(n, 5);
    assert(n[0] == -50);
    assert(n[1] == -4);
    assert(n[2] == 2);
    assert(n[3] == 4);
    assert(n[4] == 11);
    int list2[100];
    for (int i = 99; i >= 0; i--) {
        list2[99 - i] = i;
    }
    gnome_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            list2[i] = i;
        }
        else {
            list2[i] = 100 - i;
        }
    }
    gnome_sort(list2, 100);
    for (int i = 0; i < 100; i++) {
        assert(list2[i] == i);
    }
    int list3[1] = {2};
    gnome_sort(list3, 1);
    assert(list3[0] == 2);
    int list4[2] = {5, 4};
    gnome_sort(list4, 2);
    assert(list4[0] == 4);
    assert(list4[1] == 5);
}

int main() {
    test_quick_sort();
    test_merge_sort();
    test_heap_sort();
    test_insertion_sort();
    test_introsort();
    test_selection_sort();
    test_bubble_sort();
    test_comb_sort();
    test_gnome_sort();
}

#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/


/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */

void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);

// Function to perform Insertion Sort
void insertionSort(int *arr, int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && key < *(arr + j)) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

// Function to perform Selection Sort
void selectionSort(int *arr, int size) {
    int i, j, minValueIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minValueIndex = i;
        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + minValueIndex)) {
                minValueIndex = j;
            }
        }
        if (minValueIndex != i) {
            // Swap arr[i] and arr[minValueIndex]
            temp = *(arr + i);
            *(arr + i) = *(arr + minValueIndex);
            *(arr + minValueIndex) = temp;
        }
    }
}










#endif
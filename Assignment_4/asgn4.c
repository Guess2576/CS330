#include <stdio.h>
#include "asgn4.h"

int main() {
    int size, i;

    printf("Enter the size of your array: ");                            // Asks the user for the size of the array (user input 10%)
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d integers to fill the array: ", size);               // Asks the user for the integers to be put into the array (user input 10%)
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nHere's your unsorted array.\n");                           // Prints the unsorted array to show that the array exists prior to sorting
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }


    insertionSort(arr, size);                                           // Sort the array using insertion sort
    printf("\nHere's your sorted array using Insertion Sort:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, size);                                           // Sort the array using selection sort
    printf("\nHere's your sorted array using Selection Sort:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SWAP(type, x, y) do {type t = x; x=y; y=t; }while(0)

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped){
        swapped = false;

        for (int i = start; i < end; i++){
            if (a[i] > a[i + 1]) {
                SWAP(int, a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        end--;

        for (int i = end - 1; i >= start; --i){
            if (a[i] > a[i + 1]) {
                SWAP(int, a[i], a[i + 1]);
                swapped = true;
            }
        }

        start++;
    }
}

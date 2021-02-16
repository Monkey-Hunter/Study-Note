#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x=y; y=t; }while(0)

void bubble(int a[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j = n-1; j>i; j--)
            if(a[j-1] > a[j])
                swap(int, a[j-1], a[j]);

    }
}

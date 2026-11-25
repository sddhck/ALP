#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
void bubbleSort(int arr[], int n){
    bool trocou = false;
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n - i - 1; j++){
            if(arr[j] > arr[j - 1]){
                trocar(arr[j], arr[j - 1]);
                trocou = true;
            }
        }
        if (trocou == false) break;
    }
}

void stoneSort(int arr[], int n){
    bool trocou = false;
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(arr[j] < arr[j - 1]){
                trocar(arr[j], arr[j - 1]);
                trocou = true;
            }
        }
        if(trocou == false) break;
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = 1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i) trocar(arr[min_idx], arr[i]);
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int chave = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > chave){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = chave;
    }
}


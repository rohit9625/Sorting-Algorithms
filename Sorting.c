#include<stdio.h>
#include<conio.h>
#include<limits.h>

//Functions Declaration
void printArr(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
int maxTwo(int a, int b);
void countSort(int arr[], int size);



int main(){
    int arr[] = {1,4,1,3,2,4,3,7};
    int size = sizeof(arr)/sizeof(arr[0]); // Size of array
    // bubbleSort(arr,size);
    // selectionSort(arr,size);
    // insertionSort(arr, size);
    countSort(arr, size);
    printArr(arr,size);
    
}
// Functions Definitions
void printArr(int arr[], int size){
    // int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}
void bubbleSort(int arr[], int size){
    
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
// Selection Sort
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minPos = i;
        for(int j=i+1; j<size-1; j++){
            if(arr[minPos] > arr[j]){
                minPos = j;
            }
        }
        // Swapping
        int temp = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = temp;
    }
}
// Insertion sort
void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        //Insertion
        arr[prev+1] = curr;
    }
}
// Function to find greatest b/w two numbers
int maxTwo(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
// Counting Sort
void countSort(int arr[], int size){
    // Finding ranege of count array
    int largest = INT_MIN;
    for(int i=0; i<size; i++){
        largest = maxTwo(largest, arr[i]);
    }
    // Creating count array
    int count[largest+1];
    for(int i=0; i<size; i++){
        count[arr[i]]++;
    }
    // Sortinf part
    int j = 0;
    for(int i=0; i<(largest+1); i++){
        while(count[i] > 0){
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}
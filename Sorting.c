#include<stdio.h>
#include<conio.h>
//Functions Declaration
void printArr(int arr[], int size);
void bubbleSort(int arr[], int size);

int main(){
    int arr[] = {4,3,1,2,5};
    int size = sizeof(arr)/sizeof(arr[0]); // Size of array
    bubbleSort(arr,size);
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
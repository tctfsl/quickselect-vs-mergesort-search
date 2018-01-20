#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

typedef int *IntPtr;

void swap(IntPtr );

void printArray(IntPtr arr, int n);

int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int KthElement);

int Partition(IntPtr arr, int FirstIndex, int LastIndex, int output);

int Smallest(IntPtr arr, int n, int k, int output);

int main(){
    int n = 7;
    int KthElement;
    int FirstIndex = 0;
    int LastIndex = n - 1;
    IntPtr arr = new int[n];
    arr[0] = 96;
    arr[1] = 48;
    arr[2] = 91;
    arr[3] = 94;
    arr[4] = 31;
    arr[5] = 77;
    arr[6] = 2;

    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    cout << "Enter the Index of the Kth element you wish to retreive: ";
    cin >> KthElement;

    QuickSelect(arr, FirstIndex , LastIndex, KthElement);
    cout << "Array: ";
    printArray(arr, n);

    cout << "The " << KthElement << " Smallest Element is: " << QuickSelect(arr, FirstIndex , LastIndex, KthElement);
    delete[] arr;
}

void printArray(IntPtr arr, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5)
             << arr[i] << " ";
    cout << endl;
}
/*
int Smallest(IntPtr arr, int n, int k, int output){
    int FirstIndex = 0;
    int LastIndex = n - 1;

    return QuickSelect(arr, FirstIndex, LastIndex, k, output);
}
*/
int Partition(IntPtr arr, int FirstIndex, int LastIndex){
    int pivot = arr[LastIndex];
    int i = FirstIndex;

    for(int j = FirstIndex; j < LastIndex; j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[LastIndex]);
    return i;
}


int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int KthElement){
    if( FirstIndex <= LastIndex ){
        int pivot = Partition(arr, FirstIndex, LastIndex);
        if(KthElement == pivot){
            return KthElement = arr[pivot];
        }
        if(KthElement < pivot){
            return QuickSelect(arr, FirstIndex, pivot-1, KthElement);
        }else{
            return QuickSelect(arr, pivot+1, LastIndex, KthElement);
        }
    }

}

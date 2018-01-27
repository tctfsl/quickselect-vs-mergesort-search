#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

typedef int *IntPtr;

void swap(IntPtr );

void printArray(IntPtr arr, int n);
void printAPR(IntPtr arr, int n, int p, int r, int k);

int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int KthElement, int n);

int Partition(IntPtr arr, int FirstIndex, int LastIndex, int output);

int Smallest(IntPtr arr, int n, int k, int output);

int main(){
    int n = 7;
    int KthElement;
    int FirstIndex = 0;
    int LastIndex = n - 1;
    int input;

    IntPtr arr = new int[n];
    arr[0] = 96;
    arr[1] = 48;
    arr[2] = 91;
    arr[3] = 94;
    arr[4] = 31;
    arr[5] = 77;
    arr[6] = 2;

    cout << "1. Smallesth Kth element." << endl;
    cout << "2. Biggest Kth element." << endl;
    cin >> input;
    switch(input){
case 1:
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    cout << "Enter the Index of the Kth element you wish to retreive: ";
    cin >> KthElement;

    QuickSelect(arr, FirstIndex , LastIndex, KthElement, n);
    cout << "Array: ";
    printArray(arr, n);

    cout << "The " << KthElement << " Smallest Element is: " << QuickSelect(arr, FirstIndex , LastIndex, KthElement, n);
    break;

case 2:
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    cout << "Enter the Index of the Kth element you wish to retreive: ";
    cin >> KthElement;
    KthElement = n - KthElement;
    QuickSelect(arr, FirstIndex , LastIndex, KthElement, n);
    cout << "Array: ";
    printArray(arr, n);

    cout << "The " << KthElement << " Smallest Element is: " << QuickSelect(arr, FirstIndex , LastIndex, KthElement, n);
    break;
default:
break;
    }

    delete[] arr;
}

void printArray(IntPtr arr, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5)
             << arr[i] << " ";
    cout << endl;
}

void printAPR(IntPtr arr, int n, int p, int r, int k) {
    cout << setw(5)
         << "P = " << p
         << ", R = " << r;
    cout << setw(5)
         <<", Pivot = " << arr[r]
         << " : ";
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


int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int KthElement, int n){
    if( FirstIndex <= LastIndex ){
        int p = FirstIndex-1;
        int r = LastIndex;
        int pivot = Partition(arr, FirstIndex, LastIndex);
        if(KthElement == pivot){
            return KthElement = arr[pivot];
        }
        if(KthElement < pivot){
            if(FirstIndex < r){
                p = 0;
            }
            r = pivot - 1;
            printAPR(arr, n, p, r, KthElement);
            return QuickSelect(arr, FirstIndex, pivot-1, KthElement, n);
        }else{
            p = pivot;
            r = LastIndex;
            printAPR(arr, n, p, r, KthElement);
            return QuickSelect(arr, pivot+1, LastIndex, KthElement, n);
        }
    }

}

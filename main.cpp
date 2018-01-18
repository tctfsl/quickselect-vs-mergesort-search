#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

typedef int *IntPtr;

void printArray(IntPtr arr, int n);

void merge(IntPtr arr, int firstIndex, int middleIndex, int lastIndex);

void mergeSort(IntPtr arr, int firstIndex, int lastIndex);

int main() {
    int n = 7;
    IntPtr arr = new int[n];

    arr[0] = 96;
    arr[1] = 48;
    arr[2] = 91;
    arr[3] = 94;
    arr[4] = 31;
    arr[5] = 77;
    arr[6] = 2;

    cout << "DEBUGCODE: Before mergeSort() in main()" << endl;
    printArray(arr, n);
    cout << endl;

    mergeSort(arr, 0, (n-1));

    cout << endl << "DEBUGCODE: After mergeSort() in main()" << endl;
    printArray(arr, n);

    delete[] arr;
}

void printArray(IntPtr arr, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5)
             << arr[i] << " ";
    cout << endl;
}

void merge(IntPtr arr, int firstIndex, int middleIndex, int lastIndex) {
    int i, j, k;
    int arr_size = lastIndex - firstIndex + 1;
    IntPtr temp_arr = new int[arr_size];

    //cout << "DEBUGCODE: Front of merge() [temp]" << endl;
    //printArray(temp_arr, arr_size);

    //cout << "DEBUGCODE: Front of merge()" << endl;
    //printArray(arr, arr_size);

    for (i = middleIndex + 1; i > firstIndex; i--) {
        temp_arr[i - 1] = arr[i - 1];
        //cout << "DEBUGCODE: temp_arr[i(" << i << ") - 1]=" << temp_arr[i-1] << endl;
    }

    for (j = middleIndex; j < lastIndex; j++) {

        //cout << "DEBUGCODE: j= " << j << endl;

        temp_arr[lastIndex + middleIndex - j] = arr[j + 1];
        //cout << "DEBUGCODE: temp_arr[lastIndex(" << lastIndex << ") + middleIndex(" << middleIndex << ") - j(" << j << ")" << "]= " << temp_arr[lastIndex + middleIndex - j] << endl;

        //cout << "DEBUGCODE: j= " << j << endl;

    }

    //cout << "DEBUGCODE: j= " << j << endl;

    //cout << "DEBUGCODE: temp_arr after double for() >> ";
    //printArray(temp_arr, 2);
    // i == 0
    // j == 1

    for (k = firstIndex; k <= lastIndex; k++) {

        //cout << "DEBUGCODE: temp_arr[j]=" << temp_arr[j] << ", temp_arr[i]=" << temp_arr[i] << endl;
        //cout << "DEBUGCODE: j= " << j << ", i= " << i << endl;

        if ((temp_arr[j] < temp_arr[i]) /*&& (i != j)*/) {

            //cout << "DEBUGCODE: if >> ";
            //printArray(arr, arr_size);

            arr[k] = temp_arr[j--];
        } else {

            //cout << "DEBUGCODE: else >> ";
            //printArray(arr, arr_size);

            arr[k] = temp_arr[i++];
        }
    }

    //cout << "DEBUGCODE: End of merge() [temp]" << endl;
    //printArray(temp_arr, arr_size);

    //cout << "DEBUGCODE: Front of merge() ";
    printArray(arr, 7);

    //exit(1);
}

void mergeSort(IntPtr arr, int firstIndex, int lastIndex) {

    //cout << "DEBUGCODE: Front of mergeSort()" << endl;
    //printArray(arr, lastIndex);


    if (firstIndex < lastIndex) {
        //cout << "Front of \"if\" of mergeSort()" << endl;
        //printArray(arr, lastIndex);

        int middleIndex = ((firstIndex + lastIndex) / 2);

        //cout << "DEBUGCODE: middleIndex= " << middleIndex << endl;

        mergeSort(arr, firstIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, lastIndex);

        //cout << "DEBUGCODE: After both mergeSort()" << endl;
        //cout << "DEBUGCODE: Before merge()" << endl;
        //printArray(arr, lastIndex);
        cout << "First = " << firstIndex << ", Last = " << lastIndex << " : ";
        merge(arr, firstIndex, middleIndex, lastIndex);
    }

    //cout << "DEBUGCODE: End of mergeSort()" << endl;
}

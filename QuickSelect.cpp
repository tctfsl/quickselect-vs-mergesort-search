#include <stdio.h>	// To use switch()
#include <iomanip>	// To use the setwd()
#include <iostream>

using namespace std;

typedef int* IntPtr;

//void swap(IntPtr );

void printArray(IntPtr arr, int size);
void printAPR(IntPtr arr, int size, int InitialEI, int LastEI, int target);
int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int target, int size, int time);
int Partition(IntPtr arr, int FirstIndex, int LastIndex, int output);

int main(){
    int size = 7;
    int Target;	// Target is the kth element that you are looking for
    int time;	// To make sure the print function doesn't run multiple time at the final print
    int input;	// To choose either the Smallest  or Biggest section

    IntPtr arr = new int[size];
    arr[0] = 96;
    arr[1] = 48;
    arr[2] = 91;
    arr[3] = 94;
    arr[4] = 31;
    arr[5] = 77;
    arr[6] = 2;

    cout << "1. Smallest Kth element." << endl;
    cout << "2. Biggest Kth element." << endl;
    cin >> input;
    switch(input){
case 1:
    cout << "Array: ";
    printArray(arr, size);
    cout << endl;
    cout << "Enter the Index of the Kth element you wish to retrieve: ";
    cin >> Target;
    time = 1;
    QuickSelect(arr, 0 , size - 1, Target - 1, size, time);
    cout << "Array: ";
    printArray(arr, size);

    cout << "The " << Target << " Smallest Element is: " << QuickSelect(arr, 0 , size - 1, Target - 1, size, time - 1);
    break;

case 2:
    /*cout << "Array: ";
    printArray(arr, size);
    cout << endl;
    cout << "Enter the Index of the Kth element you wish to retrieve: ";
    cin >> Target;
    Target = size - Target;
    QuickSelect(arr, 0 , size - 1, Target, size, time);
    cout << "Array: ";
    printArray(arr, size);

    cout << "The " << Target << " Smallest Element is: " << QuickSelect(arr, 0 , size - 1, Target, size, time - 1);*/
    break;
default:
break;
    }

    delete[] arr;
}

void printArray(IntPtr arr, int size) {
    for (int i = 0; i < size; i++)
        cout << setw(5)
             << arr[i] << " ";
    cout << endl;
}

void printAPR(IntPtr arr, int size, int InitialEI, int LastEI, int target) {

     cout << setw(5)
          <<"Pivot = " << arr[LastEI]
          << " Array : ";
     for (int i = 0; i < size; i++)
         cout << setw(5)
              << arr[i] << " ";
     cout << setw(5)
          << ", Initial Element Index = " << InitialEI
          << ", Last Element Index = " << LastEI;
    cout << endl;
    cout << endl;
/*	cout << "|";
	cout << setw(21) << "Initial Element Index" << "|";
	cout << setw(21) << "Last Elemenet Index" << "|";
	cout << setw(21) << "Pivot" << "|";
	cout << setw(40) << "Array" << "|" << endl;
    for(int i = 0; i < 3; i++){
        cout << "+";
        if(i < 3){
            for(int j = 0; j < 21; j++){
                cout << "-";
            }
        }
    }
    for(int i = 0; i < 1; i++){
        cout << "+";
        for(int j = 0; j < 40; j++){
            cout << "-";
        }
    }
    cout << "+" << endl;
    cout << "|";
    cout << setw(21) << LastEI << "|";
    cout << setw(21) << InitialEI << "|";
    cout << setw(21) << arr[LastEI] << "|";
    for (int i = 0; i < size; i++){

        if(i > 2){
            if( i%3 != 0){
                cout << endl;
                cout << setw(68)
                     << arr[i] << " ";
            }
        }
        else{
                cout << setw(5)
                     << arr[i] << " ";
        }
    }
	cout << endl;*/
}

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


int QuickSelect(IntPtr arr, int FirstIndex, int LastIndex, int Target, int size, int time){
    if( FirstIndex <= LastIndex ){
        int InitialEI = FirstIndex;
        int LastEI = LastIndex;

        int pivot = Partition(arr, FirstIndex, LastIndex);// To get the pivot from the Partition.
        if(Target == pivot){
            return Target = arr[pivot];
        }

        if(Target < pivot){
            if(FirstIndex < LastEI){
                InitialEI = 0;
            }
            LastEI = pivot - 1;
            if(time == 1){
                printAPR(arr, size, InitialEI, LastEI, Target);
            }
            return QuickSelect(arr, FirstIndex, pivot-1, Target, size, time);
        }
        else{
            InitialEI = pivot;
            LastEI = LastIndex;
            if(time == 1)
                printAPR(arr, size, InitialEI, LastEI, Target);

            return QuickSelect(arr, pivot+1, LastIndex, Target, size, time);
        }
    }

}

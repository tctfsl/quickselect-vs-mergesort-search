#include <stdio.h>	// To use switch()
#include <iomanip>	// To use the setwd()
#include <chrono>   // chrono
#include <fstream>  // ifstream datatype, open(), close()
#include <iostream>

using namespace std;

typedef int* IntPtr;

void printline();
void printArray(IntPtr arr, int size);
void printAPR(IntPtr arr, int size, int initialIE, int lastEI, int target, int counter);

void setInput(IntPtr& arr, int& size);
void autoInput(IntPtr& arr, int& size);
void manualInput(IntPtr& arr, int& size);

int QuickSelect(IntPtr arr, int firstIndex, int lastIndex, int target, int size, int counter);
int Partition(IntPtr arr, int firstIndex, int lastIndex);

int main(){
    int size = 0;
    int target;	// Target is the kth element that you are looking for
    int counter = 1;	// To make sure the print function doesn't run multiple time at the final print
    int input;	// To choose either the Smallest  or Biggest section
    int result; // The final result
    auto startTime = chrono::system_clock::now();
    auto endTime = chrono::system_clock::now();
    IntPtr arr = new int[size];

    setInput(arr, size);
    cout << endl;
    cout << "1. Smallest Kth element." << endl;
    cout << "2. Biggest Kth element." << endl;
    cin >> input;
    switch(input){
    case 1:
        cout << "Array before QuickSelect: ";
        printArray(arr, size);
        cout << "\nEnter the Index of the Kth element you wish to retrieve: ";
        cin >> target;

        startTime;
        result = QuickSelect(arr, 0 , size-1, target - 1, size, counter);
        endTime;

        cout << "Array after QuickSelect: ";
        printArray(arr, size);
        cout << "\nThe " << target << " Smallest Element is: " << result;
        break;

    case 2:
        cout << "Array before QuickSelect: ";
        printArray(arr, size);
        cout << "\nEnter the Index of the Kth element you wish to retrieve: ";
        cin >> target;
        target = size - target;

        startTime;
        result = QuickSelect(arr, 0 , size - 1, target, size, counter);
        endTime;

        cout << "Array after QuickSelect: ";
        printArray(arr, size);

        cout << "\nThe " << target << " Smallest Element is: " << result;
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

void printline(){
    for(int i = 0; i < 3; i++){
        cout << "+";
        if(i < 3){
            for(int j = 0; j < 13; j++){
                cout << "-";
            }
        }
    }
    for(int i = 0; i < 1; i++){
        cout << "+";
        for(int j = 0; j < 120; j++){
            cout << "-";
        }
    }
    cout << "+";
    cout << endl;
}

void printAPR(IntPtr arr, int size, int initialEI, int lastEI, int target, int counter) {

    if(counter == 1){
        printline();
        cout << "|";
        cout << setw(13) << "Initial Index" << "|";
        cout << setw(13) << "Last Index" << "|";
        cout << setw(13) << "Pivot" << "|";
        cout << setw(120) << "Array" << "|" << endl;
        printline();
    }

    cout << "|";
    cout << setw(13) << initialEI << "|";
    cout << setw(13) << lastEI << "|";
    cout << setw(13) << arr[lastEI] << "|";
    for (int i = 0; i < size; i++){
        cout << setw(5)
             << arr[i] << " ";
    }
	cout << "|" << endl;
	printline();
}

void setInput(IntPtr& arr, int& size) {
  int inputMethod;
  int i = 0;

  do {
	cout << endl;

	if (i != 0)
      cout << "Error, input out of range (1 <= input <= 2)." << endl;

    cout << "How to set the input?" << endl
         << "1. Automatically" << endl
         << "2. Manually" << endl
         << "Enter the corresponding number: ";
    cin >> inputMethod;
	cout << endl;

  } while ((inputMethod != 1) && (inputMethod != 2));

  if (inputMethod == 1)
    autoInput(arr, size);
  else
    manualInput(arr, size);
}

void autoInput(IntPtr& arr, int& size) {
  cout << "Enter the number of input: ";
  cin >> size;

  delete [] arr;
  arr = new int[size];

  string fileName;
  int i = 0;
  ifstream input;

  do {
    if (i != 0)
      cout << "Error, file not found." << endl;

    cout << "Enter input file name (with .txt extension name): ";
    cin >> fileName;

	input.open(fileName);
  } while (!input);

  for(int j = 0; j < size; j++) {
	input >> arr[j];
  }

  input.close();
}

void manualInput(IntPtr& arr, int& size) {
  cout << "Enter an integer for the number of input: ";
  cin >> size;

  for(int i = 0; i < size; i++) {
    cout << "Enter the value for array[" << i << "]: ";
	cin >> arr[i];
  }
  cout << endl;
}

int Partition(IntPtr arr, int firstIndex, int lastIndex){
    int pivot = arr[lastIndex];
    int i = firstIndex;

    for(int j = firstIndex; j < lastIndex; j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[lastIndex]);
    return i;
}


int QuickSelect(IntPtr arr, int firstIndex, int lastIndex, int target, int size, int counter){
    if( firstIndex <= lastIndex ){
        int initialEI = firstIndex;
        int lastEI = lastIndex;
        if(counter == 1){
            printAPR(arr, size, initialEI, lastEI, target, counter);
        }
        counter = counter - 1;
        int pivot = Partition(arr, firstIndex, lastIndex);// To get the pivot from the Partition.
        if(target == pivot){
            lastEI = pivot;
            printAPR(arr, size, initialEI, lastEI, target, counter);
            return arr[pivot];
        }

        if(target < pivot){
            if(firstIndex < lastEI){
                initialEI = 0;
            }
            lastEI = pivot - 1;
            printAPR(arr, size, initialEI, lastEI, target, counter);
            counter = counter -1;
            return QuickSelect(arr, firstIndex, pivot-1, target, size, counter);
        }
        else{
            initialEI = pivot;
            lastEI = lastIndex;
            printAPR(arr, size, initialEI, lastEI, target, counter);
            counter = counter - 1;
            return QuickSelect(arr, pivot+1, lastIndex, target, size, counter);
        }
    }

}

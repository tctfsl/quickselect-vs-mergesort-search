#include <chrono>   // chrono
#include <fstream>  // ifstream datatype, open, close
#include <iomanip>	// setw
#include <cstdlib>  // rand
#include <ctime>    // srand
#include <iostream>
using namespace std;

typedef int* IntPtr;

void printLine(int size);
void printArray(IntPtr arr, int size);
void printInfo(IntPtr arr, int size, int firstCurrentIndex, int lastCurrentIndex, int counter, int pivot);

void autoInput(IntPtr& arr, int& size);
void randomInput(IntPtr& arr, int& size);
void setInput(IntPtr& arr, int& size);

void swap(IntPtr& leftElement, IntPtr& rightElement);
int partition(IntPtr& arr, int firstIndex, int lastIndex, int pivotType);
int quickSelect(IntPtr& arr, int firstIndex, int lastIndex, int target, int size, int counter, int pivotType);

int main() {
  int size = 0;
  IntPtr arr = new int[size];
  setInput(arr, size);

  int pivotType;
  cout << "\nHow is the pivot choosen?\n" << "1. Fixed\n" << "2. Random\n" << "Enter the corresponding number: ";
  cin >> pivotType;

  int target;       // Target is the random kth element that you are looking for
  srand(time(NULL));
  target = rand()% size + 1;
  cout << "\Random kth number is: ";
  cout << target << endl;

  if(size <= 20){
    cout << "\nArray before quickSelect: ";
    printArray(arr, size);
    cout << "\n\n";
  }
  int counter = 1;  // To make sure the print function doesn't run multiple time at the final print
  auto startTime = chrono::system_clock::now();
  int result = quickSelect(arr, 0 , size - 1, target - 1, size, counter, pivotType); // The final result
  auto endTime = chrono::system_clock::now();

  if( size <= 20){
    cout << "\nArray after quickSelect: ";
    printArray(arr, size);
    cout << "\n\nThe " << target << "th smallest element in the array is " << result << "\n";
  }
  chrono::duration<double> duration = endTime - startTime;
  cout << "Target found in " << duration.count() << " second." << endl;

  delete[] arr;
}

void printArray(IntPtr arr, int size) {
  for (int i = 0; i < size; i++)
    cout << setw(5) << arr[i] << " ";
}

void printLine(int size) {
  for(int i = 0; i < 3; i++) {
    cout << "+";

	if(i == 0) {
      for(int j = 0; j < 10; j++)
        cout << "-";
    }
	else {
      if(i == 1) {
        for(int j = 0; j < 9; j++)
          cout << "-";
	  }
	  else {
        for(int j = 0; j < 5; j++)
          cout << "-";
	  }
	}
  }

  cout << "+";

  for(int i = 0; i < size; i++)
    cout << "------";

  cout << "+";
  cout << endl;
}

void printInfo(IntPtr arr, int size, int firstCurrentIndex, int lastCurrentIndex, int counter, int pivot) {
  if(counter == 1) {
    printLine(size);
    cout << "|";
    cout << "firstIndex" << "|";
    cout << "lastIndex" << "|";
    cout << "Pivot" << "|";
    cout << "Array";

    for(int i = 0; i < (size - 1); i++)
      cout << "      ";

    cout << " |" << endl;
    printLine(size);
  }

  cout << "|";
  cout << setw(10) << firstCurrentIndex << "|";
  cout << setw(9) << lastCurrentIndex << "|";
  cout << setw(5) << arr[pivot] << "|";

  printArray(arr, size);

  cout << "|" << endl;
  printLine(size);
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
         << "2. Random" << endl
         << "Enter the corresponding number: ";
    cin >> inputMethod;
	cout << endl;

  } while ((inputMethod != 1) && (inputMethod != 2));

  if (inputMethod == 1)
    autoInput(arr, size);
  else
    randomInput(arr, size);
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

void randomInput(IntPtr& arr, int& size) {
  cout << "Enter an integer for the number of input: ";
  cin >> size;

  for(int i = 0; i < size; i++) {
    cout << "Enter the value for array[" << i << "]: ";
    cin >> arr[i];
  }
  cout << endl;
}

void swap(IntPtr& leftElement, IntPtr& rightElement){
    int temp = *leftElement;
    *leftElement = *rightElement;
    *rightElement = temp;
}

int partition(IntPtr& arr, int firstIndex, int lastIndex, int pivotType) {
  int pivot;
  if(pivotType == 1){
    pivot = arr[lastIndex];

  }else{
    srand(time(NULL));

    int pivotIndex = firstIndex + rand() % (lastIndex - firstIndex + 1);
    pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[lastIndex]);
  }

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

int quickSelect(IntPtr& arr, int firstIndex, int lastIndex, int target, int size, int counter, int pivotType) {
  if(firstIndex <= lastIndex) {
    int firstCurrentIndex = firstIndex;
    int lastCurrentIndex = lastIndex;

    int pivot = partition(arr, firstIndex, lastIndex, pivotType);// To get the pivot from the partition.

    if( (size + 1) <= 20){
      printInfo(arr, size, firstCurrentIndex, lastCurrentIndex, counter, pivot);
      counter--;
    }

    if(target == pivot) {
      return arr[pivot];
    }

    if(target < pivot) {

      return quickSelect(arr, firstIndex, (pivot - 1), target, size, counter, pivotType);
    }
    else {

      return quickSelect(arr, (pivot + 1), lastIndex, target, size, counter, pivotType);
    }
  }
}

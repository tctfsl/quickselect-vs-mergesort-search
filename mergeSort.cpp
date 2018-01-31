#include <chrono>   // chrono
#include <fstream>  // ifstream datatype, open(), close()
#include <iomanip>  // setw()
#include <iostream>
using namespace std;

typedef int* IntPtr;

void printArray(IntPtr arr, int size);

void autoInput(IntPtr& arr, int& size);
void manualInput(IntPtr& arr, int& size);
void setInput(IntPtr& arr, int& size);

void merge(IntPtr& arr, IntPtr& temp, int firstIndex, int middleIndex, int lastIndex, int size);
void mergeSort(IntPtr& arr, IntPtr& temp, int firstIndex, int lastIndex, int size);
int searchSort(IntPtr& arr, int target, int firstIndex, int lastIndex, int size);

int main() {
  int size = 0;
  IntPtr arr = new int[size];
  
  setInput(arr, size);
  
  int target = 0;
  
  cout << endl << "Enter the kth smallest element to find: ";
  cin >> target;
  cout << endl;
  
  cout << "At the beginning: ";
  printArray(arr, size);
  
  auto startTime = chrono::system_clock::now();
  
  int result = searchSort(arr, target, 0, (size - 1), size);
  
  auto endTime = chrono::system_clock::now();
  
  cout << "At the end      : ";
  printArray(arr, size);
  
  cout << "The " << target << "th smallest element in the array is " << arr[target] << "." << endl;
  
  chrono::duration<double> duration = endTime - startTime;
  
  cout << "Target found in " << duration.count() << " second." << endl;
  
  delete [] arr;
}

void printArray(IntPtr arr, int size) {
  for(int i = 0; i < size; i++)
	cout << setw(3) << arr[i] << " ";

  cout << endl;
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

void merge(IntPtr& arr, IntPtr& temp, int firstIndex, int middleIndex, int lastIndex, int size) {
  int i, j;
  
  for(i = (middleIndex+1); i > firstIndex; i--)
    temp[i-1] = arr[i-1];
  
  for(j = middleIndex; j < lastIndex; j++)
    temp[lastIndex+middleIndex-j] = arr[j+1];
  
  for(int k = firstIndex; k <= lastIndex; k++) {
    if (temp[j] < temp[i])
      arr[k] = temp[j--];
	else
      arr[k] = temp[i++];
  }
  
  if ((lastIndex - firstIndex + 1) != size) {
    cout << "After a merge   : ";
    printArray(arr, size);
  }
}

void mergeSort(IntPtr& arr, IntPtr& temp, int firstIndex, int lastIndex, int size) {
  if (firstIndex < lastIndex) {
    int middleIndex = ((firstIndex + lastIndex)/2);
    
    mergeSort(arr, temp, firstIndex, middleIndex, size);
    mergeSort(arr, temp, (middleIndex+1), lastIndex, size);
    
    merge(arr, temp, firstIndex, middleIndex, lastIndex, size);
  }
}

int searchSort(IntPtr& arr, int target, int firstIndex, int lastIndex, int size) {
  IntPtr temp = new int[size];
  
  mergeSort(arr, temp, firstIndex, lastIndex, size);
  
  delete [] temp;
  
  return arr[target-1];
}
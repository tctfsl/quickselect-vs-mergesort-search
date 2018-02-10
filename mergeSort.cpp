#include <chrono>   // chrono
#include <cstdlib>  // rand(), RAND_MAX, srand()
#include <ctime>    // time()
#include <fstream>  // ifstream datatype, open(), close()
#include <iomanip>  // setw(), fixed, setprecision()
#include <iostream>
using namespace std;

typedef int* IntPtr;

void printLine(int size);
void printInfo(IntPtr arr, int size, int firstIndex, int lastIndex, int counter);
void printArray(IntPtr arr, int size);

void autoInput(IntPtr& arr, int& size);
void randomInput(IntPtr& arr, int& size);
void setInput(IntPtr& arr, int& size);

void merge(IntPtr& arr, IntPtr& temp, int firstIndex, int middleIndex, int lastIndex, int size, int& counter);
void mergeSort(IntPtr& arr, IntPtr& temp, int firstIndex, int lastIndex, int size, int& counter);
int searchSort(IntPtr& arr, int target, int firstIndex, int lastIndex, int size);

int main() {
  int size = 0;
  IntPtr arr = new int[size];
  setInput(arr, size);
  
  srand(time(NULL));
  int target = ((rand() % size) + 1);
  cout << "Searching for the " << target << "th element.\n\n";
  
  if (size <= 20) {
    cout << "At the beginning: ";
    printArray(arr, size);
    cout << "\n";
  }
  
  auto startTime = chrono::system_clock::now();
  int result = searchSort(arr, target, 0, (size - 1), size);
  auto endTime = chrono::system_clock::now();
  
  if (size <= 20) {
    cout << "At the end: ";
    printArray(arr, size);
    cout << "\n\n";
  }
  
  cout << "The " << target << "th smallest element in the array is " << result << ".\n";
  
  chrono::duration<double> duration = endTime - startTime;
  cout << fixed << setprecision(6) << "Target found in " << duration.count() << " second." << endl;
  
  delete [] arr;
}

void printLine(int size) {
  for(int i = 0; i < 2; i++) {
    cout << "+";
    
    if(i == 0) {
      for(int j = 0; j < 10; j++)
        cout << "-";
    }
    else {
      for(int j = 0; j < 9; j++)
        cout << "-";
    }
  }
  
  cout << "+";
  
  for(int i = 0; i < size; i++)
    cout << "------";
  
  cout << "+\n";
}

void printInfo(IntPtr arr, int size, int firstIndex, int lastIndex, int counter) {
  if(counter == 1) {
    printLine(size);
	
    cout << "|";
    cout << "firstIndex" << "|";
    cout << "lastIndex" << "|";
    cout << "Merge";
    
    for(int i = 0; i < (size - 1); i++)
      cout << "      ";
    
    cout << " |\n";
	
    printLine(size);
  }

  cout << "|";
  cout << setw(10) << firstIndex << "|";
  cout << setw(9) << lastIndex << "|";
  
  printArray(arr, size);
  
  cout << "|\n";
  
  printLine(size);
}

void printArray(IntPtr arr, int size) {
  for(int i = 0; i < size; i++)
    cout << setw(5) << arr[i] << " ";
}

void autoInput(IntPtr& arr, int& size) {
  cout << "Enter the number of input: ";
  cin >> size;
  
  delete [] arr;
  arr = new int[size];
  
  int i = 0;
  string fileName;
  ifstream input;
  
  do {
    if (i != 0)
      cout << "Error, file not found.\n";
    
    cout << "Enter input file name (with .txt extension name): ";
    cin >> fileName;
    cout << "\n";
    
    input.open(fileName);
  } while (!input);
  
  for(int j = 0; j < size; j++) {
    input >> arr[j];
  }
  
  input.close();
}

void randomInput(IntPtr& arr, int& size) {
  size = 20;
  cout << "Number of input is " << size << ".\n\n";
  
  delete [] arr;
  arr = new int[size];
  
  srand(time(NULL));
  
  for(int i = 0; i < size; i++) {
    arr[i] = ((rand() % RAND_MAX) + 1);
  }
}

void setInput(IntPtr& arr, int& size) {
  int i = 0;
  int inputMethod;
  
  do {
    cout << endl;
    
    if (i != 0)
      cout << "Error, input out of range (1 <= input <= 2).\n";
    
    cout << "How to set the input?\n"
         << "1. Automatically\n"
         << "2. Randomly\n"
         << "Enter the corresponding number: ";
    cin >> inputMethod;
    cout << "\n";
  } while ((inputMethod != 1) && (inputMethod != 2));
  
  if (inputMethod == 1)
    autoInput(arr, size);
  else
    randomInput(arr, size);
}

void merge(IntPtr& arr, IntPtr& temp, int firstIndex, int middleIndex, int lastIndex, int size, int& counter) {
  int i, j;
  
  for(i = (middleIndex + 1); i > firstIndex; i--)
    temp[i - 1] = arr[i - 1];
  
  for(j = middleIndex; j < lastIndex; j++)
    temp[lastIndex + middleIndex - j] = arr[j + 1];
  
  for(int k = firstIndex; k <= lastIndex; k++) {
    if (temp[j] < temp[i])
      arr[k] = temp[j--];
    else
      arr[k] = temp[i++];
  }
  
  if (size <= 20) {
    printInfo(arr, size, firstIndex, lastIndex, counter);
    counter++;
  }
}

void mergeSort(IntPtr& arr, IntPtr& temp, int firstIndex, int lastIndex, int size, int& counter) {
  if (firstIndex < lastIndex) {
    int middleIndex = ((firstIndex + lastIndex) / 2);
    
    mergeSort(arr, temp, firstIndex, middleIndex, size, counter);
    mergeSort(arr, temp, (middleIndex + 1), lastIndex, size, counter);
    
    merge(arr, temp, firstIndex, middleIndex, lastIndex, size, counter);
  }
}

int searchSort(IntPtr& arr, int target, int firstIndex, int lastIndex, int size) {
  IntPtr temp = new int[size];
  int counter = 1;
  
  mergeSort(arr, temp, firstIndex, lastIndex, size, counter);
  
  delete [] temp;
  
  return arr[target - 1];
}
#include <ctime>    // time()
#include <cstdlib>  // srand(), rand(), RAND_MAX
#include <fstream>  // ofstream, open(), close()
#include <iostream> 
using namespace std;

int main() {
  long long size;
  cout << "Enter number of input: ";
  cin >> size;
  
  int generateType;
  cout << "\nWhat number to generate?\n" 
       << "1. Random Numbers\n"
       << "2. 1 to " << size << "\n"
       << "3. " << size << " to 1\n"
       << "4. " << size << " of integer 1\n"
       << "Enter the corresponding number: ";
  cin >> generateType;
  
  ofstream output("input.txt");
  srand(time(NULL));
  
  if (output.is_open()) {
    if (generateType == 1) {
      for(int i = 0; i < size; i++)
        output << ((rand() % RAND_MAX) + 1) << " ";
    }
    else {
      if (generateType == 2) {
        for(int i = 1; i <= size; i++)
          output << i << " ";
      }
      else {
        if (generateType == 3) {
          for(int i = size; i > 0; i--)
            output << i << " ";
        }
        else {
          for(int i = 0; i < size; i++)
            output << 1 << " ";
        }
      }
    }  
    output.close();
  }
  else {
    cout << "Error generating input.\n";
  }
}
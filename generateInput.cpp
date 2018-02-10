#include <ctime>    // time()
#include <cstdlib>  // srand(), rand(), RAND_MAX
#include <fstream>  // ofstream, open(), close()
#include <iostream> 
using namespace std;

int main() {
  long long size;
  
  cout << "Enter number of input: ";
  cin >> size;
  
  ofstream output("input.txt");
  
  srand(time(NULL));
  
  if (output.is_open()) {
    for(int i = 0; i < size; i++)
      output << ((rand() % RAND_MAX) + 1) << " ";
    
    output.close();
  }
  else {
    cout << "Error generating input." << endl;
  }
}
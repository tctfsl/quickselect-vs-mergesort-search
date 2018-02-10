# quickselect-vs-mergesort-search
An assignment to compare the time taken between quick-select and merge-sort algorithm to search for k-th element.

See the branches for progress

## Branch/Progress:
### 01/15-1437-faisal
- Added a working mergeSort(), not meant for searching yet.
- Added printArray() to print all elements in an array.
- Loads of debugging comments which will eventually be removed in the final version.
- Input is fixed to ease the logic testing.
- Imported a library for debugging, will be removed too in the final version.

### 01/18-2018-Shahzaad
- Fixed the bug at the merge function.
- The if statement at line 85 causes problem for the final output.

### 01/21-2105-Shahzaad
- added a working quickSelect() with search function.

### 01/27-2354-Shahzaad
- Program can search for the Biggest and Smallest of the Kth element.
- Program can also print after swapping but still have some bugs.
- Because of the print after swapping that I have added the original printArray() for the output of the program print multiple times.

### 02/01-0214-faisal
- generates a large set of random positive integers, though the integers are not unique.
- outputs the integers into a .txt file.
- tested up to 1 billion integers.
- take note, the size of file may go up to Gigabytes!
- additionally, text editor can't open .txt file that is too big.

### 02/01-0236-faisal
- reworked the mergeSort().
- user can now choose to either set the input automatically (from a .txt file) or manually (enter inputer individually).
- future work: add a third option to randomly generate 20 integers for the input as part of assignment requirements.
- will show the kth element and the time taken to do so.
- future work: check the datatype of all variables that hold number, there could be variables with imprecise numerical datatype.

### 02/08-1450-faisal
- code cleanup on quickSelect.cpp based on Shahzaad's latest branch.

### 02/10-1441-Shahzaad
- Added random pivot.
- use random generator
- printInfo() will print out pivot  as arr[pivot] as oppose to arr[lastIndex] previously.

### 02/10-1615-faisal
- the input is now either automatically set (to any number) or 20 randomly generated numbers.
- kth element is randomly set.
- minor cleanup on what is displayed into the console.

### 02/10-1619-Shahzaad
- Target kth element is now random
- Can choose between fixed pivot and random pivot
- If size of array is more than 20 it won't print out the array.
- swap() is a function now not utility.

### 02/10-1717
- almost-finalised quickSelect and mergeSort.
- there's still room for code cleanup though.

###02/10-1828
- added the code to generate random number (which will output to input.txt).
- more code cleanup for both algorithms.
- Assignment requirements list:
  - [x] implement a QuickSelect algorithm to find the kth element.
  - [x] implement a mergeSort algorithm to find the kth element.
  - [x] generate 20 random integers as the input.
  - [x] generate random k.
  - [x] implement both fixed and random pivot selection in quickSelect.
  - [ ] generate input ranging from 10,000 to 100,000,000.
  - [ ] text the algorithm with the generated inputs.
  - [ ] generate input for all cases (best, average, worst) for both algorithms.
  - [ ] document experiment findings.

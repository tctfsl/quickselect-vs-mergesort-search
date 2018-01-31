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

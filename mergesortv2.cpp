#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int SIZE = 100000;

//--------------------------------------------------
// Global temporary array reused during merge operations
// to avoid repeated memory allocation.
//--------------------------------------------------
int tempArray[SIZE];


//--------------------------------------------------
// Merge Function
// Merges two sorted subarrays into one sorted array.
//--------------------------------------------------
void merge(int theArray[], int first, int mid, int last)
{
    int first1 = first;
    int last1 = mid;

    int first2 = mid + 1;
    int last2 = last;

    int index = first;

    while (first1 <= last1 && first2 <= last2)
    {
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }

        index++;
    }

    while (first1 <= last1)
    {
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }

    while (first2 <= last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }

    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}


//--------------------------------------------------
// Merge Sort V2
//
// Optimization:
// Before merging, check whether the two sorted halves
// are already in order. If so, skip the merge step.
// This significantly improves performance on already
// sorted or nearly sorted datasets.
//--------------------------------------------------
void mergeSortV2(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;

        mergeSortV2(theArray, first, mid);
        mergeSortV2(theArray, mid + 1, last);

        // Early-exit optimization
        if (theArray[mid] <= theArray[mid + 1])
            return;

        merge(theArray, first, mid, last);
    }
}


//--------------------------------------------------
// Main Function
//--------------------------------------------------
int main()
{
    int arr[SIZE];
    int count = 0;

    //--------------------------------------------------
    // INPUT FILE
    //
    // Place "numbers.txt" inside the same folder as this
    // source file (or change the relative path below).
    //
    // Example project structure:
    //
    // MergeSort/
    // ├── MergeSortV2.cpp
    // ├── numbers.txt
    // └── README.md
    //--------------------------------------------------

    ifstream file("numbers.txt");

    if (!file)
    {
        cout << "Error: Could not open 'numbers.txt'." << endl;
        cout << "Make sure the file is located in the project directory." << endl;
        return 1;
    }

    //--------------------------------------------------
    // Read numbers from input file
    //--------------------------------------------------
    while (count < SIZE && file >> arr[count])
        count++;

    file.close();

    //--------------------------------------------------
    // Start timing
    //--------------------------------------------------
    clock_t start = clock();

    mergeSortV2(arr, 0, count - 1);

    //--------------------------------------------------
    // End timing
    //--------------------------------------------------
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    //--------------------------------------------------
    // OUTPUT FILE
    //
    // The sorted array will be written to
    // "sorted_numbers_v2.txt" in the project folder.
    //--------------------------------------------------

    ofstream outFile("sorted_numbers_v2.txt");

    if (!outFile)
    {
        cout << "Error creating output file." << endl;
        return 1;
    }

    for (int i = 0; i < count; i++)
        outFile << arr[i] << endl;

    outFile.close();

    //--------------------------------------------------
    // Program Output
    //--------------------------------------------------
    cout << "Sorting Completed Successfully!" << endl;
    cout << "Numbers Sorted : " << count << endl;
    cout << "Execution Time : " << timeTaken << " seconds" << endl;
    cout << "Output File    : sorted_numbers_v2.txt" << endl;

    return 0;
}

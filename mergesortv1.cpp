#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100000;

//--------------------------------------------------
// Merge Function
// Merges two sorted subarrays into one sorted array.
//--------------------------------------------------
void merge(int theArray[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first;

    while (first1 <= last1 && first2 <= last2)
    {
        if (theArray[first1] <= theArray[first2])
            tempArray[index++] = theArray[first1++];
        else
            tempArray[index++] = theArray[first2++];
    }

    while (first1 <= last1)
        tempArray[index++] = theArray[first1++];

    while (first2 <= last2)
        tempArray[index++] = theArray[first2++];

    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}

//--------------------------------------------------
// Traditional Merge Sort (V1)
//--------------------------------------------------
void mergeSort(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;

        mergeSort(theArray, first, mid);
        mergeSort(theArray, mid + 1, last);

        merge(theArray, first, mid, last);
    }
}

//--------------------------------------------------
// Main Function
//--------------------------------------------------
int main()
{
    int arr[MAX_SIZE];
    int size = 0;

    //--------------------------------------------------
    // INPUT FILE
    //
    // Place "numbers.txt" inside the same folder as this
    // source file (or change the relative path below).
    //
    // Example project structure:
    //
    // MergeSort/
    // ├── MergeSortV1.cpp
    // ├── numbers.txt
    // └── README.md
    //--------------------------------------------------

    ifstream file("numbers.txt");

    if (!file)
    {
        cout << "Error: Could not open 'numbers.txt'." << endl;
        cout << "Make sure the file is in the project directory." << endl;
        return 1;
    }

    //--------------------------------------------------
    // Read numbers from file
    //--------------------------------------------------
    while (size < MAX_SIZE && file >> arr[size])
        size++;

    file.close();

    //--------------------------------------------------
    // Start timing
    //--------------------------------------------------
    clock_t start = clock();

    mergeSort(arr, 0, size - 1);

    //--------------------------------------------------
    // End timing
    //--------------------------------------------------
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    //--------------------------------------------------
    // OUTPUT FILE
    //
    // The sorted numbers will be written to
    // "sorted_numbers.txt" in the project folder.
    //--------------------------------------------------

    ofstream outFile("sorted_numbers.txt");

    if (!outFile)
    {
        cout << "Error creating output file." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++)
        outFile << arr[i] << endl;

    outFile.close();

    //--------------------------------------------------
    // Program Output
    //--------------------------------------------------
    cout << "Sorting Completed Successfully!" << endl;
    cout << "Numbers Sorted : " << size << endl;
    cout << "Execution Time : " << timeTaken << " seconds" << endl;
    cout << "Output File    : sorted_numbers.txt" << endl;

    return 0;
}

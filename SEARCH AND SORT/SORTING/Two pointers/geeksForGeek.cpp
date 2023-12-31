// C++ Program Illustrating Naive Approach to
// Find if There is a Pair in A[0..N-1] with Given Sum
// Using Two-pointers Technique

// Importing required libraries
#include <iostream>
#include <algorithm>

using namespace std;

#define py              cout << "YES\n";
#define pn              cout << "NO\n";

// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
int isPairSum(int A[], int N, int X)
{
	// represents first pointer
	int i = 0;

	// represents second pointer
	int j = N - 1;

	while (i < j) {

		// If we find a pair
		if (A[i] + A[j] == X)
			return 1;

		// If sum of elements at current
		// pointers is less, we move towards
		// higher values by doing i++
		else if (A[i] + A[j] < X)
			i++;

		// If sum of elements at current
		// pointers is more, we move towards
		// lower values by doing j--
		else
			j--;
	}
	return 0;
}

// Driver code
int main()
{
	// array declaration
	int arr[] = { 2, 3, 5, 8, 9, 10, 11 };
	
	// value to search
	int val = 17;
	
	// size of the array
	int arrSize = *(&arr + 1) - arr;
	
	// array should be sorted before using two-pointer technique
	sort(arr, arr+7);

	// Function call
    bool a = isPairSum(arr, arrSize, val);
	
    if (a) py
    else pn

	return 0;
}

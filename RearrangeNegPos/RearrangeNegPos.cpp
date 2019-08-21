

#include <iostream>

using namespace std;

// Function to Rearrange positive and negative 
// numbers in a array 
void RearrangePosNeg(int arr[], int l, int r) {

	while (l < r)
	{
		// find element that is negative 
		while (l < r && arr[l] < 0)
			l++;

		// find element that is positive 
		while (r >= l && arr[r] > 0)
			r--;

		// swap elements. 
		if (l < r) {
			swap(arr[l], arr[r]);
			l++;
			r--;
		}
	}
}

// Function to print an array  
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}



int main()
{
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6, -7, 8 };

	int arr_size = sizeof(arr) / sizeof(arr[0]);

	RearrangePosNeg(arr, 0, arr_size - 1);

	printArray(arr, arr_size);

}



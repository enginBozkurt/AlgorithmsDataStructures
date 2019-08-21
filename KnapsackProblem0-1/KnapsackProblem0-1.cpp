// KnapsackProblem0-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// val[0..n - 1]  --->  values (profits)
// wt[0..n-1] --- > weights
// W which represents knapsack capacity, n is the number of items
// find out the maximum value subset of val[] such that sum of the weights 
// of this subset is smaller than or equal to W

#include <iostream>

using namespace std;

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n)
{
	
	//initilize 2D array - dynamic memory allocation (heap)
	int** K = new int* [n+1];
	for (int i = 0; i < n+1; ++i) {
		K[i] = new int[W+1];
	}

	// Build table K[][] in bottom up manner 
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];

	// delete 2D array
	for (int i = 0; i < n+1; ++i) {
		delete[] K[i];
	}
	delete[] K;

}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 50;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(W, wt, val, n) << endl;
	
	return 0;
}

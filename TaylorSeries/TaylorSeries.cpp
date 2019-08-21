// TaylorSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


double e(int x, int n) {
	static double p = 1, f = 1;
	double r;

	if (n == 0)
		return 1;
	else {
		r = e(x, n - 1);
		p = p * x;
		f = f * n;

		return r + p / f;
	}
}

int main()
{
	std::cout << "The result is :" << e(1,10)<<endl;
}

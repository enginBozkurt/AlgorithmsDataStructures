
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n) swap(m, n);  // If m is larger than n, exchange it. Does not affect the conclusion. 
		if (m < 2) return m;	// If m == 0, then there is no path, if m == 1, then there is only one way from Guhuashan.

		std::vector<int> steps(n, 1);

		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				steps[j] += steps[j - 1];

		return steps[n - 1];
	}
};

int main()
{
	Solution s;

	std::cout << s.uniquePaths(3, 7) << std::endl;

	return 0;
}


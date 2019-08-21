#include <iostream>
#define N 100

using namespace std;

const int NIL = -1;
int cache_table[N];

void init() {
	for (int i = 0; i < N; i++)
		cache_table[i] = NIL;
}

int fib_mem(int n) {
	if (cache_table[n] == NIL) {
		if (n <= 1)
			cache_table[n] = n;
		else
			cache_table[n] = fib_mem(n - 1) + fib_mem(n - 2);
	}
	return cache_table[n];
}

int main()
{
	init();
	std::cout << fib_mem(5) << endl;
	std::cout << fib_mem(7) << endl;
}
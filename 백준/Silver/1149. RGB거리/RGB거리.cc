#include <iostream>
#include <cstdio>

int mini(int x, int y) { return x < y ? x : y; }

using namespace std;


int main() {
	int N, arr[3] = { }, a, b, c;
	cin >> N;

	for (int i = 0; i < N; i++) {
		
		cin >> a >> b >> c;
		
		a += mini(arr[1], arr[2]);
		b += mini(arr[0], arr[2]);
		c += mini(arr[0], arr[1]);

		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
	}
	printf("%d", mini(arr[0], mini(arr[1], arr[2])));
}
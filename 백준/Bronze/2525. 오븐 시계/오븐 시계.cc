#include <iostream>

using namespace std;

int main(){
	int h, m, c;
	cin >> h >> m >> c;
	m += c;
	h += m/60;
	m %= 60;
	h %= 24;
	cout << h << " " << m;
}
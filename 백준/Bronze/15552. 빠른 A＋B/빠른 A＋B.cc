#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, a, b;
	cin >> T;
	while(T--){
		cin >> a >> b;
		cout << a+b << "\n";
	}
}
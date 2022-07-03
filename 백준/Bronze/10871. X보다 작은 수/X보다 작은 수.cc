#include <iostream>

using namespace std;

int main(){
	int N, X, input;
	cin >> N >> X;
	while(N--){
		cin >> input;
		if(input<X) cout << input << " ";
	}
}
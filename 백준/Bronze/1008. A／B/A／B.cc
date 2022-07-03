#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if(a==b) cout << "1";
	else{
		for(int i=2;i<=4;i++){
			if(!(a%i)&&!(b%i)){
				a /= i;
				b /= i;
			}
		}
		if(b==1 || b==2 || b==4 || b==5 || b==8 ) cout << (double)a/b;
		else {
			printf("%.32Lf", (long double)a/b);
		}
	}
}
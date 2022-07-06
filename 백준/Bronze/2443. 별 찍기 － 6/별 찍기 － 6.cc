#include <iostream>

using namespace std;

int main(){
	int N, emp=0, star;
	cin >> N;
	star=1+2*(N-1);
	while(star>0){
		for(int i=emp;i;i--) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp++;
		star-=2;
		cout << "\n";
	}
}
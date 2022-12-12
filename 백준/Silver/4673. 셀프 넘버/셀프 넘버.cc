#include <iostream>
#define MAX 10000
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool check[MAX + 1] = { 0 };
	int num, i;
	for(i=1;i<=MAX;i++){
		num = i;
		while(1){
			int temp = num;
			while(num > 0){
				temp += num%10;
				num /= 10;
			}
			num = temp;
			if(num>MAX) break;
			if(check[num]) break;
			check[num] = 1;
		}
	}
	for(int i=1;i<=MAX;i++){
		if(!check[i]) cout << i << endl;
	}
}
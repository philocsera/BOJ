#include <iostream>

using namespace std;

int memo[10][101],N;

int boo(int num, int count){
	if(num<0||num>9) return 0;
	if(count==N) return 1;
	if(memo[num][count]) return memo[num][count];
	return memo[num][count] = (boo(num-1,count+1) + boo(num+1,count+1))%1000000000;
}

int main(){
	long rslt=0;
	cin >> N;
	for(int i=1;i<10;rslt%=1000000000) rslt += boo(i++,1);
	cout << rslt;
}
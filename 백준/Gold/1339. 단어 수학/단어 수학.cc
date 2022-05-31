#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arr[26];

int boo(int P){
	int MaxI=-1, MaxV=-1;
	for(int i=0;i<26;i++){
		if( MaxV < arr[i] ){
			MaxV = arr[i];
			MaxI = i;
		}
		else if( MaxV == arr[i] && !MaxV){
			MaxV = arr[i];
			MaxI = -2;
		}
	}
	if(MaxI == -2) {
		if(!MaxV) return 0;
		return boo(P);
	}
	if(MaxI == -1) return 0;
	arr[MaxI] = 0;
	return boo(P-1) + P*MaxV ;
}

int main(){
	int N, len;
	string input;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		len = input.length();
		for(int i=0;i<len;i++){
			arr[input[i] - 'A'] += pow(10,len-1-i);
		}
	}
	cout << boo(9);	
	
}
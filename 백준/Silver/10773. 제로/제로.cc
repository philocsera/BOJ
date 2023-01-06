#include <iostream>
int main(){
	int K,t,N=0,r=0;
	int s[100'000]={0};
	std::cin >> K;
	while(K--){
		std::cin >> t;
		if(t) s[N++] = t;
		else N--;
	}
	while(N--) r += s[N];
	std::cout << r;
}
#include <bits/stdc++.h>

using namespace std;

int isOp(char ch){
	if(ch == '+') return 1;
	if(ch == '-') return 1;
	if(ch == '*') return 1;
	if(ch == '/') return 1;
	return 0;
}

double calc(double a, double b, char ch){
	if(ch == '+') return a+b;
	if(ch == '-') return a-b;
	if(ch == '*') return a*b;
	if(ch == '/') return a/b;
	return 0;
}

int main(){
	string str;
	queue<char> exp;
	stack<double> stk;
	int arr[26], N;
	char input;
	double a, b;

	cin >> N >> str;
	for(int i=0;i<str.length();i++) exp.push(str[i]);
	for(int i=0;i<N;i++) cin >> arr[i];

	while(!exp.empty()){
		if(isOp(exp.front())){
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();
			stk.push(calc(a,b,exp.front()));
		}
		else{
			stk.push(arr[exp.front()-'A']);
		}
		exp.pop();
	}

	cout << fixed;
	cout.precision(2);

	cout << stk.top();
	
}
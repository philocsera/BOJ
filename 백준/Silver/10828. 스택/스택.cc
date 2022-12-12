#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<int> stk;
	int commandN, input;
	string command;

	cin >> commandN;
	while(commandN--){
		cin >> command;

		if(command == "push"){
			cin >> input;
			stk.push(input);
		}
		else if(command == "pop"){
			if(stk.empty()) cout << "-1" << endl;
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if(command == "size"){
			cout << stk.size() << endl;
		}
		else if(command == "empty"){
			if(stk.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if(command == "top"){
			if(stk.empty()) cout << "-1" << endl;
			else cout << stk.top() << endl;
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	queue<int> q;
	int N, input;
	string command;

	cin >> N;

	while(N--){
		cin >> command;

		if(command == "push"){
			cin >> input;
			q.push(input);
			continue;
		}
		else if(command == "pop"){
			if(q.empty()) cout << "-1";
			else{
				cout << q.front();
				q.pop();
			}
		}
		else if(command == "size"){
			cout << q.size();
		}
		else if(command == "empty"){
			cout << q.empty();
		}
		else if(command == "front"){
			if(q.empty()) cout << "-1";
			else cout << q.front();
		}
		else if(command == "back"){
			if(q.empty()) cout << "-1";
			else cout << q.back();

		}
		cout << endl;
	}
}
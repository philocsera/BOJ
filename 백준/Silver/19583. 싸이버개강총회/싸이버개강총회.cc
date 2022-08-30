#include <bits/stdc++.h>
#define hour first
#define minute second
using namespace std;

int timeToNum(pair<int, int> time){
	return time.hour * 100 + time.minute;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char temp;
	int rslt = 0;
	pair<int, int> start, end, quit, now;
	map< string, bool > check;
	string name;

	cin >> start.hour >> temp >> start.minute;
	cin >> end.hour >> temp >> end.minute;
	cin >> quit.hour >> temp >> quit.minute;

	while(cin >> now.hour >> temp >> now.minute >> name){
		if(timeToNum(now) <= timeToNum(start)){
			check.insert({name,true});
		}
		else if(timeToNum(end) <= timeToNum(now) && timeToNum(now) <= timeToNum(quit)){
			if(check.find(name) != check.end()){
				check.erase(name);
				rslt++;
			}				
		}
	} 

	cout << rslt;
}
#include <iostream>

using namespace std;

int main(){
   int a, b, n, rslt;
   cin >> a >> b >> n;

   for(int i=0;i<n;i++){
      a %= b;
      a *= 10;
      rslt = a/b;
   }
   cout << rslt;
 }
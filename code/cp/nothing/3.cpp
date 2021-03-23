#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int x = 5; x>=1; x--){
		for(int y = 5; y>x; y--)cout<< " ";
		if(x != 1)cout << x << " " ;
		cout << x << "\n";
	}
	for(int x = 2; x<= 5; x++){
		for(int y = 5; y>x; y--)cout << " ";
		cout << x  << " " << x << endl;
	}

}
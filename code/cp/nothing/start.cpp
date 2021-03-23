#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	for(int xx = 1; xx<= test_case; xx++){
		bool even = false , odd = false;
		int n ;
		cin >> n;
	    vector<int> even1, odd1;
		for(int x =0; x<n; x++){
			int d;
			cin >> d;
			if(d % 2 == 1){
			    odd = true;
			    odd1.push_back(d);
			}
			else {
			    even  = true;
			    even1.push_back(d);
			}
		}
		if(even)
		sort(even1.begin(), even1.end());
		if(odd)
		sort(odd1.begin(), odd1.end());
		// cout <<"debug  " <<  even1[0] << endl;
		int index = odd1.size() - 1;
		if(even && odd && even1[0] > odd1[index]){
			cout << "FINITE\n";
		}
		else{
			cout << "INFINITE\n";
		}
		}
}
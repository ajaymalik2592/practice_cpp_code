#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin >> test;
	for (int t = 0; t<test; t++){
		int c, n , k;
		cin >> c >> n >> k;
		int extra = 0;
		vector<pair<int,int>> vec;
		for (int x =0; x<n; x++){
			pair<int,int> pa;
			cin >> pa.first >> pa.second;
			vec.push_back(pa);
		}
		sort(vec.begin(), vec.end());
		int taken = 0, pro = 0;
		int ma = 0;
		for (auto a : vec){
			if(taken >= a.first)pro++;
			ma = max(ma , a.first - taken);
			taken = max(taken, a.second);
		}
		ma = max(c - taken, ma);
		if(pro > k){
			cout << "Bad\n";
		}
		else{
			if(k == 0){
				cout << "Good\n";
			}
			else{
				bool solve = false;
				int pro = 0;
				taken = 0;
				if(vec[0].second >= vec[1].first){
					pro = vec[0].second - vec[0].first + 1;
					ma = max(vec[1].second -1, ma);
					if(ma >= pro)solve = true;
					taken = max(taken, vec[0].second);
				}
				for(int x =1; x<n-1; x++){
					if(taken >= vec[x].first)pro = vec[x].second - vec[x].first + 1;
					ma = max(ma, vec[x+1].first - taken);
					if(ma >= pro)solve = true; 
					taken = max(taken, vec[x].second);
				}
				ma = max(ma, c - taken);
				pro = max(pro, vec[n-1].second + 1 - vec[n-1].first);
				if(ma >= pro)solve = true;
				if(solve){
					cout << "Good\n";
				}
				else{
					cout << "Bad\n";
				}
			}
		}
	}
}
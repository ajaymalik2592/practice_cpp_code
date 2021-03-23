#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long

vector<pair<int,int>> get_vector_diff(vector<pair<int,int>> a){
	vector<pair<int,int>> ans;
	for(auto a1: a){
		if(a1.first != a1.second){
			ans.push_back(a1);
		}
	}
	return ans;
}

bool fix_2_pair_in_1_step(pair<int,int> a, pair<int,int> b){
	if(a.second - a.first == b.second - b.first)return true;
	if(a.first != 0 && b.first != 0 && a.second % a.first == 0 && b.second % b.first == 0 && a.second / a.first == b.second / b.first)
		return true;
	return false;
}

bool two_can_hold(vector<pair<int,int>> a){
	if(a.size() < 3)return true;
	if(fix_2_pair_in_1_step(a[0], a[1]))return true;
	if(fix_2_pair_in_1_step(a[0], a[2]))return true;
	if(fix_2_pair_in_1_step(a[1], a[2]))return true;
	sort(a.begin(), a.end());
	do{
		auto temp = a;
		temp[1].first += temp[0].second - temp[0].first;
		if(fix_2_pair_in_1_step(temp[1], temp[2]))
			return true;
		temp = a;
		if(temp[0].first != 0 && temp[0].second % temp[0].first == 0){
			temp[1].first *= temp[0].second / temp[0].first;
			if(fix_2_pair_in_1_step(temp[1], temp[2]))
			return true;
		}
	}while(next_permutation(a.begin(), a.end()));
	return false;
}
bool fix_in_1_step(vector<pair<int,int>> a){
	if(a.size() == 1)return true;
	if(a.size() == 2 && fix_2_pair_in_1_step(a[0], a[1])){
		return true;
	}
	if(a.size() == 3){
		if(a[0].second - a[0].first == a[1].second - a[1].first && a[2].second - a[2].first == a[1].second - a[1].first)return true;
		if(a[0].first != 0 && a[1].first != 0 && a[2].first != 0){
			int d1 = a[0].second / a[0].first, d2 = a[1].second / a[1].first, d3 = a[2].second / a[2].first;
			if(a[2].second % a[2].first == 0 && a[1].second % a[1].first == 0 && a[0].second % a[0].first == 0 && d1 == d2 && d2 == d3)
				return true;
		}
	}
	return false;
}

int main(){
		int test;
		cin >> test;
		for (int turn = 1; turn <= test; turn++){
			vector<pair <int,int> > num(3);
			cin >> num[0].first >> num[1].first >> num[2].first >> num[0].second >> num[1].second >> num[2].second;
			auto var = get_vector_diff(num);
			int n = var.size();
			if(n < 2){
				cout << n;
			}
			else if(fix_in_1_step(var)){
				cout << 1;
			}
			else if(two_can_hold(var)){
				cout << 2;
			}
			else{
				cout << 3;
			}
			cout << '\n';
		}
		return 0;
}
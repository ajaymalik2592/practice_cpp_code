#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<pair<long long , long long>> s;
	s.emplace(1,2).first;
	auto it = s.insert({3,4}).first;
	s.insert({0,3}).first;
	--it;
	cout << (*it).second;
	return 0;
}
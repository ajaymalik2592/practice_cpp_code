#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
bool comp(pair<pair<string,int> , int> a, pair<pair<string,int> , int> b )
{
	if(a.first.first  != b.first.first)
		return a.first.first < b.first.first;
	else
		return a.first.second >  b.first.second;
}
int main()
	{
		
	deque<int> de;
	int n, k;
	cin >> n >> k;
	for(int x =0;x <n;x++)
	{
		int i;
		cin >> i;
		de.push_back(i);
	}


		
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	int a[n][2] , b[n][2];
	for(int x = 0 ; x< n ; x++)
	cin>>a[x][0] >> a[x][1];
	for(int x = 0 ; x< n ; x++)
	cin>>b[x][0] >> b[x][1];
	bool t = true;
	
	vector<pair<ll , ll >> vec ;
	for(int x = 0 ; x< n  && t ; x++)
	{
		
		for(int y = 0 ; y < n && t ;y++)
		{
		
			vec.push_back(make_pair(a[x][0]  + b[y][0] , a[x][1] + b[y][1]));
					}
		}
	
	sort(vec.begin() , vec.end());
	for(vector<pair<ll , ll>> ::iterator it = vec.begin() ; it!= vec.end() -1 ; it++)
	{
		if(*it == *(it+1))
		cout<<(*it).first<<" "<< (*it).second<<endl;
		break;
		}
	return 0;
}

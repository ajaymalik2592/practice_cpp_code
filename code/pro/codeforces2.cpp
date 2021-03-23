#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int main()
	{
		vector <ll> vec = {4,8,15,16,23,42}, vec1 (4), a(4);

		cout << "? 1 2\n" << flush;
		cin >> a[0];
		cout << "? 3 4\n" << flush;
		cin >> a[1];
		cout << "? 5 1\n" << flush;
		cin >> a[2];
		cout << "? 2 3\n" << flush;
		cin >> a[3];
		string s = "012345";
		
		do
		{
			if(vec[0]*vec[1] == a[0] && vec[2]*vec[3] == a[1] &&  vec[4]*vec[0] == a[2] && vec[1] * vec[2] == a[3])
			break; 
		}while(next_permutation(ALL(vec)));
		cout << "!" ;
		for(int x =0;x < 6; x++)
		{
			cout << " "<<  vec[x] ;
		}
		cout << "\n";

	}

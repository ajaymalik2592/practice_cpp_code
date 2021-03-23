#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

template<typename T>
T power(T a , T b , T d){T re =1 ; while(b){if(b%2 == 1)re*=a, re%=d; a*=a ; a%=d ; b>>=1;} return re;}

int main()
	{
		int n;
		cin >> n;
		vector<int> vec;
		vec.resize(n);	
		F(x,0,n-1)cin >> vec[x];
		sort(vec.begin() ,vec.end());
		reverse(vec.begin(),vec.end());
		int re = 0,i=1;
		for(int x =0; x< n-1 ; x++)
		{
			for(i;i<=n-1;i++)
			{
				if(vec[x] > vec[i])
					{re++;i++;break;}
				//cout << x <<" "<< i << " " << re << "\n";


			}
			if(i == n)break;
		}
		cout << re <<"\n";
	}
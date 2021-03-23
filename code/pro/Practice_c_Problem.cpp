#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mk make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()

int main()
	{
		speed
		int n;
		cin >> n;
		int aa[4];
		cin >> aa[1] >> aa[2] >> aa[3];
		priority_queue <pair < pair<int, int> , int> > que;
		ll su =0;
		for(int x= 0; x < n ;x++)
		{
			int i, j ,k;
			cin >> i >> j >>k ;
			que.push(make_pair(mk(i , 1),x));
			que.push(make_pair(mk(j , 2),x));
			que.push(make_pair(mk(k , 3),x));


		}
		int a[4], count = 0;
		a[1] =0, a[2] = 0; a[3] = 0;
		int visited[n+1];
		for(int x= 0; x< n+1; x++)visited[x] = 0;
		for(int x= 0 ; x< 3*n  ;x++)
		{
			auto r = que.top();
			que.pop();
			for(int y = 1; y < 4 ;y++)
			{
				if(y == r.first.second && a[r.first.second] < aa[r.first.second] && !visited[r.second] )
				{
					su += r.first.first;
					a[r.first.second]++;
					visited[r.second]  =1;
					count ++;
					//cout << r.first.first <<"  "<< r.first.second<< endl;
				}
			}
		}
		cout << su ;
		
	}

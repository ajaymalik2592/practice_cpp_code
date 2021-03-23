#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
template < typename  T  > 
T power( T a , T b , T c) 
	{ T re = 1 ;
		 while(b)
		 	{
		 		if(b&1)
		 			re = (re*a)%c ; 
		 		a = (a*a)%c ;
		 		 b>>=1;
		 	} 
		 return re;
	}

ll fun( vector < int > vec  ,    int  l , int r  , ll A , ll B)
{
	int num = ub( vec,r);
	num -= lb(vec,l);
	if(num == 0 ) return ((r - l + 1) * A;
	else if(r == l  && num == 0) return A;
	else if( r == l & num != 0 )return num * B * (r - l  + 1);
	else 
	{
		return fun(vec , l , r/2 , A , B) + fun(vec , r/2 +1 , r , A , B);
	}
}

int main()
	{
		speed

		ll n , k , A , B;
		cin >> n >> k >> A >> B;
		vector < ll > vec;
		vec.resize(k);

		F(x,0,k-1)
		{
			cin >> vec[x] ;

		}

		sort(vec.begin() , vec.end() );

		
		cout << fun(vec , 1 ,  power(1LL , n ,(ll)2000*1000*1000 ) , A  , B) ;
	return 0;
}
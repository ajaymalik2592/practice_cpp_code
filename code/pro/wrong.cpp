#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

int main()
	{
		int n;
		cin >> n;
		
		int a[n] , b [1001] , m= 0 , m1= 0 , m2 = 0;
		for(int x = 0 ; x< 1001 ; x++)b[x] = 0;
		F(x,0,n*n-1)
		{
			cin >> a[x];
			b[a[x]] ++;


		}
		/*for(int x = 1 ; x < 1001 ; x++)
		{
			if(b[x])cout << x << "  " << b[x]<< "\n";
		}*/
		bool t = true;
		
		int w[n +1][n+1];
		int  j = 0;

		F(x,1,n/2)
		{	
			if(!t)break;
			
			F(y,1,n/2)
			{
				 if(!t)break;
				 j = 0;
				for(int xx = 1 ; xx< 1001 &&t ;xx ++)
				{
					if(b[xx] %4 == 0 && b[xx] > 0 )
						{
							w[x][y]= xx ;

							b[xx]-=4;
							//cout << x <<" "<< y << " " << xx <<" \n"; 
							
							j = 1;
							break;
						}
				}
			if(j == 0)
				t= false;
			}
		}


		
			
		if(n%2 ==1 && t)
		{
			
				j = 0;
			for(int x =1 ; x< 1001 ; x++)
			{
				if(b[x]%2 == 1 )
				{
					
					w[n/2 +1 ][n/2+1]  = x;
					b[x] --;
					j =1;
					break;
				}
			}
			if(j == 0)
			{
				t = false;

			}
			
			
			for(int i = 1 ; i <= n/2 && t ; i++)
			{int h = 0;
				for(int x = 1 ; x< 1001 ; x++)
			{
				if(b[x] %2 == 0 && b[x] > 0)
				{
					w[i][n/2 +1] = x;b[x]-=2;
					h  = 1;
					
					break;
				}
			}
			if(h == 0)
			{
				t = false;
				
			}
		}
			
			for(int i = 1 ; i <= n/2 && t ; i++)
			{
				int c = 0;
				for(int x = 1 ; x< 1001 && t ; x++)
			{
				if(b[x] %2 == 0 && b[x] > 0 )
				{
					w[n/2 +1][i] = x;b[x]-=2;
					
					c =1;
					break;
				}
			}
			if(c == 0 )
			{
				t = false;
			}
		}


		

}
		
		if(t)
		{
			cout << "YES\n";
			if(n%2 ==0)
			for(int x = 1  ;x<= n ;x++){
				for(int y =1 ; y <= n ;y++)
				{
					
						cout <<w[min(x , n -x +1)][min(y , n-y +1)]<<" ";
					
				}
				cout <<"\n";
			}
			else
				for(int x = 1  ;x<= n ;x++){
				for(int y =1 ; y <= n ;y++)
				{
					
						cout << w[min(x , n -x +1)][min(y , n-y +1)] << " ";
					
				}
				cout <<"\n";
			}

		}
		else
			cout << "NO\n";
		
		return 0;
	}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
/*
int t[800004];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2] ,t[v*2+1]);
    }
}
int mini(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min( mini(v*2, tl, tm, l, min(r, tm))
           , mini(v*2+1, tm+1, tr, max(l, tm+1), r));
}*/

int main()
	{	int n;
		cin>>n;
		int a[n][n];
		char c;
		vector<int> vec;
		//for(int x , )
		F(x,0,n-1)
		{F(y,0,n/4-1)
			{
				cin>>c;
				int i;
				if(c >= 'A') i = c-'A' + 10;
				else i = c- '0';
				a[x][y*4 ]  = i/8;
				a[x][y*4+1]  = (i/4) %2;
				a[x][y*4+2] = (i/2)%2;
				a[x][y*4+3] = i%2;
 			}}
 		int u = 1,z;
 		bool r  ;
 		F(l,2,n)
 		{r = true;
			if(n%l==0)
 		F(x,0,n/l -1 )
		{	
			if(r)F(y,0,n/l-1)
			{	z = a[x*4 ][y*4];
				
				F(xx,0,l-1)
				{	if(r)
					F(yy,0,l-1)
					if(z != a[x*4 + xx][y*4 +yy]){r = false;break;}
					else break;
					}
 			}
 			else break;
 			}
 			if(r && n%l == 0)
 			u = max(u , l);
		}
		cout<<u<<"\n";
		
		return 0;
 
	}


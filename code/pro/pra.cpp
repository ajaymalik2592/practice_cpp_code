#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
bool comp(int a[] , int b[])
{return a[0] < b[0] ;}
int main()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int  n,m;
			cin>>n>>m;
			int a[n][m],p, k=1;
			
			set<int > temp;
			//if(n>=m)
			F(x,0,n-1)
			{F(y,0,m-1)
				{temp.clear();
					//temp.push(0);
					if(x-2>=0)
						temp.insert(a[x-2][y]);
						
					if(y-2>=0)
						temp.insert(a[x][y-2]);
						
					if(x-1 >= 0 && y+1 < m )
						temp.insert(a[x-1][y+1]);
					if(y-1>=0 && x-1 >= 0)
						temp.insert(a[x-1][y-1]);
						
					//sort(temp.begin() , temp.end());
					p =1;
					while(p)
					{
							if(temp.find(p) != temp.end() )
								p++;
							
							else 
								a[x][y] = p , k = max(k , p) , p = 0;
					
						}
						
					
				}
				}
		  /* else
			F(y,0,m-1)
			{F(x,0,n-1)
				{temp.clear();
					//temp.push(0);
					if(x-2>=0)
						temp.insert(a[x-2][y]);
						
					if(y-2>=0)
						temp.insert(a[x][y-2]);
						
					if(y-1 >= 0 && x+1 < n)
						temp.insert(a[x+1][y-1]);
					if(y-1>=0 && x-1 >= 0)
						temp.insert(a[x-1][y-1]);
						
					//sort(temp.begin() , temp.end());
					p =1;
					while(p)
					{
							if(temp.find(p) != temp.end() )
								p++;
							
							else 
								a[x][y] = p , k = max(k , p) , p = 0;
					
						}
						
					
					}
				}*/
			//	if(k<4)
				cout<<k<<"\n";
				F(x,0,n-1)
					{F(y,0,m-1)
						{cout<<a[x][y]<<" ";
							//else cout<<a[x][y];
							}
						cout<<"\n";
						
						}
			//	}
				/*else {*/int o ;
					cout<<4<<"\n";
					F(x,0,n-1)
					{	if(x%4 < 2)o=1;
						else o =3;
						F(y,0,m-1)
						{cout<<o<<" ";
							o%=4;
							o++;
							
							}
						cout<<"\n";
						
						}
				
					//}
			}
			
		
		
		return 0;
	}

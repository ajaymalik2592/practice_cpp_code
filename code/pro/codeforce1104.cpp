#include<bits/stdc++.h>
using namespace std;

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	char c;
	while(s == "start")
	{
		int  l  =0,r = 1, p = 1,ans; 
		while(p)
			{
				cout<<"? "<<l<<" "<<r<<"\n";
				cin>>c;
				//if(l = 0 && )ans
				if(c == 'x')
				   break;
				l = r ;
				r*=2;
			}
		int t ;
		if(l == 0) 
			{
				cout<<"! "<<1<<"\n";
				p=0;
				}
		else if(l == 1) 
			{
				cout<<"! "<<2<<"\n";
				p=0;
				}
		bool y=true;
		while(p && l < r && y)
			{
				t = (r+l)/2;
				if(l!=t)
				
				{cout<<"? "<<l<<" "<<t<<"\n";
					cin>>c;}
				else 
					{
					cout<<"? "<<t<<" "<<r<<"\n";
						cin>>c;
						if(c=='x')
						    ans =r;
						 else ans = t;
						 y=false;
						 break;
						}
					
				
				
				if(c=='x' )
				{	
					//l++;
					
					r=t;
					}
				else 
					{ 
						if(r-l==2)
						{ans = r;
						 y=false;
						break;}
						
						l = t;
						
					  
						}
			}
		if(p)
			cout<<"! "<<ans<<"\n";
		cin>>s;
	}
	return 0;
}

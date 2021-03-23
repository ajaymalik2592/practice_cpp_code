#include<bits/stdc++.h>
using namespace std;
#define F(x,a,b) for(int x = (int)a ; x <= (int)b ; x++)
typedef long long ll ;
bool comp(int a , int b)
{
	 return a > b;
}
int main()
{

	int n , k;
	string s;
	cin>>s>>k;
	n = s.length();
	int r = 0 , a = 0;
	for(int x = 0 ; x< n ; x++)
	{
		if(s[x] == '*' || s[x] == '?')r++;
		if(s[x] == '*') a++;
		
		}
	int pure = n - r;
	//cout<<"pure "<<pure;
	if(a== 0 && pure < k || pure - r  > k )cout<<"Impossible";
	else {
			int ch = k - pure;
			if(ch == 0)
			{for(int x = 0 ; x< n ;x++)
				{if(s[x] != '*' && s[x] != '?')cout<<s[x];}
			}
			else if(ch < 0)
			{
				ch  = -ch;
				for(int x = 0;x  < n ;x++)
				{ 
					if( (ch > 0) && (s[x+1] == '*' || s[x+1] == '?') )
						ch--;
					else if(  s[x] != '*' && s[x] != '?') cout<<s[x];
					}
				}
			else {
						bool t = true;
					for(int x = 0 ; x < n ;x++)
					{
						if(s[x]!= '*' && s[x] != '?')cout<<s[x];
						if(t && s[x+1] == '*')
						{ t = false;
							for(int y = 0 ; y< ch ; y++)
								cout<<s[x];
							}
						}
				}
		}
		cout<<"\n";
	
	
	return 0;		
}

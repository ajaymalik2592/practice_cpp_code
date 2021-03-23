#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	//int n = t;
	string s;
	cin>>s;
	char e[3] = {'R' ,'G','B'};
	//int yy =0,su = n ,temp;
	
	int count = 0;
	string s1,p;
	s1 += s[0];
	for(int x = 1 ; x < n; x++)
	{	
		if(s[x] != s[x-1])s1+=s[x];
		else {
			for(int y = 0 ;y< 3 ; y++)
			{
				if(e[y] != (char )s[x-1] && x < n-1 &&  e[y] != (char )s[x+1]  )
				{s1 += e[y];
					s1+=s[x+1];
					x++;
					count++;
					break;
					}
				else if ( x== n-1 &&  e[y] != (char) s[x-1] ){
					s1 +=e[y];
					//x++;
					count++;
					break;
					}
				}
			}
		}
		
	cout<<count<<"\n";
	cout<<s1<<"\n";
	
	
	return 0;}

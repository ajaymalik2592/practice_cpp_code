#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int str(string s , int n)
{int a = 0;
	for(int x = 0; x< n-1 ;x++)if(s[x] != s[x+1])a++;
	return a;
	}

int main()
{
	string s;
	//int y = "c" - 'a';cout<<y<<endl;
	int k;
	cin>>s>>k;
	int n = s.length(),re= 0,f = str(s , n);
	
	if( f > k){
		
		
		}
		else cout<<0<<endl;
	
  	return 0;}

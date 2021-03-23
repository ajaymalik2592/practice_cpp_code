#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(x,a,b) for(int x = (int)a ; x <= (int) b ; x++)
int visited[100001];
ll p;
void dfs(vector<int > white[] , int index , int count , int pure)
{
	if(count == 0 && index == pure) p++;
	else if(!visited[index-1] )
	{visited[index-1] = true;
		for(auto s : white[index -1])
		{	
			dfs(white , s , count -1 , pure);
		}
	visited[index -1] = false;
	}
}
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	vector< int > white[n];
	F(x,0,m-1)
		{
			cin>>i>>j;
			white[i-1].push_back(j);
			white[j-1].push_back(i);
			
		}
	F(x,0,n-1)visited[x] = 0;
	ll re= 0,temp;
	F(x,0,n-1)
	{	temp = n-1 - white[x].size();
		re += ((temp)*(temp-1)) / 2;	
		p = 0;
		 dfs(white , x + 1 , 3 , x+1);
		re+=p;
		cout<<"x   re "<<x <<" "<<re<< " p "<<p<<"\n";
	}
	cout<<re/3<<"\n";
	
	
	
	
	
	return 0;
}

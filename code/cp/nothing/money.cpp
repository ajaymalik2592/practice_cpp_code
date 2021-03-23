#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto &a : vec)cin >> a;
    for(int x =0; x<n-1; x++)
    {
        int i, j;
        cin >> i >> j;
        i--, j--;
        edges[i].push_back(j);
        edges[j].push_back(i);
    }
    
}
int main(){
	int t;
    cin >> t;
	while(t--)
	{
		solve();
    }
}
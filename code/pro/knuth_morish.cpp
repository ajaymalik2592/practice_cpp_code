#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin >> a >> b;
	int pi[a.length() ];
	pi[0] = 0;
	int cou[a.length()];
	cou[0] = 1;
	for(int x =1; x<a.length();x++)
	{
		int k = pi[x-1];
		int in = 1;
		while(k>0 && a[x] != a[k])
			k = pi[k-1],in++;
		if(a[k] == a[x])
			k++;
		pi[x] = k;
		cou[x] = in;
	}

	int index  = 0;
	for(auto val : pi)
		cout << index << "  " <<val << " " << cou[index] <<  "\n" ,index++;
	return 0;
}
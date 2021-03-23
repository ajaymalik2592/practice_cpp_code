#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("in.txt", "r", stdin); 
    freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int test_case =1 ; test_case <= t; test_case++)
	{
		cout << "Case #" <<test_case <<": ";
		string s;
		cin >> s;
		int n = s.length(), b = 0;
		for(int x=1; x<n; x++)
		{
			if(s[x] == 'B')b++;
		}

		if((n == 3 && b == 1) || ( b != n-1 && b >= 2  ))
			cout <<"Y";
		else
			cout << "N";
		cout << "\n";
		}
	return 0;
}
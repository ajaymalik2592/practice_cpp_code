#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main()
{
	freopen("in.txt", "r",  stdin);
	int n;
	cin >> n;
	vector<int> vec(n);
	for(auto it = vec.begin(); it != vec.end() ; it++)
	{
		cin >> *it;
	}

	int ma = 10;
	int max_arr[n][ma];
	for(int x=0; x<10; x++)
		for(int y=0; y<n; y++)
			max_arr[y][x] = -1;
	for(int x=0; x<n; x++)
		max_arr[x][0] = x;
	for(int x = 1; x < 5; x++)
	{
		for(int y=0; y<n; y++)
		{
			if(max_arr[y][x-1] != -1 )
				if(y + (1<<(x-1)) - 1 < n  &&  max_arr[y + (1<<(x-1)) -1 ][x-1] != -1 && vec[max_arr[y][x-1]]  > vec[max_arr[y + (1<<(x-1)) -1 ][x-1]])
					max_arr[y][x] = max_arr[y + (1<<(x-1)) -1 ][x-1];
				else
					max_arr[y][x] = max_arr[y][x-1];
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u, v);
		int f =  100;
		// for(int j = 10; j >= 0; j--)
		// {
		// 	if(u + (1<<j) <= v)
		// 		u = max_arr[u][j], f = min(f, vec[u]);
		// }
		// cout << f << "\n";
	}


	for(int x=0; x<n; x++)
	{
		cout << "index " << x << "  ";
		for(int y =0; y<8; y++)
		{

			if((1<<y) -1  + x < n)
			{
				cout << max_arr[x][y] << " ";
			}

		}
		cout << endl;
	}

}
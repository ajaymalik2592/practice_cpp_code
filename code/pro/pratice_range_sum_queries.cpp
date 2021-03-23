#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int n = 15;
	vector<int> vec= {1, 2, 3 , 4 ,5 ,5 , 4 ,3, 2 ,1, 1 ,2 , 3 ,4 ,5};
	int arr[15][5];
	for(int x =0; x<n; x++)arr[x][0] = vec[x];

	for(int index = 1; index <5; index ++)
	for(int x =0; x<n; x++)
	{
		if(x + (1 << index) < n)
			arr[x][index] =arr[x][index - 1] +  arr[x + (1<<index ) / 2][index-1];

	}
	int q = 5;
	for(int x =0; x<q; x++)
	{
		int i , j; 
		cin >> i >> j;
		int su = 0;
		for(int y = 5; y>= 0; y--)
		{
			if(i + (1<<y) <= j + 1)
				su += arr[i][y], i += 1<<y;
		}
		cout << su << endl;
	}
	return 0;
}
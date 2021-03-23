#include<bits/stdc++.h>
using namespace std;
#define pb  push_back 
int main()
{
	int n ;k;
	int mi = 0 , m = n , e  =1 ;
	vector<int> vec;

	while(m)
		{
			if(m%2  == 1 ) 	
				{
					mi++ ;

				 	vec.pb(e);
				}
			e *= 2;
			m /= 2;

		}
	if(k < mi || k > n)
	{

		cout<<"NO\n";
	}
	else {
		reverse(vec.begin() , vec.end());

		int need = k - mi;

		cout<<"YES\n";
		for(int x = 0 ;x< k ;x++)
		{
			int e = 1 , val = vec[x];
			
			if(val / e -1  => need)
			{
				for(int r = 0 ;r < val ; r++)
					cout<<1<<" ";
			}
			else{

			}

		}
	}
	return 0;
}
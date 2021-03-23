#include<bits/stdc++.h>
using namespace std;


int main()
{	

	cout<<"enter the number of input signals ::: = \n";
	int n;

	cin>>n;
	int r = pow(2,n);

	vector <int> vec;
	vec.resize(r);
	cout<<"we will take input as the number serialwise \n ";

	for(int x= 0 ; x<  r ;x++)

	{

		cout<<"enter the otput value for "<<x<< "   " ;
		cin>>vec[x];

	}
	vector <int> w;
	w.resize(n);
	
	bool t ;
	for(int x = 0 ; x < r ;x++)

	{	
		 t = true;
		
		int z = n  , e = x;
		for(int y = 0 ; y < n ; y++)
		{
			w[y] = e%2;
			e/=2;
			if(w[y] == 0 )w[y] = -1;
 
		}
		int weigth  = 0 , P= 0,    N = 0;
		for(int c = 0  ;c< n ;c++)
		{if(w[c] == -1) N++;
			else P++;
			}

		int qq = n*P - N;
		int count = 0 ;
		for(int y = 0 ; y< r ; y++)
		{

			
			int num  , u = y;
			for(int xx = 0 ; xx< n ;xx++)
			{

				
				num += w[xx] * u%2;
				u /=2 ;

			}
			
			if((num >= qq && vec[y] == 1) || (num < qq && vec[y] == 0))
			{ count++;
			}
			else {
				t = false ; 
				break;
			}


		}
		if (t)
		{
			int xxx = 0;
		for( ; xxx < n ; )
		{	int u = -1;
		if(w[xxx] == 2) u  =  1;
		else if(w[xxx ] == 1) u = 0;
		cout<<"weight of "<<xxx<<"th the input is "<<u<<"\n";
		xxx++;

		}

		}
		


	}
	
	
return 0;
}

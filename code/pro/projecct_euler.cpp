/*
	trying hard;0

*/
/**********************************************/
#include<bits/stdc++.h>
using namespace std;

int main()
{

	auto str = [](int a){
		string a1 = "";
		while(a)
		{
			a1 = char(a%10 + '0') + a1;
			a/=10;
		}
		return a1;
	} ;

	auto f = [](string a){
		long long a1 = 0;
		for (auto d : a)
		{
			a1 *=10;
			a1 += d - '0';

		}
		return a1;
	} ;
	// cout << str(100);
	int ma = 1000 * 1000 * 1000;
	bool primes[ma];
	for(int x=0;x <ma; x++)primes[x] = false;
	vector <int> vec;
	vector<string> vec1 = {"3" , "7", "109" , "673"};
	for (int x=2; x< ma;x++)
	{
		if(primes[x] == 0)
		{
			if(x > 673 )
			vec.push_back(x);
			for(int y=2*x; y < ma; y+=x)
			{
				primes[y] = true;
			}
		}
		
	}

	for (int s : vec)
	{
		int r = 0;
		string s3 = str(s);
		int l1 =0;
		for(auto l : vec1)
		{
			string s1 = l +s3, s2 = s3 + l;
			long long a1 = f(s1), a2 = f (s2);
			if(a1 < ma && a2 < ma  && primes[a1] == false && primes[a2] == false)
				l1 ++;
			// if(  )
		}
		if(l1 == 4)
		{
			vec1.push_back(s3);
			break;
		}
	}
	for(auto f1 : vec1)
		cout << f1 << endl;
	return 0;
}
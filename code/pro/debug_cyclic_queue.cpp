#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ALL(v) v.begin(), v.end()
struct data{
	ll val;
	data* child;
};
typedef  data* pdata;
pdata create()
{
	pdata aja;
	aja = (pdata)malloc(sizeof(data));
	return aja;
}
int main()
{
	int test;
	cin >> test;
	for(int test_cases = 1; test_cases<=test; test_cases++)
	{	
		
		ll n;
		cin >> n;
		vector<ll> vec(n-1);
		for(auto &a : vec)
			cin >> a;
		bool r = false;
		int f;
		cin >> f;
		long long de = 1e18, in = 0;
		for(int x =0; x<n-1;x++)
		{
			if(vec[x] >f)continue;
			r = true;
			int index = 0;
			pdata root = create(), temp;
			if(x == 0)
			{
					root->val = 0;
				
			}
			else
			{
						root->val = vec[0];
						index++;
			}
			temp = root;
			for(int y = 1; y<n; y++)
			{
				
				if(y == x)
				{
					pdata da = create();
					da->val = 0;

					root->child = da;
				}
				else
				{
					pdata da =  create();
					da->val = vec[index];
					root->child = da;
					index++;
				}
				

				root = root->child;
				if(y == n-1)
					root->child = temp, root = root->child;
				
				
			}
			for(int y =0; y<n-2; y++)
			{
				if(root->val <= 0)
					root = root->child;
				else if(root->child->val <= 0)
					(root->child) ->val -= root->val, root = root->child->child;
				root->child = root->child->child;
				root = root->child;
			}
			
			if(root->val > 0)
				root = root->child;
			if(-1 * root->val + f  < de)
				de = -1* root->val + f , in = x;

		}
		if(r)
		{
			cout << "possible\n";
			cout << in + 1 << " " << de;
		}
		else
		{
			cout << "impossible";
		}
		cout << "\n";
		
	}
}

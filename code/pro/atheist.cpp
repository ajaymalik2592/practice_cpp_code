#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
struct data{
	int sum, prefix, suffix, ans;
};
data t[100];
int a[100];
data make(int val)
{
	data temp;
	temp.sum = temp.prefix = temp.suffix = val;
	temp.ans = max(0, val);
	return temp;
}
data joint(data one, data two)
{
	data temp;
	temp.sum = one.sum + two.sum;
	temp.prefix = max(one.prefix, two.prefix + one.sum);
	temp.suffix = max(two.suffix, one.suffix + two.sum);
	temp.ans = max( max(one.ans, two.ans) , one.suffix + two.prefix);
	return temp;
}
void build(int v,  int l , int r)
{
	if(l == r)
		t[v] = make(a[l]);
	else
	{
		int m = l + (r-l)/2;
		build(v*2, l ,m);
		build(v*2+1, m+1, r);
		t[v] = joint(t[v*2] , t[v*2+1]);
	}
}
void update(int v, int pos, int val, int l1, int r1)
{
	if(l1 == r1)
		t[v] = make(val);
	else
	{
		int m = l1 + (r1-l1)/2;
		if(pos <= m)
			update(v*2, pos, val, l1, m);
		else 
			update(v*2+1, pos, val, m+1, r1);
		t[v] = joint(t[v*2] , t[v*2+1]);
	}
}
data get_sum(int v, int l1, int r1, int l ,int r)
{
	if(l > r)
		return make(0);
	else if(l == l1 && r1 == r)
		return t[v];
	else
	{
		int m = l1 + (r1- l1)/2;
		return joint (get_sum(v*2, l1, m, l , min(m, r)), get_sum(v*2+1, m+1, r1, max(l, m+1), r));

	}
}
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	int n;
	cin >> n;
	for(int x =0; x<n; x++)
		cin >> a[x];
	build(1,0,n-1);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x == 0)
		{
			int pos, val;
			cin >> pos >> val;
			update(1,pos,val, 0,n-1);
		}
		else
		{
			int l,r;
			cin >> l >> r;
			cout << get_sum(1, 0,n-1,l,r).ans << "\n";
		}
		// cout << "array values ";
		// for(int x = 0; x<n*4; x++)
		// 	cout << t[x].ans << " ";
		// cout << "\n";
		
	}
	vector<int> v ={1,2,3,4}, v1 = {-1,6,7,8}, v2= {1000};
	merge(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2) );
	for(auto s : v2)
		cout << s << " ";
	set<int> se = {1, 2};
	se.erase(se.find(2));
	for(auto d : se)
		cout << d << " ";
}
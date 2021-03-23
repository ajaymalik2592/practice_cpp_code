#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
ll gcd(ll a, ll b)
{
	if(b == 0LL) return a;
	else return gcd(b, a%b);
}
string string_l(ll a)
{
	string s = "";
	while(a)
	{
		s = char(a %10 + '0') + s;
		a /= 10;
	}
	return s;
}
int main()
{

	speed

    int t;
    cin >> t;
    int cas = 1;
    while(t--)
    {
    	ll n, l;
    	cin >> n >> l;
    	vector <ll> vec;
    	vector < string > vec1;
    	vec.resize(l);
    	for (auto &d : vec) cin >> d;

    	ll de = gcd(vec[0], vec[1]), f1;
    	f1 = vec[0] / de;
    	set<ll> se;
    	vec1.pb(string_l (f1));
    	se.insert(f1);
    	for (auto f : vec)
    	{
    		f1 = f / f1;
    		string h = string_l(f1);
    		vec1.pb(h);
    		se.insert(f1);
    	}
    	vector <ll> vec2;
    	for (auto pe : se) vec2.pb(pe);
    	sort(ALL(vec2));
    	map<string,ll> ma;
    	ll i = 0;
    	for(auto f : vec2)
    	{
    		ma[string_l(f)] = i;
    		i++;
    	}
    	string s = "";
    	for(auto f : vec1)
    	{
    		s += char(65 + ma[f]);
    	}
        cout <<"Case #"<< cas << ": "<< s <<  "\n";
        cas++;
        
    }
}

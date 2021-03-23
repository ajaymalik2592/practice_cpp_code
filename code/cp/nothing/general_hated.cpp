#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define ALL(a) (a).begin() , a.end()

int mod = 1e9 + 7;

int add(int a, int b){
	if(a + b >= mod)return a+ b - mod;
	return a + b;
}
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int power(int a, int b){
	if(b < 0)return 0;
	int re = 1;
	while(b){
		if(b&1){
			re = mul(re, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return re;
}
int const N = 513;
int fact[N], inverse[N];
void FAC(){
 	fact[0] = 1;
	for(int x = 1; x< N; x++){
		fact[x] = mul(fact[x-1], x);
	}
	inverse[N-1] = power(fact[N-1], mod -2);
	for(int x = N-2; x>= 0; x--){
		inverse[x] = mul(x + 1, inverse[x+1]);
	}

 }

int ncr(int a, int b){
	if(a < b)return 0;
	return mul(fact[a], mul(inverse[a-b], inverse[b]));
}


/******************************************************/


// int dfs(int a){
// 	temp.pb(a);
// 	visit[a] = 1;
// 	for(auto b : edges[a]){
// 		if(visit[b] == 0){
// 			dfs(b);
// 		}
// 	}
// }
int n, m;

bool cmp(pair<int, vector<int> >  a, pair<int, vector<int>> b){
	int a1 = 0, a2 = a.first , b2 = b.first, b1 = 0;
	while(a2){
		if(a2&1)a1++;
		a2>>=1;
	}
	while(b2){
		if(b2&1)b1++;
		b2>>=1;
	}
	if(a1 != b1)return a1 < b1;
	return a.second.size() > b.second.size();

}
void solve(){
	cin >> m >> n;
	vector<string> vec(m);
	for(auto &a : vec)cin >> a;
	vector<int> s(n), edges[n];
	vector<int> mask(1<<m);
	for(int x =0; x<n; x++){
		int g = 0;
		for(int f = 0; f<m; f++){
			if(vec[f][x] == '1'){
				g += power(2, f);
			}
		}
		mask[x] = g;
	}
	for(int &a : s)cin >> a;
	// vector<int> edges[n];
	for(int x =0; x<n; x++){
		int j;
		cin >> j;
		if(x != 0){
			edges[x].pb(j-1);
			edges[j-1].pb(x);
		}
	}
	int mi = 0;
	vector<int> vis(n, 0);
	vector<int> v1 = {0} ;
	vector<vector<int>> answer ;
	vis[0] = 1;
	while(!v1.empty()){
		answer.pb(v1);
		vector<int> v;
		for(auto a: v1){
			for(auto b : edges[a]){
				if(vis[b] == 0){
					vis[b] = 1;
					v.pb(b);
				}
			}
		}
		v1 = v;
	}
	vector< pair< int, vector<int> > > salary;
	for(int x =0; x<answer.size(); x++){
		map<int, vector<int>> ma;
		for(auto a : answer[x]){
			ma[s[a]].pb(a);
			// done[a] = false;
		}
		int g = 0;
		vector<pair<int,int>> ma1;
		vector<int> pais ;
		vector<pair<int, vector<int>>> salary1, salary2;
		ll t1 = 0, t2 = 0;

		for(auto a : ma){
			map<int , vector<int>> good;
			vector<pair<int, vector<int>>> god;
			// map<int, bool> done;

			for(int bande : a.second)good[mask[bande]].pb(bande);
			for(auto b : good)god.pb(b);
			sort(god.begin(), god.end(), cmp);
			for(auto a1 : god){
				// vector<pair<int,vector<int>>> fin;
				// for(auto g : god.second){
				// 	if(done[g] == false)
				// 		{
				// 			done[g] = true;

				// 		}
				// }
				salary.pb({a.first, a1.second});
			}
		}
		continue;


		for(auto a : ma){
			for(auto b : a.second)
				ma1.pb({a.first, b});
			pais.pb(a.first);
			salary2.pb(a);
			set<int>sett;
			for(auto b : a.second){
				for(int g = 0; g<m; g++){
					sett.insert(vec[g][b-1]);
				}
			}
			t1 += 1LL * a.first * sett.size();
		}
		int i = 0, ini = ma1[0].first;
		for(int y = 0; y<ma.size(); y++){
			pair<int, vector<int>> tem;
			tem.first = pais[y] - i;
			int h = 0;
			while(ma1[h].first < pais[y])h++;
			for(; h< ma1.size(); h++){
				tem.second.pb(ma1[h].second);
			}
			i = pais[y];
			salary1.pb(tem);
			set<int>sett;
			for(auto b : tem.second){
				for(int g = 0; g<m; g++){
					sett.insert(vec[g][b-1]);
				}
			}

			t2 += 1LL * tem.first * sett.size();
		} 

		if(t1 <= t2){
			for(auto h : salary2)salary.pb(h);
		}
		else{
			for(auto h : salary1)salary.pb(h);
		}

	}
	ll ans = 0 , ans1 = 0;
	// cout << salary.size() << "\n";
	for(auto a : salary){
		// // cout <<a.second.size() << " " <<  a.first << " ";
		// for(auto b : a.second)cout << b + 1<< " ";
		// cout << "\n";


		set<int> sett;
		for(auto b : a.second){
			for(int g = 0; g<m; g++){
				if(vec[g][b-1] == '1')sett.insert(g);
			}
		}
		ans += 1LL * a.first * sett.size(); 
	}
	// for(auto a : s)cout << a  << " "; 
	// cout << n << "\n";
	for(int x = 1; x<=n; x++){
		// cout << 1 << " " << s[x-1] << " " << x << "\n";
		int o = 0;
		for(int c = 0; c<m; c++)o += vec[c][x-1] - '0';
		ans += 1LL * s[x-1] * o;
	}
	if(ans1 <= ans){
			cout << salary.size() << "\n";
			for(auto a : salary){
				cout <<a.second.size() << " " <<  a.first << " ";
				for(auto b : a.second)cout << b + 1<< " ";
				cout << "\n";
		}

	}
	else{
			cout << n << "\n";
			for(int x = 1; x<=n; x++){
				cout << 1 << " " << s[x-1] << " " << x << "\n";
				// int o = 0;
				// for(int c = 0; c<m; c++)o += vec[c][x-1] - '0';
				// ans += 1LL * s[x-1] * o;
			}

	}
}


/******************************************************/
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	cin >> t;
	while(t--){
		solve();
	}

}
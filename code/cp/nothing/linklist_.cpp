#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	long long a1 = (1LL * a.second * b.first) + b.second, b1 = (1LL * b.second * a.first) + a.second;
	return a1 > b1;
}
int mod = 1e9 + 7;
int add(int a, int b){
	if(a + b >= mod)return a + b - mod;
	return a + b;
}
int mul(int a, int b){
	return (1LL * a * b) % mod;
}
int power(int a, long long b){
	int re = 1;
	while(b){
		if(b&1) re = mul(re, a);
		a = mul(a, a);
		b >>= 1;

	}
	return re;
}



vector<int> vec(1e5 + 5);


int block_size = 300;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());


    int cur_l = 0;
    int cur_r = -1, si = 0;
    vector<int> ma(1e5 + 5, 0);
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            ma[vec[cur_l]] += 1;
            if(ma[vec[cur_l]] == 1)si ++;
        }
        while (cur_r < q.r) {
            cur_r++;
            ma[vec[cur_r]] += 1;
            if(ma[vec[cur_r]] == 1)si++;
        }
        while (cur_l < q.l) {
        	int u = --ma[vec[cur_l]];
        	if(u == 0)si--;
        	cur_l++;
        }
        while (cur_r > q.r) {
        	int u = --ma[vec[cur_r]];
        	if(u == 0)si--;
            cur_r--;
        }
        answers[q.idx] = si;
    }
    return answers;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	map<string ,int> ma;
	int i = 0;
	for(int x =0; x<n; x++)
	{
		cin >> s;
		sort(s.begin(), s.end());
		if(ma.find(s) != ma.end())vec[x] = ma[s];
		else ma[s] = i++, vec[x] = ma[s];
	}
	int q;
	cin >> q;
	vector<Query> Q(q);
	for(int x =0; x<q; x++){
		cin >> Q[x].l >> Q[x].r;
		Q[x].l--, Q[x].r--;
		Q[x].idx = x;
	}
	vector<int> ans = mo_s_algorithm(Q);
	for(int a : ans){
		cout << a << "\n";
	}

}
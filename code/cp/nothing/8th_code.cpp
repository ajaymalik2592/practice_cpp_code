#include<bits/stdc++.h>
using namespace std;
int n, c, t, mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> cal(26 , 0);
    cal[0] = cal['e' - 'a'] = cal['o' - 'a'] = cal['i' - 'a'] = cal['u' - 'a'] = 1;
    int t;
    cin >> t;
    while(t--){
    	int L, i;
    	cin >> L;
    	vector<string> a, b;
    	string s;
    	for(int x =0; x<L; x++){
    		cin >> s;
    		bool f = true;
    		int n = s.length();
    		if(n == 1){
    			if(cal[s[0] - 'a'] == 0)f = false;
    		}
    		else if(n == 2){
    			if(cal[s[0] - 'a'] == 0 && cal[s[1] - 'a'] == 0) f = false;
    		}
    		else{
    			for(int x =0; x<n-2; x++){
    				i = cal[s[x] - 'a'] + cal[s[x+1] - 'a'] + cal[s[x+2] - 'a'];
    				if(i < 2) {
    					f = false;
    					break;
    				}
    			}
    		}
    		if(f) a.push_back(s);
    		else b.push_back(s);
    	}
    	
    }	
}
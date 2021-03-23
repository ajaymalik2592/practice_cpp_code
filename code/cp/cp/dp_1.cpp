#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> v(n*m, 0);
		int arr[n][m];
		for(int x = 0; x<n; x++){
			for(int y = 0; y<m; y++){
				int c;
				cin >> c;
				v[c-1] += y;
			}			
		}
		for(int x = 0; x<m; x++){
			for(int y = 0; y<n; y++){
				int c;
				cin >> c;
				v[c-1] += m * y;
				int o = v[c-1];
				arr[o/m][o%m] = c;
			}			
		}
		for(int x =0; x<n; x++){
			for(int y =0; y<m; y++){
				cout << arr[x][y] << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}
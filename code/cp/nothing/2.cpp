#include<bits/stdc++.h>

using namespace std;
void fun(int a){
	if(a < 10)cout << " " << a;
	else cout << a ;
}
void solve(int n){
	if(n == 1 || n % 2 == 0){
		cout << "Hooray\n";
		if(n == 1){
			cout << 1 << "\n";
		}
		else{
			vector<vector<int>> arr(n, vector<int>(n, 0));
			// for(int x =0; x<n; x++)arr[x][x] = 1;
			vector<int> se[n+2];
			for(int x =0; x<n; x++){
				for(int y = 1; y<= n*2-1; y++){
					se[x].push_back(y);
				}
			}
			// cout << 1 << endl;
			// cout << *find(se[1].begin(), se[1].end(), 1) << endl;
			for(int x = 0; x<n; x++){
				for(int y = 0; y<n; y++){
					// cout << 2 << endl;
					for(int a : se[x])
					{
						// cout << a << endl;

						if(count(se[y].begin(), se[y].end(), a)) {
							remove(se[x].begin(), se[x].end(), a);
							remove(se[y].begin(), se[y].end(), a);
							arr[x][y] = a;
							// arr[y][x] = a + n -1;
							break;
						}
					}

				}
			}
			// int m = log2(n);
			// m++;
			// vector<vector<vector<int>>> arr(m+1);
			// for(int x =0; x<= m; x++){
			// 	arr[x].resize(pow(2,x), vector<int>(pow(2,x)));
			// }
			// arr[0][0][0] = 1;
			// for(int x = 1; x<=m; x++){
			// 	int si = pow(2, x-1);
			// 	for(int x1 = 0; x1<si*2; x1++){
			// 		for(int y1 = x1; y1<si*2; y1++){
			// 			if(x1 == y1){
			// 				arr[x][x1][y1] = 1;
			// 				continue;
			// 			}
			// 			else if(x1 < si && y1>= si){
			// 				int y2 = y1 % si;
			// 				if(y2 >= x1){
			// 					// if(y2 == x1 ){
			// 					// 	arr[x][x1][y1] = arr[x-1][x1][y2] + si;
			// 					// 	continue;
			// 					// }
			// 					arr[x][x1][y1] = si + arr[x-1][x1][y2];
			// 					arr[x][y2][x1+si] = arr[x][x1][y1];
			// 				}
			// 			}
			// 			else
			// 				arr[x][x1][y1] = arr[x-1][x1%si][y1%si];
			// 			arr[x][y1][x1] = arr[x][x1][y1] + si*2-1;
			// 		}
			// 	}

			// }
			for(int x =0; x<n; x++){
				for(int y = 0; y<n; y++){
					fun(arr[x][y]);
					cout  << " ";
				}
				cout << "\n";
			}
		}
	}
	else{
		cout << "Boo\n";
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		solve(n);
	}

}
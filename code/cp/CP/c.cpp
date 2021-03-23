#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power( ll N, ll S );
int main(){
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );
    int T;
    ll count, last, input, N;
    cin >> T;
    while( T-- ){
        cin >> N;
        count = 1;
        cin >> input;
        last = input;
        for( int i = 1; i < N; i++ ){
            cin >> input;
            if( count == -1 ){
                continue;
            }
            else if( ( (last & input) != last )  ){
                count = -1;
                continue;
                //cin.ignore();
            }
           count = (count * power(2, __builtin_popcount(last))) % int(1e9  + 7);
           last = input;
        }
        if(count == -1)cout << "-1\n";
        else
        cout << count % (1000000007)<< '\n';
    }
    return 0;
}

ll power( ll N, ll S ){
    if( S < 0 ){
        return 0;
    }
    ll result = 1;
    while( S > 0 ){
        if( S & 1 ){
            result = result * N;
        }
        N *= N;
        S >>= 1;
    }
    result %= 1000000007;
    return result;
}
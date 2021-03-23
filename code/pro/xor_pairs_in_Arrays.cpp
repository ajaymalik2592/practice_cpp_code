#include<bits/stdc++.h>
using namespace std;
int* FWHT(int P[], bool inverse) {
    for (int len = 1; 2 * len <= 16; len <<= 1) {
        for (int i = 0; i <16; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = P[i + j];
               int  v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }
    
    if (inverse) {
        for (int i = 0; i < 16; i++)
            P[i] = P[i] / 16;
    }

    return P;
}

int main()
{
	int a[4] = {0,1,2,3};
	int b[11] = FWHT(a, true);
	for(auto s : b)
		cout << s << " ";

	return 0;
}
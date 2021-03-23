#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    long long possible=0;
    long long impossible=0;
    cin>>t;
    while(t--){
        long long int s;
        long long n,k,r;
        cin>>s>>n>>k>>r;
        
        long long res=k;
        long long sum=k;
        
        for(int i=0;i<n-1;i++){
            sum*=r;
            res+=sum;
        }
        long diff=abs(s-res);
        
        if(res<=s){
            cout<<"POSSIBLE "<<diff<<endl;
            possible+=diff;
        }
        else{
            cout<<"IMPOSSIBLE "<<diff<<endl;
            impossible+=diff;
        }
        
        if(t==0){
            if(possible>=impossible)
                cout<<"POSSIBLE"<<endl;
            else
                cout<<"IMPOSSIBLE"<<endl;
            
        }
        
    }
    
    return 0;
}
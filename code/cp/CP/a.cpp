#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
      int n;  
      cin >> n;
      char a[n];
      int x=0,y=0;
      cin>>a[0];
      
      if(a[0]=='L')
      {
         x=x-1;
      }
      else if(a[0]=='R')
      {
        
        x=x+1;
      }
      else if(a[0]=='U')
      {
        
        y=y+1;
      }
      else
      {
        y=y-1;
      }
    
    
     for(int i=1;i<n;i++)
     {
        cin>>a[i];
        if(a[i] == 'D'){
            if(a[i-1] != 'U' && a[i-1] != 'D')y--;
            
        }
        else if(a[i] == 'U'){
            if(a[i-1] != 'U'&& a[i-1] != 'D')y++;

        }
        else if(a[i] == 'L'){
            if(a[i-1] != 'L' && a[i-1] != 'R')x--;

        }
        else{
            if(a[i-1] != 'R' && a[i-1] != 'L')x++;
        }
      }
    
    
    cout << x << " "<< y <<endl;
    
    
    }
    
    
  // your code goes here
  return 0;
}

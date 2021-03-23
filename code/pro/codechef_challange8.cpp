#include<bits/stdc++.h>
#include<time.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
int value(char str)
{
	if(str < 91)
		return str + 27 -'A';
	else 
		return str -96 ;
}
int main()
	{
		srand(time(0));
		speed
		int  N  , M , A , X  , R , temp , perfect , waste , worst;
		cin >> N >> M >> A >> X >> R ;
		char s[N];
		cin >> s;
		pair< string  , int > pretty_melody[M] , good_melody[A];
		long double d = 0 , d1 = -10000000 ;
		int pretty[M];
		F(x,0,M-1)
			{
				cin >> pretty_melody[x].first >> pretty_melody[x].second;
				pretty[x] = pretty_melody[x].first.length();
				temp = pretty_melody[x].second / (pretty[x]);
				if(temp > d)
				{
					d = temp ; 
					perfect = x;
				}
				if(temp < d1)
				{
					d1 = temp ;
					worst = x;
				}


			}
		d = 1000000   ;
		F(x,0,A-1)
		{
			cin >> good_melody[x].first >> good_melody[x].second;
			temp = good_melody[x].second / ((good_melody[x].first).length());
				if(temp <  d)
				{
					d = temp ; 
					waste = x;
				}
		}
		vector <int> ett[20000];
		int limit = 0 , consume = 0 ;
		for(int x = 0 ;  x < N && (limit < 100000) && (X > limit); x++)
		{
			for(int y = 0 ; y <  M && (limit < 100000) && (X > limit) ; y++)
			{
				int error = 0;
				if(pretty_melody[y].second < 0 )
				{
					for(int size = 0 ; size < pretty[y] && (x + pretty[y] ) <= N   ; size++)
					{
						if(s[x + size] == pretty_melody[y].first[size])
							error ++;
						else break;
					}
					if(error == pretty[y])
					{
						char c ;
						if(s[x] == 90 && s[x] == 122) c = s[x] - 1;
						else c = s[x] + 1 ;
						ett[consume].pb(x+1);
						int r = c;
						ett[consume].pb(r);
						consume ++;
						limit ++;
						
						
					}
				}
				

			}
		}

		if(limit == X)
		{
			cout << limit<<"\n";
			for(int x = 0 ;x < limit ; x++)
			{
				cout << 1 << " " <<ett[x][0] <<" "<< ((char)ett[x][1])<<"\n"; 
			}
			return 0;
		}

		bool po = false;
		X -= consume;

		int exx = X   , step = limit ,step1 = 1 + limit , l = N , ttt = good_melody[waste].first.length() - 1 , n = N;
		int p = N;
		if(X - R <= 0)
			{
					//  int exx = X  , step = 0 , l = N , ttt = good_melody[waste].first.length() - 1;
			while((step+1 <= 100000) && (exx - good_melody[waste].second >= 0) && (l + ttt <= 1000000) )
			{
				exx -= good_melody[waste].second;
				step ++;
				l += ttt;

			}
			cout <<step << "\n";
			for(int y = 0  ;y < limit  ; y++ )
			{	char err = ett[y][1];
				cout <<1 <<" " << ett[y][0] <<" " << err<<"\n";
			}
			for(int y = limit ; y < step  ; y++)
			{
				cout << 2 << N << " "<< N << " "<< waste + 1 <<"\n";

			}
			
		} 
		else 
		{
			
			while((step+1 <= 100000) && (exx - good_melody[waste].second >= 0) && (l + ttt <= 1000000) )
			{

				exx -= good_melody[waste].second;
				step ++;
				l += ttt;

			}

			exx = X - R , l =  N;
			while((step1+1 <= 100000) && (exx - good_melody[waste].second >= 0) && (l + ttt <= 500000) )
			{

				exx -= good_melody[waste].second;
				step1 ++;
				l += ttt;

			}

			if(step - limit  >= 2 * (step1-1 - limit))
			{
			
				cout << step << "\n";
				p = N;

				for(int y = 0  ;y < limit  ; y++ )
						{
							char err = ett[y][1];
							cout <<1 <<" " << ett[y][0] <<" " << err <<"\n";
						}
				for(int y =limit ; y < step  ; y++)
				{	
					cout << 2 << " " << n << " " << n << " " << waste + 1 << "\n";
					
				
				}
			}
		else
			{
				cout<< step1 << "\n";
				p = N;
				//cout <<step << "\n";
				for(int y = 0  ;y < limit  ; y++ )
					{
						char err = ett[y][1];
						cout <<1 <<" " << ett[y][0] <<" " << err <<"\n";
					}
				for(int x =limit ; x < step1  ; x++)
					{
						int ii =rand();
						ii %= p;
						ii++;
						
						cout << 2 << " " << n << " " << n << " " << waste + 1 << "\n";
						p += ttt;
					
					}
				cout << 3 << " " << 1 << " " << p << "\n";  
			}
		}
			

			

		
		
		

		return 0;
	}
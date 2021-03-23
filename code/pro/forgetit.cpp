#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, n1;
		cin >> n;
		n1 = n;
		vector<int> parent(n+1, -1);
		int root;
		string s;
		pair<int, int> never = {-1,-1};
		// vector <queue<pair<pair<int, int>, int > >>    que(2);
		vector< pair < int, int > > vec(n+1);
		vector< int > se;
		for(int x=0; x<=n; x++) vec[x] = {-1,-1};
		for(int x=1; x<=n; x++)
		{
			
			cout << "Q "  << x << " " << x << " " << x << endl;;
			cin >> s;
			if(s == "Yes")
			{
				
				se.push_back(x);
				vec[x].first = vec[x].second = x;
			}
		}
		

		while(n1 > 1)
		{
			if(se.size() > 1)
			{
				int i = 0, d = 0 , d1 = *se.begin();
				while(true)
				{
					i = 0;
					while(i < se.size() && se[i] <= d1 )i++;
					if(i >= se.size())break;
					d = se[i];
					if(vec[d].first - vec[d1].second == 2)
						{
							cout << "Q" << " " << vec[d1].second +1 << " "<< vec[d1].first << " " << vec[d].second << endl;
							cin >> s;
							if(s == "Yes")
							{


								int r = vec[d].first - 1;
								parent[d] = parent[d1] = r;
								vec[r].first = vec[d1].first,  vec[r].second = vec[d].second;

								se.erase(se.begin() + i);
								se.erase(se.begin() + i-1);
								se.insert(se.begin() + i-1, r);

								d1 = r;
								if(d1 > 1) d1--;
								n1-=2;
							}
							// sort(se.begin(), se.end());
							
					}
					else
						d1 = d;
						
				
				}
				}
			

			 int i = 0;
			 int d1 = se[0],d;

			    while(true)
				{
					while(i < se.size() &&  se[i] <= d1) i++;
					if(i >= se.size())break;
					d = se[i];
					if(vec[d].first - vec[d1].second == 1)
					{
						cout << "Q " << d1 << " " << vec[d1].first << " " << vec[d].second << endl;
						cin >> s;
						if(s == "Yes")
						{
							
							parent[d] = d1;
							vec[d1].second= vec[d].second; 
							
							se.erase(se.begin() + i);
							n1--;
							
						}
						else
						{
							parent[d1] = d;
							vec[d].first= vec[d1].first; 

							se.erase(se.begin() + i-1);
							n1--;

						}
						if(i -2 >= 0)
								d1 = se[i-2];
						else
							d1 = se[i-1];

					}
					else
					{
						d1 = d;
					}
				}
				if(se.size() == 1)
				{


					while(! (vec[se[0]].first == 1 && vec[se[0]].second == n))
					{
						int index = se[0];

						if(vec[index].first > 1 )
						{
							cout << "Q " << vec[index].first - 1 << " " << vec[index].first -1 <<  " " << vec[index].second << endl;
							cin  >> s;
							if(s == "Yes")
							{
								se.clear();
								se.push_back(vec[index].first-1);
								parent[index] = vec[index].first-1;
								vec[parent[index]]  = {vec[index].first-1, vec[index].second};
							}
							else
							{
								se.clear();
								se.push_back(vec[index].second+1);
								parent[index] = vec[index].second+1;
								vec[parent[index]]  = {vec[index].first, vec[index].second+1};
							}
						}
						else
						{
							cout << "Q " << vec[index].second  + 1 << " " << vec[index].first <<  " " << vec[index].second + 1 << endl;
							cin >> s;
							if(s == "Yes")
							{


								se.clear();
								se.push_back(vec[index].second+1);
								parent[index] = vec[index].second+1;
								vec[parent[index]]  = {vec[index].first, vec[index].second+1};
							}
							else{
								se.clear();
								se.push_back(vec[index].first-1);
								parent[index] = vec[index].first-1;
								vec[parent[index]]  = {vec[index].first-1, vec[index].second};
							}

						}
				}
				n1--;
			}
				
		



	}
	cout << "A ";
		for(int x=1; x<= n ; x++)
		{
			cout << parent[x] << " ";
		}
		cout << endl;
	}
	return 0;
}
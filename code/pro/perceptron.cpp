#include<bits/stdc++.h>using namespace std;int activation (int a){ if(a >= 0 ) return 1; else return 0; }int main(){		random_device rd;  //Will be used to obtain a seed for the random number engine    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()    uniform_real_distribution<> dis(0.0, 1.0);    	cout<<"enter the number of input signals ::: = \n";	int n;	cin>>n;	cout<< " enter number of patterns \n";	int pattern;	cin >> pattern;		vector< long double > vec[pattern];	for(int c = 0 ;c< pattern ; c++)		vec[c].resize(n + 1);	int i , j , k;	cout<< " enter pattern  first enter  then corresponfing otput \n";	for (int x = 0; x < pattern; ++x)	{		for(int  y = 0 ; y < n ; y++)			{				cin >> i;				vec[x].push_back(i);			}				cin>>k;		vec[x].push_back(k);	}	cout<< " enter  tolerance value \n";	long double tolerance = 0 , temp = 1000000 , learning_rate;	//cin >> tolerance;	cout<<" enter learning rate \n" ;	cin >> learning_rate ;	vector <  long double > tolerance_vector , weight_vector ;	tolerance_vector.resize(pattern);	weight_vector.resize(n);	long double y_input  , b;	for(int x = 0 ; x< n ;x ++)	{		long double o = dis(gen);		weight_vector[x] = o;	}	for(int x = 0 ; x < n ;x++)		cout << "weigth for " << x+1<< " is  "<< weight_vector[x]<< " \n";	b = dis(gen);	int e = 1;	while(abs(temp) > 0)	{				long double r;		for(int x = 0 ; x< pattern ; x++)		{			y_input = b;			for(int y = 0 ; y < n ;y++)			{				y_input += vec[x][y] * weight_vector[y];			}			y_input = activation(y_input);						r = vec[x][n] - y_input;			b += learning_rate *r ;			for(int xx = 0 ;xx< n ;xx ++)			{				weight_vector[xx] += learning_rate * vec[x][xx] * r;			}					}		cout<< " error in "<<  e <<" iteration  " << r <<"  "<<  flush;		for(int xx =0 ;xx < n ;xx++)cout << weight_vector[xx]<<"  " ;		cout << b <<"   \n";		//if(r == 0.0 )break;		temp = r;		e++;	} for(int x = 0 ; x< n ; x++) { 	cout<<"weight for " << x+1 << "  " << weight_vector[x]<< " \n"; } cout << "weigth for b  " << b <<"\n"; 	return 0;}
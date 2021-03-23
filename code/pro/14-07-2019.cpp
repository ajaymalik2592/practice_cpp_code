#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
typedef struct tree
{
    int val, h;
    struct tree* left, *right;
    
}tree;
tree* create(int va, int d)
{
    tree* ajay = (tree*)(malloc(sizeof(tree)));
    ajay->val = va;
    ajay->h = d;
    ajay->left = NULL;
    ajay->right = NULL;
    return ajay;
}
tree* find(tree* ajay, int va)
{
	cout << ajay->val << " " << ajay->h << "\n";
    if(ajay->val > va  && ajay->left != NULL)
        return find(ajay->left, va);
    else if(ajay->val < va && ajay->right != NULL)
        return find(ajay->right, va);
    return ajay;
}
int main()
	{
	    int n;
	    cin >> n;
	    vector<int> vec(n);
	    for(auto a : vec)cin >> a;
	    int h = 0;
	    tree* root = create(vec[0],1);
	    int u = 1;
	    for(int x =1; x<n; x++)
	    {
	        tree *temp1 = root , * temp = find(root, vec[x]);
	        tree * ajay = create(vec[x], temp->h  + 1);
	        u = max(u , ajay->h);
	        if(vec[x] > temp->val)temp->right = ajay;
	        else temp->left = ajay;
	        root = temp1;
	    }
	    cout << u;
		return 0;
	}


#include<bits/stdc++.h>
#define REP(i,b) for (int i = 0; i < b; i++)
#define mt make_tuple
#define eb emplace_back
#define c(a) cout<<"\ncondition :"<<a<<"\n";
#define el endl // to display output at right place
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define FOR(i,a,b,c) for (int i = a; i < b; i+=c)
#define MAT(v,row,col) vector<vi> > v(row,vi (col,0));
#define MOD 1000007
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

// ***************************  Templates *****************


template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }



// ***************************** Code ***********************


int main(int argc, char const *argv[])
{
	int n,k,qr,qc;

	std::vector<int> v{2,3,4,5,6,10};
	cout<<sum(v);

	// cin>>n>>k;
	// cin>>qr>>qc;

	// std::vector<pair<int,int> > obs(k);
	// for (int i = 0; i < k; ++i)
	// {
	// 	cin>>obs[i].first>>obs[i].second;
	// }


	return 0;
}
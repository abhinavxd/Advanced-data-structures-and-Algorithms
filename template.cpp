#include "bits/stdc++.h"
// Nagpur ki public bole to taklif
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

template<typename T_vector>
void output_vector(const T_vector &v, bool addOne = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = (int) v.size();
	for(int i = start; i < end; i++)
		cout<< v[i] + (addOne ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

int ceil(int x, int y) {
    return x / y + (x % y > 0);
}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
const int N=2e5+5;

void solve() {
	
}

signed main() {
	fast
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
	
	#endif 
	cout<<setprecision(12);
	cout<<fixed;
	
	int t=1;
	cin>>t;
	while(t--) solve();
	
	return 0;
}


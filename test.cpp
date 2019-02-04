/* 
	Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define N 16
#define ll long long int
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define pl pair<ll, ll>
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure(){
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << duration.count() << endl;
}
int n;
vector<int> a(n);
int solve(){
	ll bitt[66000]={0};
	// int n;
	// scanf("%d", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ll parent[66000];
	vector<int> ind[66000];
	ll mx = -1 , mx_index = -1;
	memset(parent,-1,sizeof(parent));
	for (ll i = 0; i < n; i++ ) { 
		ind[a[i]].push_back(i);
		if(bitt[a[i]] < 1)
			bitt[a[i]] = 1; 
		for (ll j = a[i]; j >= 0 ; j = ((j-1)&a[i])){   
			if (a[i] > j && bitt[j] + 1 > bitt[a[i]]) {
				bitt[a[i]] = 1 + bitt[j];
				if(bitt[a[i]] >= mx) {
					mx_index = a[i];
					mx = bitt[a[i]];
				}
				parent[a[i]] = ind[j].back();
			}
			if(j == 0)  break;
		}
	} 
	if(mx==-1)
	{
		// printf("1\n1\n");
	}
	else{
		// printf("%lld\n", mx);
		ll k=mx;
		ll temp[100005];
		ll val = n;
		while(mx--){
			int iind = lower_bound(ind[mx_index].begin(), ind[mx_index].end(), val) - ind[mx_index].begin();
			temp[mx] = ind[mx_index][iind - 1] + 1;
			val = ind[mx_index][iind - 1];
			mx_index = a[parent[mx_index]];
		}
		// for(ll i=0;i<k;i++)
		// {
		// 	printf("%lld ", temp[i]);
		// }
		// printf("\n");
			rp(i, k - 1) {
			if(temp[i] >= temp[i + 1])	return 0;
			if((a[temp[i] - 1]&a[temp[i + 1] - 1]) != a[temp[i] - 1]){
				return 0;
			}
		}
	}
	

	// rp(i, sz){
	//     cout << idx[i] << " ";
	// }
	// cout << endl;
	return 1;
}
int main(){
	FAST
	int t = 5000;
	srand(time(0) * rand());
	while(t--){
		n = rand() % 100000;
		a.clear();
		a.resize(n);
		srand(time(0) * rand());
		rp(i, n){
			a[i] = rand() % (1<<16);
		}
		int st = solve();
		if(!st){
			cout << "Failed" << endl;
			cout << n << endl;
			rp(i, n){
				cout << a[i] << " ";
			}
			cout << endl;
			break;
		}
	}
	return 0;
}
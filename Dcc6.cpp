/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int a[1002][1002], af[1002];
int mark[1002][1002];
int vis[1002], n;
void dfs(int i, int k){
    vis[i] = true;
    mark[k][i] = 1;
    rp(j, n){
        if(i != j && a[i][j] && !vis[j]){
            dfs(j, k);
        }
    }
}
int main(){
    //Do awesome things here
    n = readInt();
    rp(i, n){
        rp(j, n){
            a[i][j] = readInt();
        }
    }
    int k;
    k = readInt();
    rp(i, k){
        af[i] = readInt();
        rp(i, n){
            vis[i] = false;
        }
        dfs(af[i], af[i]);
    }
    int cnt[1002] = {0};
    rp(i, n){
        int ct = 0;
        rp(j, n){
            ct += mark[j][i];
        }
        cnt[i] = ct;
    }
    int ans = -1, ansv;
    rp(i, k){
        int ct = 0;
        rp(j, n){
            if(mark[af[k]][j] && cnt[j] == 1){
                ct++;
            }
        }
        if(ct > ans){
            ans = ct;
            ansv = af[i];
        }
        else if(ct == ans){
            ansv = min(af[i], ansv);
        }
    }
    printf("%d\n", ansv);
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}
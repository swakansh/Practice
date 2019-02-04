/* 
    Author - linpaws07 
*/ 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
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

int flag[100002];
vector<ll> primes;

int main(){
    FAST
    auto sieve_lambda = [](){
        rp(i, 100002){
            flag[i] = 1;
        }
        flag[0] = 0;
        flag[1] = 0;
        for(ll i = 2; i <= 100000; i++){
            if(flag[i]){
                primes.pb(i);
                for(ll j = i; j * i <= 100000; j++){
                    flag[j * i] = 0;
                }
            }
        }
    };
    sieve_lambda();
    int required = 50000;
    int index = 2501, index_one = 2500;
    vector<int> inflag(index, 1), pr, nec;
    rp(i, index + 1){
        pr.pb(primes[i] * primes[i + 1]);
        if(pr.size() >= required)  break;
    }
    fr(i, 2, index + 2){
        nec.pb(primes[i]);
    }
    int cur = index - 1;
    while((inflag[(cur - (inflag[cur] + 1)) % index] + inflag[cur]) != index){
        int new_ind = ((cur - (inflag[cur] + 1)) % index + index) % index;
        pr.pb(nec[cur] * nec[new_ind]);
        if(pr.size() >= required) break;
        inflag[cur]++;
        cur = new_ind;
    }
    int t;
    cin >> t;
    while(t--){   
        int how_many;
        cin >> how_many;
        rp(i, how_many - 1){
            cout << pr[i] << " ";
        }
        cout << pr[how_many - 1] * 2 << endl;
    }
    return 0;
}
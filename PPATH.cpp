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
vector<int> pr(10000, 1);
int visited[10000];
int bfs(string a, string b){
    int cost = INT_MAX;
    queue<pair<string, int > > q;
    visited[stoi(a)] = 1;
    q.push({a, 0});
    while(!q.empty()){
        pair<string, int> p = q.front();
        if((p.f).compare(b) == 0) {
            cost = min(p.s, cost);
            break;
        }
        q.pop();
        rp(i, (p.f).length()){
            rp(j, 10){
                if(i == 0 && j == 0)    continue;
                string temp(p.f);
                temp[i] = char(j + '0');
                int num = stoi(temp);
                if(visited[num] == -1){
                    visited[num] = 1;
                    if(pr[num]){
                        q.push({temp, p.s + 1});
                    }
                }
            }
        }
    }
    return cost;
}
int main(){
    FAST
    int t;
    cin >> t;
    auto sieve = [](){
        pr[0] = pr[1] = 0;
        for(int i = 2 ; i < 10000 ; i++){
            if(pr[i]){
                for(int j = i ; j * i < 10000 ; j++){
                    pr[j * i] = 0;
                }
            }
        }
    };
    sieve();
    while(t--){
        rp(i, 10000){
            visited[i] = -1;
        }
        string a, b;
        cin >> a >> b;
        int cost = bfs(a, b);
        if(cost == INT_MAX){
            cout << "Impossible" << endl;
        }
        else{
            cout << cost << endl;
        }
    }
    return 0;
}
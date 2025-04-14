#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 66; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll len[MAX];

char dnc(ll cur, ll lev){
    if(!lev) return s[cur];
    if(cur >= len[lev]) return dnc(((cur - len[lev] - 1) + len[lev]) % len[lev], lev - 1);
    return dnc(cur, lev - 1);
}

void run(){
    cin >> s >> n; len[1] = s.size();
    ll idx = 0;
    for(int i = 2;i <= 61;i++){
        if((i128)(len[i - 1]) * (i128)2 >= 2e18) break;
        len[i] = len[i - 1] * 2; idx = i;
    }

    cout << dnc(n - 1, idx) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
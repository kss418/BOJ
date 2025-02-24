#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll cnt = 1, num[MAX];
ll mnf[MAX], mxf[MAX];
ll mnt, mxt;

void run(){
    cin >> n >> m; ll result = 0; 
    for(int i = 1;i <= n;i++) cin >> st[i];
    for(int i = 1;i <= n;i++){
        if(st[i] == "or") cnt++;
        else if(i % 2) num[i] = cnt;
    }

    memset(mnf, 0x3f, sizeof(mnf)); mnt = INF;
    for(ll i = 1;i <= n;i += 2){
        ll now = num[i];
        if(st[i] == "false"){
            mnf[now] = min(mnf[now], i);
            mxf[now] = max(mxf[now], i);
        }
    }

    for(ll i = 1;i <= cnt;i++){
        if(mnf[i] != INF) continue;
        mnt = min(mnt, i);
        mxt = max(mxt, i);
    }

    while(m--){
        ll l, r; string s; cin >> l >> r >> s;
        ll lg = num[l], rg = num[r];
        if(mnt < lg || mxt > rg){
            cout << (s == "true" ? "Y" : "N");
        }
        else if(s == "true"){
            cout << (mnf[lg] < l || mxf[rg] > r ? "N" : "Y");
        }
        else cout << "Y";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
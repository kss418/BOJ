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
ll a[MAX], b[MAX], pl[MAX], nxt[MAX];

void run(){
    cin >> n >> m; ll la = 0;
    memset(nxt, -1, sizeof(nxt));
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[la] >= a[i]) continue;
        nxt[la] = i; la = i;
    }

    for(int i = 1;i <= m;i++) {
        cin >> b[i]; ll la = 0, now = 1, br = -1;
        while(now != -1){
            ll cur = a[now], pre = a[la];
            if(pre >= b[i]) { br = now; break; }
            ll diff = min(cur, b[i]) - pre; la = now;
            pl[now] = diff; now = nxt[now];
        }

        now = 1; vector <ll> tr;
        while(1){
            if(now == -1 || br == now) break;
            a[now] += pl[now]; tr.push_back(now);
            now = nxt[now];
        }

        for(int i = tr.size() - 1;i >= 0;i--){
            ll now = tr[i];
            while(nxt[now] != -1 && a[now] >= a[nxt[now]]) nxt[now] = nxt[nxt[now]];
        } 
    }

    for(int i = 1;i <= n;i++) cout << a[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


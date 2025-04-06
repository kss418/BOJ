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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], c[MAX];
bool use[MAX], cnt[MAX];

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> a[i];
    while(k--){
        ll x, idx; cin >> x >> idx;
        c[idx] = x; cnt[x] = 1;
    }

    ll now = m, one = 0;
    for(int i = n;i >= 1;i--){
        if(a[now] == 1){ one = i; break; }

        if(c[i]){ use[c[i]] = 1; continue; }
        while(now >= 1 && use[a[now]]) now--;
        if(now >= 1 && !cnt[a[now]]) c[i] = a[now--];
    }

    now = 1;
    for(int i = 1;i <= one;i++){
        if(c[i]){ use[c[i]] = 1; continue; }
        while(now <= m && use[a[now]]) now++;
        if(now <= m && !cnt[a[now]]) c[i] = a[now++];
    }

    ll result = n;
    for(int i = n;i >= 1;i--){
        if(!c[i]) result = min<ll>(result, i);
        else if(c[i] == 1){ result = i; break; }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


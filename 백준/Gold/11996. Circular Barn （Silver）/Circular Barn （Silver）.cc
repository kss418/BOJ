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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result = INF;
multiset <ll> idx;

bool chk(){
    for(int i = 0;i < n;i++){
        if(b[i] != 1) return 0;
    } 
    return 1;
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    
    for(int i = 0;i < n;i++){
        idx.clear();
        for(int j = 0;j < n;j++){
            b[j] = a[j];
            for(int k = 1;k <= b[j];k++) idx.insert(j);
        }

        ll cur = 0;
        for(int j = n + i;j > i;j--){
            ll now = j % n;
            if(b[now]) continue;

            auto lb = idx.lower_bound(now);
            ll num = lb != idx.begin() ? *--lb : *--idx.end();
            ll diff = (now - num + n) % n;
            cur += diff * diff;
            idx.erase(idx.find(num));
            b[now]++; b[num]--;
        }

        if(chk()) result = min(result, cur);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
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
ll a[MAX], num[MAX];
bool f[MAX];
vector <ll> arr;

void init(){
    for(int i = 1;i <= n;i++) num[i] = 0, f[i] = 0;
    arr.clear();
}

void run(){
    cin >> n >> m >> k; init();
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(!a[i]) f[i] = 1;
        a[i] = max(a[i], 1ll);
    }
    
    while(m--){
        ll s, e; cin >> s >> e;
        num[s] = max(num[s], e);
    }
    
    ll idx = 1;
    while(idx <= n){
        ll now = idx;
        while(now < num[idx]){
            if(num[now] && num[now] != num[idx]){
                cout << -1 << "\n"; return;
            }
            
            num[now] = num[idx];
            now++;
        }

        idx = max(idx + 1, now);
    }

    ll pre = 0, nxt = 0; idx = 1;
    while(idx <= n){
        pre = max(pre, a[idx]);
        nxt = max(nxt, a[idx]);

        if(!num[idx]){
            idx++; continue;
        }

        for(int i = idx + 1;i < num[idx];i++) nxt = max(nxt, a[i]);

        if(nxt > pre){
            for(int i = idx;i >= 0;i--){
                if(!i || (num[i] && num[i] < num[idx])){
                    cout << -1 << "\n"; return;
                }

                if(!f[i]) continue;
                a[i] = nxt; pre = nxt; break;
            }
        }

        if(f[num[idx]]) a[num[idx]] = pre + 1;
        if(a[num[idx]] <= pre){ cout << -1 << "\n"; return; }

        idx = num[idx];
    }

    for(int i = 1;i <= n;i++){
        if(a[i] > k){ cout << -1 << "\n"; return; }
    }

    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}
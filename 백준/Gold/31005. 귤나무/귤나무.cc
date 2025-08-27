#include <bits/stdc++.h>
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
ll a[MAX];
set <pll> ms;

void run(){
    cin >> n >> m; ll all = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; all += a[i];
        ms.insert({i, a[i]});
    }
    
    while(1){
        bool flag = 0;
        auto it = ms.begin();
        m -= (m / all) * all;

        while(it != ms.end()){
            if(it->y > m) all -= it->y, it = ms.erase(it);
            else{
                m -= it->y; it++;
                flag = 1;
            }
        }

        if(!flag) break;
    }

    cout << m;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
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

void run(){
    cin >> n >> m; vector <ll> result;

    for(int i = 1;i <= 4;i++){
        ll num = (1ll << i);
        if(!(m & num)) continue; 
        ll now = (1ll << num) - 1; n -= now;
        result.push_back(now);
    }

    if(n % 2 && (m & 1)){
        result.push_back(1);
        n--;
    }
    else if(n % 2 == 0 && (m & 1)){
        result.push_back(2);
        n -= 2;
    }
    else if(n % 2){
        result.push_back(1);
        result.push_back(2);
        n -= 3;
    }

    if(n < 0 || n % 2){ cout << -1 << "\n"; return; }
    result.push_back(n / 2);
    result.push_back(n / 2);

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}
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

ll solve1(ll cur){
    return cur / 3 + (cur % 3 ? 1 : 0);
}

ll solve2(ll cur){
    vector <ll> v; ll two = 0, ret = 0;
    while(cur > 1){
        bool flag = 0;
        for(int i = 2;i * i <= cur;i++){
            if(cur % i) continue;
            if(i == 2) two++; flag = 1;
            cur /= i; v.push_back(i); break;
        }

        if(flag) continue;
        if(cur == 2) two++;
        v.push_back(cur); break;
    }

    ret = v.size() - (two >> 1ll);
    return ret;
}

void run(){
    cin >> n;
    cout << solve1(n) << " " << max(solve2(n), 1ll);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


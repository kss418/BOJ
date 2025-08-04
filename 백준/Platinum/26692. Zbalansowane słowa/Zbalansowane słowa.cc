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
map <tll, ll> cnt3;
map <pll, ll> cnt1[3];
map <tll, ll> cnt2[3];
ll c[3], result;

void run(){
    cin >> s;

    cnt3[{0, 0, 0}]++;
    for(int i = 0;i < 3;i++) cnt1[i][{0, 0}]++;
    for(int i = 0;i < 3;i++) cnt2[i][{0, 0, 0}]++;
    
    for(auto& i : s){
        c[i - 'a']++;
        ll mn = min({c[0], c[1], c[2]});

        if(i == 'a') result += cnt1[0][{c[1], c[2]}];
        else if(i == 'b') result += cnt1[1][{c[0], c[2]}];
        else result += cnt1[2][{c[0], c[1]}];

        ll mn0 = min(c[1], c[2]), mn1 = min(c[0], c[2]), mn2 = min(c[0], c[1]);
        result += cnt2[0][{c[0], c[1] - mn0, c[2] - mn0}];
        result += cnt2[1][{c[0] - mn1 , c[1], c[2] - mn1}];
        result += cnt2[2][{c[0] - mn2, c[1] - mn2, c[2]}];

        if(c[0] && c[1] && c[2]) result += cnt3[{c[0] - mn, c[1] - mn, c[2] - mn}];

        cnt1[0][{c[1], c[2]}]++;
        cnt1[1][{c[0], c[2]}]++;
        cnt1[2][{c[0], c[1]}]++;

        cnt2[0][{c[0], c[1] - mn0, c[2] - mn0}]++;
        cnt2[1][{c[0] - mn1 , c[1], c[2] - mn1}]++;
        cnt2[2][{c[0] - mn2, c[1] - mn2, c[2]}]++;

        cnt3[{c[0] - mn, c[1] - mn, c[2] - mn}]++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
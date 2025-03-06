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
vector <ll> arr, result;

void run(){
    cin >> n >> s;
    for(int i = 0;i < n;i+=2){
        if(s[i] == s[i + 1]) continue;
        arr.push_back(s[i] == 'G');
    }

    for(auto& i : arr){
        if(!result.empty() && result.back() == i) continue;
        result.push_back(i);
    }

    if(!result.back()) result.pop_back();
    cout << result.size();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
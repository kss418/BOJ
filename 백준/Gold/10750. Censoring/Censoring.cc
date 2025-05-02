#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b, now;

bool chk(){
    if(now.size() < b.size()) return 0;
    for(int i = 0;i < b.size();i++){
        if(now[now.size() - i - 1] != b[b.size() - i - 1]) return 0;
    }
    return 1;
}

void run(){
    cin >> a >> b;
    for(auto& i : a){
        now.push_back(i);
        if(!chk()) continue;
        for(int i = 0;i < b.size();i++) now.pop_back();
    }

    cout << now;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
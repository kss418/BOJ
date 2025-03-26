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
constexpr ll MAX = 31; // SET MAX SIZE
constexpr ll MOD = 998244353;
set <string> arr[MAX], all;

bool chk(string& a, string& b){
    bool ua = 0, ub = 0, uab = 0;
    for(int i = 1;i <= n;i++){
        if(arr[i].count(a) && arr[i].count(b)) uab = 1;
        else if(arr[i].count(a)) ua = 1;
        else if(arr[i].count(b)) ub = 1;
    }

    bool ret = (ua && ub && uab);
    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> m;
        while(m--){
            cin >> s; 
            arr[i].insert(s);
            all.insert(s);
        }
    }

    ll result = 1;
    for(auto i : all){
        for(auto j : all){
            if(i == j) continue;
            if(chk(i, j)) result = 0;
        }
    }

    cout << (result ? "yes" : "no");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pl, one;
vector <ll> result;
vector <ll> mn, mx;

void cal(ll l, ll r){
    ll diff = r - l + 1;
    if(l && r != n - 1){
        ll now = (diff & 1) ^ (s[l - 1] == s[r + 1]);
        mn.push_back(now);
        mx.push_back(diff + (s[l - 1] == s[r + 1] ? 1 : 0));
    }
    else if(!l && r == n - 1){
        mn.push_back(0); 
        mx.push_back(diff - 1);
        one = 1;
    }
    else{
        mn.push_back(0);
        mx.push_back(diff);
        one = 1;
    }
}

void init(){
    ll s = accumulate(all(mn), pl);
    ll e = accumulate(all(mx), pl);
    for(int i = s;i <= e;i += (one ? 1 : 2)){
        result.push_back(i);
    }
} 

void run(){
    cin >> n >> s;
    for(int i = 1;i < n;i++){
        if(s[i] != 'F' && s[i] == s[i - 1]) pl++;
    }

    ll l = 0; 
    for(int i = 0;i < n;i++){
        if(s[i] == 'F' && (i == n - 1 || s[i + 1] != 'F')) cal(l, i), l = i + 1;
        else if(s[i] != 'F') l = i + 1;
    }

    init();
    cout << result.size() << "\n"; sort(all(result));
    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


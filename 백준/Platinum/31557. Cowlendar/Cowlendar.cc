#include <bits/stdc++.h>
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
ll a[MAX], result, mx = INF;
map <ll, bool> cnt, able;
vector <ll> num;

vector <ll> prime(ll v){
    vector <ll> ret;
    for(ll i = 1;i * i <= v;i++){
        if(v % i) continue;
        if(i <= mx) ret.push_back(i);
        if((v / i) <= mx) ret.push_back(v / i);
    }

    return ret;
}

void chk(ll v){
    vector <ll> now; ll cnt = 1;
    for(auto& i : num){
        now.push_back(i % v);
    }

    sort(all(now));
    for(int i = 1;i < now.size();i++){
        if(now[i] != now[i - 1]) cnt++;
    }

    if(cnt <= 3) result += v;
}

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++){
        cin >> a[i], cnt[a[i]] = 1;
        mx = min(mx, a[i]);
    }
    for(auto [x, y] : cnt) num.push_back(x);
    mx /= 4;

    if(num.size() <= 3){
        cout << (mx * (mx + 1)) / 2;
    }
    else{
        for(int i = 0;i < 4;i++){
            for(int j = i + 1;j < 4;j++){
                ll diff = abs(num[i] - num[j]);
                for(auto& k : prime(diff)) able[k] = 1;
            }
        }
        
        for(auto [x, y] : able) chk(x);
        cout << result;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
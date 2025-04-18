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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
multiset <pll> ms, rms;
vector <ll> vec;
ll result = INF;

ll cal(){
    vector <pll> back;
    for(auto& i : vec){
        pll now;
        if(!i){
            now = *ms.begin();
            ms.erase(ms.begin());
            rms.erase(rms.find({now.y, now.x}));
        }
        else if(i == 1){
            now = *--ms.end();
            ms.erase(--ms.end());
            rms.erase(rms.find({now.y, now.x}));
        }
        else if(i == 2){
            now = *rms.begin();
            rms.erase(rms.begin());
            ms.erase(ms.find({now.y, now.x}));
        }
        else{
            now = *--rms.end();
            rms.erase(--rms.end());
            ms.erase(ms.find({now.y, now.x}));
        }

        if(i <= 1) back.push_back(now);
        else back.push_back({now.y, now.x});
    }

    ll dx = (--ms.end())->x - ms.begin()->x;
    ll dy = (--rms.end())->x - rms.begin()->x;

    for(auto& [cy, cx] : back){
        ms.insert({cy, cx});
        rms.insert({cx, cy});
    }
    
    return dx * dy;
}

void bt(){
    if(vec.size() == 3){ result = min(result, cal()); return; }

    for(int i = 0;i < 4;i++){
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        ms.insert({a[i].x, a[i].y});
        rms.insert({a[i].y, a[i].x});
    }

    bt();
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
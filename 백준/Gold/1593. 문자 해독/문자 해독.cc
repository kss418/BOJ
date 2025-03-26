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
constexpr ll MAX = 61; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b;
ll result;
vector <ll> cnt, now;

void add(vector <ll>& vec, char c, ll v){
    if(c >= 'a' && c <= 'z') vec[c - 'a' + 26] += v;
    else vec[c - 'A'] += v;
}

bool chk(){
    for(int i = 0;i < 52;i++){
        if(cnt[i] != now[i]) return 0;
    }
    return 1;
}

void run(){
    cin >> n >> m >> a >> b;
    cnt.resize(MAX); now.resize(MAX);
    for(auto& i : a) add(cnt, i, 1);

    for(int i = 0;i < b.size();i++){
        add(now, b[i], 1);
        if(i >= a.size()) add(now, b[i - a.size()], -1);
        result += chk();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


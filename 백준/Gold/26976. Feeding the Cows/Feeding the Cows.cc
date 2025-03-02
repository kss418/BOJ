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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> v[2];
ll cnt;
string result;

void init(){
    for(int i = 0;i < 2;i++) {
        v[i].clear();
        v[i].push_back(MINF);
    }
    result.clear(); cnt = 0;
}

void run(){
    cin >> n >> m >> s; init();
    result.resize(n, '.');
    for(int i = 0;i < n;i++){
        ll now = (s[i] == 'G' ? 0 : 1);
        if(v[now].back() + m >= i) continue;
        if(i + m < n) result[i + m] = s[i];
        else{
            for(int j = n - 1;j >= 0;j--){
                if(result[j] != '.') continue;
                result[j] = s[i]; break;
            }
        }
        v[now].push_back(i + m);
    }

    for(auto& i : result) cnt += (i != '.');
    cout << cnt << "\n" << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}


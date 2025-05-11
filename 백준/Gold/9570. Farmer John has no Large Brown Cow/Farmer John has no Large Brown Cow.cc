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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
set <string> cnt[33];
map <string, ll> num[33];
vector <string> org[33];
vector <ll> have;
string st[MAX][33];
bool flag;

void run(){
    cin >> n >> m; m--;
    for(int i = 1;i <= n;i++){
        ll now = 0;
        while(1){
            cin >> st[i][now];
            if(st[i][now] == "cow.") break;
            cnt[now].insert(st[i][now]);
            now++;
        }
    }

    ll mul = 1;
    for(int i = 0;i < 33;i++){
        if(cnt[i].empty()) break;
        ll now = 0;
        mul *= cnt[i].size();
        for(auto& j : cnt[i]){
            num[i][j] = now;
            org[i].push_back(j);
            now++;
        }
        sort(all(org[i]));
    }

    for(int i = 1;i <= n;i++){
        ll now = 0, idx = 0, mul = 1;
        while(1){
            if(st[i][idx] == "cow.") break;
            idx++;
        }

        while(idx--){
            now += num[idx][st[i][idx]] * mul;
            mul *= cnt[idx].size();
        }
        have.push_back(now);
    }

    sort(all(have));
    for(auto& i : have) if(i <= m) m++;

    for(int i = 0;i < 33;i++){
        if(cnt[i].empty()) break;
        if(cnt[i].size() == 1 && !flag) continue;
        flag = 1;
        mul /= cnt[i].size();
        ll div = m / mul;
        cout << org[i][div] << " ";
        m -= div * mul;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


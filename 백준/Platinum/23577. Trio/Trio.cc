#include <bits/stdc++.h>
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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result, cnt[10][10][10][10], a[MAX];
string st[MAX];

ll num(string& s){
    return cnt[s[0] - '0'][s[1] - '0'][s[2] - '0'][s[3] - '0'];
}

void add(string& s){
    cnt[s[0] - '0'][s[1] - '0'][s[2] - '0'][s[3] - '0']++;
}

vector <tll> vec;
vector <ll> arr;
void bt(ll cur, ll cnt = 0){
    ll sz = arr.size();
    if(sz == cur){  
        result += num(s) * (cnt % 2 ? -1 : 1);
        return;
    }

    auto[idx, a, b] = vec[sz];
    for(int i = 0;i < 3;i++){
        char c = (i ? (i == 1 ? a : b) : '0');
        s[idx] = c;
        arr.push_back(i);
        bt(cur, cnt + (i ? 1 : 0));
        arr.pop_back();
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], st[i] = to_string(a[i]);

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            vec.clear();
            string now; now.resize(4);
            for(auto& i : now) i = '0';
            for(int k = 0;k < 4;k++){
                if(st[i][k] == st[j][k]) now[k] = st[i][k];
                else vec.push_back({k, st[i][k], st[j][k]});
            }

            s = now; bt(vec.size());
        }

        for(int j = 0;j < 16;j++){
            string now = st[i];
            for(int k = 0;k < 4;k++){
                if(j & (1ll << k)) continue;
                now[k] = '0';
            }

            add(now);
        }
    }
    
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
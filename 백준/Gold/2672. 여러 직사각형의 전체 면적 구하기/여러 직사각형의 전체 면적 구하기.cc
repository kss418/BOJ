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
constexpr ll MAX = 31; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pl[20101], cnt, la, result;
class query{
public:
    ll x, y1, y2, num;
    query(ll x, ll y1, ll y2, ll num) : x(x), y1(y1), y2(y2), num(num){}
    bool operator < (const query& ot) const{
        return x < ot.x;
    }
};
vector <query> q;

ll num(string &s){
    ll ret = 0, flag = 0;
    for(auto& i : s){
        if(i == '.'){ flag = 1; continue;}
        ret *= 10; ret += i - '0';
    }
    if(!flag) ret *= 10;

    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        string x, y, w, h;
        cin >> x >> y >> w >> h;
        ll lx = num(x), ly = num(y);
        ll lw = num(w), lh = num(h);
        q.push_back({lx, ly, ly + lh, 1});
        q.push_back({lx + lw, ly, ly + lh , -1});
    }
    sort(all(q));

    la = q[0].x;
    for(auto& i : q){
        auto[x, y1, y2, num] = i;
        result += (x - la) * cnt; la = x;

        for(int j = y1;j < y2;j++) {
            pl[j] += num;
            if(pl[j] == 1 && num == 1) cnt++;
            else if(pl[j] == 0 && num == -1) cnt--; 
        }
    }
    
    cout << (result / 100);
    if(result % 100) {
        cout << ".";
        if(result % 100 < 10) cout << '0';
        cout << result % 100;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
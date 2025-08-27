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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
int a[MAX * MAX], mx[MAX * MAX];
vector <int> arr;
deque <int> q, w;

class _uf { 
public:
    ll n; vector <int> p;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1);
    }

    int find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        p[b] = a; mx[a] = max(mx[a], mx[b]);
    }

    bool same(ll a, ll b) { return find(a) == find(b); }
};

ll num(ll cy, ll cx){
    return (cy - 1) * m + cx - 1;
}

void run(){
    cin >> n >> m >> k; ll result = 0;
    _uf uf(n * m); arr.clear(); 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[num(i, j)];
            arr.push_back(num(i, j));
            mx[num(i, j)] = a[num(i, j)];
        }
    }

    sort(all(arr), [](ll l, ll r){
        return a[l] > a[r];
    });

    for(auto& i : arr){
        q.push_back(i);
        while(!w.empty() && a[w.front()] >= a[i] + k){
            auto now = w.front(); w.pop_front();
            result += mx[uf.find(now)] == a[now];
        }

        while(!q.empty()){
            auto now = q.front(); q.pop_front();
            if(now % m && !uf.same(i, now - 1) && a[now - 1] >= a[i]){
                uf.merge(i, now - 1);
                q.push_back(now - 1);
            }

            if(now % m != m - 1 && !uf.same(i, now + 1) && a[now + 1] >= a[i]){
                uf.merge(i, now + 1);
                q.push_back(now + 1);
            }

            if(now / m && !uf.same(i, now - m) && a[now - m] >= a[i]){
                uf.merge(i, now - m);
                q.push_back(now - m);
            }

            if(now / m != n - 1 && !uf.same(i, now + m) && a[now + m] >= a[i]){
                uf.merge(i, now + m);
                q.push_back(now + m);
            }
        }

        w.push_back(i);
    }

    while(!w.empty()){
        auto now = w.front(); w.pop_front();
        result += mx[uf.find(now)] == a[now];
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}
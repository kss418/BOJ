#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
string st[MAX];
ll arr[MAX][MAX][21];
ll able[21];
pll l = {0, INF}, r = {0, 0}, u = {INF, 0}, d = {0, 0};

void dfsx(ll cx, ll cy, ll dx, ll dy, ll num){
    if(cx < l.y || cx > r.y) return;
    if(cx < 0 || cx >= 10 || cy < 0 || cy >= 10) {
        able[num] = 1;
        return;
    }
    arr[cy][cx][num] = 1;

    dfsx(cx + dx, cy, dx, dy, num);
    if(dy != 1) dfsx(cx + dx, cy - 1, dx, dy, num);
    if(dy != -1) dfsx(cx + dx, cy + 1, dx, dy, num);
}

void dfsy(ll cx, ll cy, ll dx, ll dy, ll num){
    if(cy > d.x || cy < u.x) return;
    if(cx < 0 || cx >= 10 || cy < 0 || cy >= 10) {
        able[num] = 1;
        return;
    }
    arr[cy][cx][num] = 1;

    dfsy(cx, cy + dy, dx, dy, num);
    if(dx != 1) dfsy(cx - 1, cy + dy, dx, dy, num);
    if(dx != -1) dfsy(cx + 1, cy + dy, dx, dy, num);
}

int main() {
    fastio;

    for(int i = 0; i < 10;i++) cin >> st[i];
    
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            if (st[i][j] == '0') continue;
            if(l.y > j) l = {i, j};
            if(r.y <= j) r = {i, j};
            if(u.x > i) u = {i, j};
            if(d.x <= i) d = {i, j};
        }
    }

    if(l.y == INF){
        cout << 0; return 0;
    }

    ll cnt = 1;
    for(auto& i : {l, r}){
        if(i.y == u.y && i.y == d.y) continue;
        ll dx = 0;
        if(i == l) dx = 1;
        else dx = -1;
        for(int dy = -1;dy <= 1;dy++) dfsx(i.y, i.x, dx, dy, cnt++);
    }

    for(auto& i : {u, d}){
        if(i.x == l.x && i.x == d.x) continue;
        ll dy = 0;
        if(i == u) dy = 1;
        else dy = -1;
        for(int dx = -1;dx <= 1;dx++) dfsy(i.y, i.x, dx, dy, cnt++);
    }

    ll result = 0;
    for(int cur = 1;cur < cnt;cur++){
        ll flag = 1;
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
                if(st[i][j] - '0' != arr[i][j][cur]) flag = 0;
            }
        }

        if(able[cur]) flag = 0;
        if(flag) result = 1;
    }

    if(result){
        set <pll> c;
        pll ul, ur, dl, dr, ru, lu, ld, rd;
        ul = {INF, 0};
        ur = {INF, 0};
        dl = {0, 0};
        dr = {0, 0};
        lu = {0, INF};
        ru = {0, 0};
        ld = {0, INF};
        rd = {0, 0};

        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
                if(st[i][j] == '0') continue;
                if(ul.x > i) ul = {i, j};
                if(ur.x >= i) ur = {i, j};
                if(dl.x < i) dl = {i, j};
                if(dr.x <= i) dr = {i, j};
                if(lu.y > j) lu = {i, j};
                if(ru.y < j) ru = {i, j};
                if(ld.y >= j) ld = {i, j};
                if(rd.y <= j) rd = {i, j};
            }
        }
        for(auto& i : {ul, ur, dl, dr, lu, ru, ld, rd}) c.insert(i);

        if(c.size() == 3){
            for(auto& i : c){
                cout << i.x + 1 << " " << i.y + 1 << "\n";
            }
        }
        else cout << 0;
    }
    else cout << 0;

    return 0;
}
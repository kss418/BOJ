#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 66;
const ll INF = 1e12;
ll n;
string st[MAX];

void dnc(ll cy, ll cx, ll sz){
    bool flag = 1;
    char num = st[cy][cx];
    for(int i = cy;i < cy + sz;i++){
        for(int j = cx;j < cx + sz;j++){
            if(st[i][j] != num) flag = 0;
        }
    }

    if(flag){
        cout << num;
        return;
    }

    cout << "(";

    ll nsz = sz / 2;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            dnc(cy + i * nsz, cx + j * nsz, nsz);
        }
    }

    cout << ")";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    dnc(0, 0, n);
}


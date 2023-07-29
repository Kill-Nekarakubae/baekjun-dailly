#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n, atk, t, a, h;
vector<bool> isMonster;
vector<ll> attack;
vector<ll> hp_change;
vector<ll> mon_atk;
vector<ll> mon_hp;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> atk;

    isMonster.resize(n);
    attack.resize(n);       // 내 공격지수
    hp_change.resize(n);    // n번 방에서 바뀌는 내 hp
    mon_atk.resize(n);      // n번 방에서 몬스터 공격지수
    mon_hp.resize(n);       // n번 방에서 몬스터 hp



    for (int i = 0; i < n; i++) {
        cin >> t >> a >> h;
        if (t == 1) {
            isMonster[i] = true;
            attack[i] = (i == 0) ? atk : attack[i - 1];
            mon_atk[i] = a;
            mon_hp[i] = h;
        }
        if (t == 2) {
            isMonster[i] = false;
            attack[i] = (i == 0) ? atk + a : attack[i - 1] + a;
            hp_change[i] = h;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (isMonster[i]) {
            ll needed_attack_cnt = (mon_hp[i] / attack[i]) + ((mon_hp[i] % attack[i] == 0) ? 0 : 1);
            ll endure_cnt = needed_attack_cnt - 1;
            ll needed_hp = endure_cnt * mon_atk[i];
            hp_change[i] = needed_hp * -1;
        }
    }

    ll currHP = 1;
    ll maxHP = 1;
    for (int i = n - 1; i >= 0; i--) {
        ll neededHP = currHP - hp_change[i];
        if (neededHP <= 0) neededHP = 1;
        currHP = neededHP;
        if (neededHP > maxHP)
            maxHP = neededHP;
    }
    cout << maxHP;

    return 0;
}

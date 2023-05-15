//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> parent, r;
//
//void make_set(int v) {
//    parent[v] = v;
//    r[v] = 0;
//}
//
//int find_set(int v) {
//    if (v == parent[v])
//        return v;
//    return parent[v] = find_set(parent[v]); // оптимизация: сжатие пути
//}
//
//void union_sets(int a, int b) {
//    a = find_set(a);
//    b = find_set(b);
//    if (a != b) {
//        if (r[a] < r[b])
//            swap(a, b);
//        parent[b] = a;
//        if (r[a] == r[b])
//            ++r[a];
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    parent.resize(n);
//    r.resize(n);
//
//    for (int i = 0; i < n; ++i)
//        make_set(i);
//
//    for (int i = 0; i < m; ++i) {
//        int a, b;
//        cin >> a >> b;
//        --a; --b; // приводим к нумерации с нуля
//        union_sets(a, b);
//    }
//
//    vector<vector<int>> groups(n);
//    for (int i = 0; i < n; ++i)
//        groups[find_set(i)].push_back(i);
//
//    vector<vector<int>> result;
//    for (auto& group : groups) {
//        vector<int> enemies;
//        for (auto& v : group) {
//            for (auto& w : group) {
//                if (v == w)
//                    continue;
//                // проверяем, есть ли между v и w вражда
//                // в данном случае просто добавляем пару (v, w) в список врагов
//                // в вашем случае может быть другая логика
//                enemies.push_back(v);
//                enemies.push_back(w);
//            }
//        }
//        sort(enemies.begin(), enemies.end());
//        enemies.erase(unique(enemies.begin(), enemies.end()), enemies.end());
//        vector<vector<int>> subgroups;
//        for (auto& v : group) {
//            bool added = false;
//            for (auto& subgroup : subgroups) {
//                if (find(subgroup.begin(), subgroup.end(), v) != subgroup.end())
//                    continue;
//                bool can_add = true;
//                for (auto& w : subgroup) {
//                    if (find(enemies.begin(), enemies.end(), v * n + w) != enemies.end()) {
//                        can_add = false;
//                        break;
//                    }
//                }
//                if (can_add) {
//                    subgroup.push_back(v);
//                    added = true;
//                    break;
//                }
//            }
//            if (!added) {
//                subgroups.push_back(vector<int>({ v }));
//            }
//        }
//        for (auto& subgroup : subgroups) {
//            result.push_back(subgroup);
//        }
//    }
//
//    for (auto& group : result) {
//        for (auto& v : group) {
//            cout << "Group "<<  v + 1 << " "  << endl; // приводим к нумерации с единицы
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <set>


using namespace std;


class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }

private:
    std::vector<int> parent;
};

class Enemy {
public:
    int enemy1;
    int enemy2;
    Enemy(int e1, int e2) : enemy1(e1), enemy2(e2) {}
};

void find_groups(int n, vector<Enemy>& enemies) {
    // Создаем объект класса DSU и объединяем множества людей, которые не являются врагами друг другу
    DSU dsu(n);
    for (auto& enemy : enemies) {
        int enemy1 = enemy.enemy1;
        int enemy2 = enemy.enemy2;
        dsu.unite(enemy1, enemy2 + n);
        dsu.unite(enemy2, enemy1 + n);
    }

    // Разбиваем множество людей на группы таким образом, чтобы в каждой группе не было вражды между людьми
    vector<set<int>> group_list;
    vector<bool> used(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            set<int> group;
            for (int j = i; j <= n; j++) {
                if (dsu.find(i) == dsu.find(j)) {
                    if (!used[j]) {
                        group.insert(j);
                        used[j] = true;
                    }
                }
            }
            group_list.push_back(group);
        }
    }

    // Выводим список групп на экран
    for (int i = 0; i < group_list.size(); i++) {
        cout << "Group " << i + 1 << ": ";
        for (auto person : group_list[i]) {
            cout << person << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 7;
    vector<Enemy> enemies = { Enemy(1, 2), Enemy(3, 4), Enemy(5, 6) };
    find_groups(n, enemies);
    return 0;
}
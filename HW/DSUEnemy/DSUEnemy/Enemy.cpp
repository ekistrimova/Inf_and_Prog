#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> parent, r;

void make_set(int v) {
    parent[v] = v;
    r[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // оптимизация: сжатие пути
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        if (r[a] == r[b])
            ++r[a];
    }
}

int main() {
    char mode = '0';
    cout << "Enter mode(1 friend/2 enemies): ";
    cin >> mode;
    if (mode == '1') {

        int n, m;
        cin >> n >> m;

        parent.resize(n);
        r.resize(n);

        for (int i = 0; i < n; ++i)
            make_set(i);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a; --b; // приводим к нумерации с нуля
            union_sets(a, b);
        }

        vector<vector<int>> groups(n);
        for (int i = 0; i < n; ++i)
            groups[find_set(i)].push_back(i);

        vector<vector<int>> result;
        for (auto& group : groups) {
            vector<int> enemies;
            for (auto& v : group) {
                for (auto& w : group) {
                    if (v == w)
                        continue;
                    // проверяем, есть ли между v и w вражда
                    // в данном случае просто добавляем пару (v, w) в список врагов
                    // в вашем случае может быть другая логика
                    enemies.push_back(v);
                    enemies.push_back(w);
                }
            }
            sort(enemies.begin(), enemies.end());
            enemies.erase(unique(enemies.begin(), enemies.end()), enemies.end());
            vector<vector<int>> subgroups;
            for (auto& v : group) {
                bool added = false;
                for (auto& subgroup : subgroups) {
                    if (find(subgroup.begin(), subgroup.end(), v) != subgroup.end())
                        continue;
                    bool can_add = true;
                    for (auto& w : subgroup) {
                        if (find(enemies.begin(), enemies.end(), v * n + w) != enemies.end()) {
                            can_add = false;
                            break;
                        }
                    }
                    if (can_add) {
                        subgroup.push_back(v);
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    subgroups.push_back(vector<int>({ v }));
                }
            }
            for (auto& subgroup : subgroups) {
                result.push_back(subgroup);
            }
        }

        for (auto& group : result) {
            for (auto& v : group) {
                cout << "Group " << v + 1 << " " << endl; // приводим к нумерации с единицы
            }
            cout << endl;
        }
    }
    else if (mode == '2') {
        system("cls");
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> enemies;

        parent.resize(n);
        r.resize(n);

        for (int i = 0; i < n; ++i)
            make_set(i);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            enemies.push_back({a, b});
        }
        for (int i = 0; i < n; i++) {
            std::unordered_map<int, int> wrong;
            for (auto e : enemies) {
                if (e.first == i) {
                    if (!wrong[e.second]) 
                        wrong[e.second] = find_set(e.second);
                }
                else if (e.second == i) {
                    if (!wrong[e.first]) 
                        wrong[e.first] = find_set(e.first);
                }
            }
            for (int j = 0; j < i; j++) {
                bool canAdd = true;
                for (auto it = wrong.begin(); it != wrong.end(); it++)
                    if (find_set((*it).second) == find_set(j))
                        canAdd = false;
                if (canAdd) {
                    union_sets(i, j);
                    break;
                }
            }
        }
        for (auto e : parent) {
            cout << e << " ";
        }
    }
    else {
        system("cls");
        cout << "Invalid mode!";
    }

    return 0;
}

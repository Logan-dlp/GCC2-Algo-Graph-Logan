#include "../../include/Graph/Algo.hpp"

#include <vector>

namespace graph::algo {
    // V = n = sommet
    // E = m = arete
    void ComputeRelatedComponents(int n, int m, int edges[][2], int comp[]) {
        int aux(0);

        for (int i = 0; i < n; ++i) {
            comp[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            if (comp[edges[i][0]] != comp[edges[i][1]]) {
                aux = comp[edges[i][0]];
                for (int j = 0; j < n; ++j) {
                    if (comp[j] == aux) {
                        comp[j] = comp[edges[i][1]];
                    }
                }
            }
        }
    }

    void ComputeRelatedComponentsOptimized(int n, int m, int edges[][2], int comp[]) {
        std::vector<std::vector<int>> L(n, std::vector<int>(0));

        for (int i = 0; i < n; ++i) {
            L[i].push_back(i);
            comp[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            if (comp[edges[i][0]] != comp[edges[i][1]]) {

                int x = comp[edges[i][0]];
                int y = comp[edges[i][1]];

                if (L[x].size() > L[y].size()) {
                    x = comp[edges[i][1]];
                    y = comp[edges[i][0]];
                }

                int size = (int)L[x].size();

                for (int z = 0; z < size; ++z) {
                    int temp = L[x].back();
                    L[x].pop_back();
                    L[y].push_back(temp);
                    comp[temp] = L[y][0];
                }
            }
        }
    }
}

#include "../../include/Graph/Algo.hpp"

namespace graph::algo {
    // V = n = sommet
    // E = m = arete
    void ComputeRelatedComponents(int n, int m, int edges[][2], int comp[]) {
        for (int i = 0; i < n; ++i) {
            comp[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            if (comp[edges[i][0]] != comp[edges[i][1]]) {
                int aux = comp[edges[i][0]];
                for (int j = 0; j < m; ++j) {
                    if (comp[j] == aux) {
                        comp[j] = comp[edges[i][1]];
                    }
                }
            }
        }
    }
}

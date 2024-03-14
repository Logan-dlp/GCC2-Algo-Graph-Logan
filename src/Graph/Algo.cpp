#include "../../include/Graph/Algo.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

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
                for (int j = 0; j < n; ++j) {
                    if (comp[j] == aux) {
                        comp[j] = comp[edges[i][1]];
                    }
                }
            }
        }
    }

    void DisplayComponentsSizes(int n, int m, int comp[]) {
        int isolated_points = 0;
        std::vector<int> other_sizes(n, 0); // Vecteur pour stocker les tailles des composantes

        for (int i = 0; i <= n; i++) {
            if (comp[i] == 1)
                isolated_points++;
            else
                other_sizes[comp[i]]++;
        }

        std::cout << "Nombre de points isoles : " << isolated_points << std::endl;
        std::cout << "Nombre de composantes par taille (ordre croissant) :" << std::endl;
        for (int i = 2; i <= n; i++) {
            if (other_sizes[i] > 0)
                std::cout << "Taille " << i << " : " << other_sizes[i] << std::endl;
        }
    }
}

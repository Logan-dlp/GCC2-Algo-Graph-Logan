#include "../../include/Graph/Utils.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace graph::utils {
    void GenerateRandomGraph(int n, int m, int edges[][2]) {
        std::srand(time(nullptr));
        for (int i = 0; i < m; ++i) {
            edges[i][0] = std::rand() % n;
            edges[i][1] = std::rand() % n;
        }
    }

    void DisplayEdgeMatrix(int m, int edges[][2]) {
        for (int i = 0; i < m; ++i) {
            std::cout << "[" << edges[i][0] << "," << edges[i][1] << "]";
        }
        std::cout << std::endl;
    }

    void DisplayComponentsMatrix(int n, int comp[]) {
        for (int i = 0; i < n; ++i) {
            std::cout << i << " -> " << comp[i] << std::endl;
        }
    }
}

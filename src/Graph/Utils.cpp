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

    void DisplayComponentsSizes(int n, int m, int comp[]) {
        int compOccurrences[n]; // Worst case: n components
        int compSizes[n+1]; // Worst case : one component with size equals n

        for (int i = 0; i < n; ++i) {
            compOccurrences[i] = 0;
            compSizes[i] = 0;
        }
        compSizes[n] = 0;

        // Compute Components occurrences
        for (int i = 0; i < n; ++i) {
            compOccurrences[comp[i]]++;
        }

        // Compute each component size
        for (int i = 0; i < n; ++i) {
            if (compOccurrences[i] > 0) {
                compSizes[compOccurrences[i]]++;
            }
        }

        // Display each component size and isolated vertices
        for (int i = 0; i < n+1; ++i) {
            if (compSizes[i] != 0){
                if (i == 1) {
                    std::cout << "There's " << compSizes[i] << " isolated vertice(s)." << std::endl;
                }
                else {
                    std::cout << "There's " << compSizes[i] << " component of size " << i << "." << std::endl;
                }
            }
        }
    }
}

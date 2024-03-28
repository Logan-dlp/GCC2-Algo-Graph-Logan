#include "../../include/Graph/Algo.hpp"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
        std::vector <std::vector<int>> L(n, std::vector<int>(0));

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

                int size = (int) L[x].size();

                for (int z = 0; z < size; ++z) {
                    int temp = L[x].back();
                    L[x].pop_back();
                    L[y].push_back(temp);
                    comp[temp] = L[y][0];
                }
            }
        }
    }

    void CreateRandomPoints(int n, Point2D points[]) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < n; ++i) {
            points[i].abs = std::rand() % 612;
            points[i].ord = std::rand() % 792;
        }
    }

    void ComputeEdges(int n, int m, Point2D points[], int edges[][3]) {
        int i(0);
        int j(i+1);
        int k(0);
        int dist(0);

        while (k < m) { // On parcourt toutes les arêtes
            dist = std::pow(points[i].abs - points[j].abs, 2) + std::pow(points[i].ord - points[j].ord, 2);
            edges[k][0] = i; // Point n°1 de l'arête k
            edges[k][1] = j; // Point n°2 de l'arête k
            edges[k][2] = dist; // Distance entre les 2 points
            j++;
            k++;
            if (j == n) {
                i++;
                j = i+1;
            }
        }
    }

    void SortEdgesMatrix(int m, int edges[][3]) {
        int i(0);
        int k(m);
        bool isOrdered(false);

        while (!isOrdered) {
            isOrdered = true;
            for (i = 0; i < k-1; ++i) {
                if (edges[i][2] > edges[i+1][2]) {
                    std::swap(edges[i][0], edges[i+1][0]); // x
                    std::swap(edges[i][1], edges[i+1][1]); // y
                    std::swap(edges[i][2], edges[i+1][2]); // w
                    isOrdered = false;
                }
            }
            k--;
        }
    }

    void Kruskal(int n, int m, int edges[][3], int tree[][2]) {
        int comp[n] = {0};
        int aux(0);
        int i(0), j(0);

        SortEdgesMatrix(m, edges);

        for (i = 0; i < n; ++i) {
            // A <- {}
            tree[i][0] = 0;
            tree[i][1] = 0;
            comp[i] = i;
        }

        for (i = 0; i < m; ++i) {
            if (comp[edges[i][0]] != comp[edges[i][1]]) {
                int x = edges[i][0];
                int y = edges[i][1];

                aux = comp[x];
                // A <- A u {xy}
                tree[j][0] = x;
                tree[j][1] = y;
                j++;

                for (int z = 0; z < n; ++z) {
                    if (comp[z] == aux) {
                        comp[z] = comp[y];
                    }
                }
            }
        }
    }
}

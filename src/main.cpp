#include <iostream>
#include <cstdlib>

#include "../include/Graph/Utils.hpp"
#include "../include/Graph/Algo.hpp"

namespace GraphUtils = graph::utils;
namespace GraphAlgo = graph::algo;

int main() {
    std::cout << "Practical exercices: connected components" << std::endl;

    int n, m; //Nombre de sommets et d'arêtes

    std::cout << "Entrer le nombre de sommets: ";
    std::cin >> n;
    std::cout << "Entrer le nombre d'arêtes: ";
    std::cin >> m;

    int edges[m][2];
    int comp[n];

    GraphUtils::GenerateRandomGraph(n, m, edges);
    GraphUtils::DisplayEdgeMatrix(m, edges);

    GraphAlgo::ComputeRelatedComponents(n, m, edges, comp);
    GraphUtils::DisplayComponentsMatrix(n, comp);

    GraphUtils::DisplayComponentsSizes(n, m, comp);

    // Kruskal
    std::cout << "Entrer le nombre de sommets pour kruskal: ";
    std::cin >> n;

    m = n * (n-1) / 2;
    GraphAlgo::Point2D points[n];
    int edgesForKruskal[m][3];
    int tree[n-1][2];

    GraphAlgo::CreateRandomPoints(n, points);
    GraphAlgo::ComputeEdges(n, m, points, edgesForKruskal);
    GraphAlgo::Kruskal(n, m, edgesForKruskal, tree);

    GraphUtils::ExportTreeInPSFormat(n, points, tree, "Kruskal.ps");

    return 0;
}
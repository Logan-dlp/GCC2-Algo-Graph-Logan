#include "../../include/Graph/Utils.hpp"

#include <iostream>
#include <fstream>
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

    void ExportTreeInPSFormat(int n, graph::algo::Point2D points[], int tree[][2], char* name){
        // Cree le fichier Exemple.ps qui affiche
        // les points et l'arbre de Kruskal.

        std::ofstream output;
        output.open(name,std::ios::out);
        output << "%!PS-Adobe-3.0" << std::endl;
        output << "%%BoundingBox: 0 0 612 792" << std::endl;
        output << std::endl;
        for(int i=0;i<n;i++){
            output << points[i].abs << " " << points[i].ord << " 3 0 360 arc" << std::endl;
            output << "0 setgray" << std::endl;
            output << "fill" << std::endl;
            output << "stroke"<< std::endl;
            output << std::endl;
        }
        output << std::endl;
        for(int i = 0; i < n - 1; ++i){
            output << points[tree[i][0]].abs << " " << points[tree[i][0]].ord
                   << " moveto" << std::endl;
            output << points[tree[i][1]].abs << " " << points[tree[i][1]].ord
                   << " lineto" << std::endl;
            output << "stroke" << std::endl;
            output << std::endl;
        }
        output << "showpage";
        output << std::endl;
    }
}

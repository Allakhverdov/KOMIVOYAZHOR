//
//  MatrixGraph.hpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#ifndef MatrixGraph_hpp
#define MatrixGraph_hpp
#include<iostream>
#include<vector>
struct MatrixGraph{
    explicit MatrixGraph(size_t VCount);
    ~MatrixGraph() = default;
    std::vector<std::vector<double>> GetAll();
    void AddEdge(int from, int to, double weight);
    int VCount() const;
    double GetWeight(int i, int j);
private:
    void OllFalse();
    void MakeMatrix(int VCount);
    std::vector<std::vector<double>> Matrix;
};

#endif /* MatrixGraph_hpp */

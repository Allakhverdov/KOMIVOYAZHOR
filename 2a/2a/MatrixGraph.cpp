//
//  MatrixGraph.cpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#include "MatrixGraph.hpp"

void MatrixGraph::MakeMatrix(int VCount)
{
    Matrix.resize(VCount);
    for(int i = 0 ; i < VCount; ++i)
    {
        Matrix[i].resize(VCount);
    }
}

void MatrixGraph::OllFalse()
{
    for(int i = 0; i < VCount(); ++i)
    {
        for(int j = 0; j < VCount(); ++j)
        {
            Matrix[i][j] = -1;
        }
    }
}

MatrixGraph::MatrixGraph(size_t VerticesCount)
{
    MakeMatrix(VerticesCount);
    OllFalse();
}

int MatrixGraph::VCount() const
{
    return Matrix.size();
}

void MatrixGraph::AddEdge(int from, int to, double weight)
{
    Matrix[from][to] = weight;
}

double MatrixGraph::GetWeight(int i, int j)
{
    return Matrix[i][j];
}

std::vector<std::vector<double>> MatrixGraph::GetAll()
{
    return Matrix;
}

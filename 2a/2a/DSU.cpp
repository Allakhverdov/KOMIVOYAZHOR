//
//  DSU.cpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#include "DSU.hpp"
DSU::DSU(size_t VCount)
{
    Trees.resize(VCount);
    for(int i = 0; i < VCount; ++i)
    {
        
        Trees[i].me = i;
        Trees[i].parent = i;
        Trees[i].rank = 0;
    }
}

int DSU::FindSet(int x)
{
    if (Trees[x].me != Trees[x].parent)
    {
        Trees[x].parent = FindSet(Trees[x].parent);
    }
    return Trees[x].parent;
}

void DSU::Link(int x_root,int y_root)
{
    if(Trees[x_root].rank > Trees[y_root].rank)
    {
        Trees[y_root].parent = x_root;
    }
    else if(Trees[x_root].rank < Trees[y_root].rank)
    {
        Trees[x_root].parent = y_root;
    }
    if(Trees[x_root].rank == Trees[y_root].rank)
    {
        Trees[x_root].rank = Trees[y_root].rank + 1;
        Trees[y_root].parent = x_root;
    }
}

void DSU::Union(int x,int y)
{
    Link(FindSet(x), FindSet(y));
}

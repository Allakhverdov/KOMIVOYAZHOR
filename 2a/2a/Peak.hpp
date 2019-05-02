
//  Peak.hpp

//эта структура - представление вершины

#ifndef Peak_hpp
#define Peak_hpp

struct Peak
{
    Peak(int parent, int me): parent(parent), me(me){}
    Peak(){}
    int parent = 0;         //это поле нужно для работы DSU
    int me = 0;
    int rank = 0;           //это поле нужно для работы DSU
};

#endif /* Peak_hpp */

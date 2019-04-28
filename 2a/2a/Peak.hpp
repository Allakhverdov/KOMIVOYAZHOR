//
//  Peak.hpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#ifndef Peak_hpp
#define Peak_hpp

struct Peak
{
    Peak(int parent, int me): parent(parent), me(me){}
    Peak(){}
    int parent = 0;
    int me = 0;
    int rank = 0;
};

#endif /* Peak_hpp */

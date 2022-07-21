// @File:       range.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/19/22 at 10:55 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef range_hpp
#define range_hpp

int normalize_value ( int value, int max, int min = 1 )
{
    return ( ( ( value - min ) * ( max - min ) ) / ( 100 - min ) ) + min;
}

#endif /* range_hpp */

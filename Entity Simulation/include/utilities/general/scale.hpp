// @File:       range.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/19/22 at 10:55 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef scale_hpp
#define scale_hpp

int scale_to ( int value, int percentage = 100, int min = 1 )
{
    return ( ( ( value - min ) * ( percentage - min ) ) / ( 100 - min ) ) + min;
}

#endif /* scale_hpp */

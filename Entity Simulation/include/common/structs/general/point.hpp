// @File:       point.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 11:23 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef point_hpp
#define point_hpp

#include <cmath>

struct POINT
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    
    // Constructors ......................................................... //
    
    POINT ( float x, float y )
    : x ( x )
    , y ( y )
    { }
    
    POINT ( float x, float y, float z )
    : x ( x )
    , y ( y )
    , z ( z )
    { }
    
    POINT  ( ) { }
    
    ~POINT ( ) { }
    
    // Functions ............................................................ //
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . [ GETTERS ]  . //
        
    double get_distance_from ( POINT & one, POINT & two )
    {
        return std::sqrt ( ( one.x - two.x ) * ( one.x - two.x ) +
                           ( one.y - two.y ) * ( one.y - two.y ) );
    }
};

#endif /* point_hpp */

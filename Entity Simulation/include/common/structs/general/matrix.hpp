// @File:       matrix.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 8/2/22 at 7:40 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef matrix_hpp
#define matrix_hpp

struct MATRIX
{
    int row    = 0;
    int column = 0;
    
    MATRIX ( int row, int column )
    : row    ( row )
    , column ( column )
    { }
    
    MATRIX  ( ) { }
    
    ~MATRIX ( ) { }
};

#endif /* display_hpp */

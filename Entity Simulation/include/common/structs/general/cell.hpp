// @File:       sector.hpp
// @Project:    Detection Grid
// @Author:     Justin Byrne
// @Date:       Created 7/15/22 at 7:32 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef cell_hpp
#define cell_hpp

#include "../../../utilities/renderer/SFML_utilities.hpp"

extern sf::RenderWindow window;

struct CELL : public POINT
{
    POINT start;
    POINT end;
    
    sf::RectangleShape shape;
    
    float size = 0;
    
    // Constructors ......................................................... //
    
    CELL ( int iterator_height, int iterator_width, int size )
    : _matrix ( iterator_height, iterator_width )
    , size    ( size )
    , start   ( iterator_width * size, iterator_height * size )
    , end     ( ( iterator_width  + 1 ) * size, ( iterator_width  + 1 ) * size )
    {
        this->shape = SFML::create_rectangle (
                          this->start,
                          POINT { this->size, this->size },
                          colors::gray_dark,
                          0,
                          colors::transparent
                      );
    }
    
    CELL  ( ) { }
    
    ~CELL ( ) { }
    
    // Functions ............................................................ //
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . [ GETTERS ]  . //
    
    int get_row ( )
    {
        return this->_matrix.row;
    }
    
    int get_column ( )
    {
        return this->_matrix.column;
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . [ INITIALIZER ]  . //
    
    void activate ( sf::Color color = colors::grid_a )
    {
        this->shape.setFillColor ( color );
    }
    
    void deactivate ( sf::Color color = colors::transparent )
    {
        this->shape.setFillColor ( color );
    }
    
private:
    
    MATRIX _matrix;
};

#endif /* cell_hpp */

// @File:       sector.hpp
// @Project:    Detection Grid
// @Author:     Justin Byrne
// @Date:       Created 7/15/22 at 7:32 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef cell_hpp
#define cell_hpp

#include "../../../utilities/renderer/SFML_utilities.hpp"

extern sf::RenderWindow window;

struct CELL
{
    POINT start;
    POINT end;
    
    sf::RectangleShape shape;
    
    float size = 0;
    
    // Constructors ......................................................... //
    
    CELL ( int iterator_height, int iterator_width, int size )
    {
        this->size          = size;
        
        this->matrix.row    = iterator_height;
        this->matrix.column = iterator_width;
        
        this->start.x       = iterator_width  * size;
        this->start.y       = iterator_height * size;
        
        this->end.x         = ( iterator_width  + 1 ) * size;
        this->end.y         = ( iterator_height + 1 ) * size;
        
        this->shape         = SFML::create_rectangle (
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
        return this->matrix.row;
    }
    
    int get_column ( )
    {
        return this->matrix.column;
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
    
    struct MATRIX
    {
        int row    = 0;
        int column = 0;
    }
    matrix;
};

#endif /* cell_hpp */

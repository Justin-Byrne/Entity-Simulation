// @File: 		uniform_grid.hpp
// @Project: 	Detection Grid
// @Author:		Justin Byrne
// @Date:		Created 7/15/22 at 9:14 AM
// @Copyright:	Copyright (c) 2022 Byrne-Systems

#ifndef uniform_grid_hpp
#define uniform_grid_hpp

#include <SFML/Graphics.hpp>

#include <unordered_map>

#include "../../config.hpp"

#include "../../common/structs/general/cell.hpp"

#include "../../common/static/colors.hpp"

extern sf::RenderWindow window;

extern std::unordered_map<std::string, CELL> grid;

namespace UNIFORM_GRID
{
    int generate ( )
    {
        for ( int i = 0; ( i * CELL_SIZE ) < WINDOW_HEIGHT; i++ )
            for ( int j = 0; ( j * CELL_SIZE ) < WINDOW_WIDTH; j++ )
                grid.insert (
                    std::pair<std::string, CELL>
                        (
                            std::string ( ) + std::to_string ( i ) + ", " + std::to_string ( j ),
                            CELL ( i, j, CELL_SIZE )
                        )
                    );
        
        return EXIT_SUCCESS;
    }

    int draw_n_reset ( CELL & cell )
    {
        window.draw ( cell.shape );
        cell.shape.setFillColor ( colors::transparent );

        return EXIT_SUCCESS;
    }

    int display ( )
    {
        for ( auto & cell : grid )
            draw_n_reset ( cell.second );
        
        return EXIT_SUCCESS;
    }

    int print ( )
    {
        printf ( "\nUNIFORM GRID - - - - - - - - - - - - - - - - \n\n" );
        
        for ( auto & cell : grid )
        {
            printf ( "id:\t( %d, %d )\n", cell.second.get_row ( ), cell.second.get_column ( ) );
            printf ( "x:\t%f, %f\n",      cell.second.start.x,     cell.second.end.x          );
            printf ( "y:\t%f, %f\n\n",    cell.second.start.y,     cell.second.end.y          );
        }
        
        return EXIT_SUCCESS;
    }
}

#endif /* uniform_grid_hpp */

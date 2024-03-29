// @File:       display.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/13/22 at 5:47 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef display_hpp
#define display_hpp

#include <unordered_map>

#include "../renderer/SFML_utilities.hpp"

#include "../../common/structs/custom/entity.hpp"

#include "../../common/structs/general/cell.hpp"
#include "../../common/structs/general/color.hpp"

extern sf::RenderWindow window;

extern sf::Color * generate_step_colors ( sf::Uint8 top_color, bool invert );


POINT rotate_origin, rotate_destination;

std::unordered_map<std::string, CELL> grid;


const int neighboring_cells[8][2] =
{
    { -1, -1 }, { -1,  0 }, { -1,  1 },
    {  0, -1 },             {  0,  1 },
    {  1, -1 }, {  1,  0 }, {  1,  1 }
};

sf::Color * step_colors = generate_step_colors ( 255, true );

namespace DISPLAY
{
    int rotation ( ENTITY & entity, COLOR color = { colors::red_apple, colors::red } )
    {
        rotate_origin      = entity.rotate ( entity.angle.a, entity.attributes.size );
        rotate_destination = entity.rotate ( entity.angle.b, entity.attributes.size );
        
        SFML::render_line ( window, entity.origin, rotate_origin,      color.origin      );
        SFML::render_line ( window, entity.origin, rotate_destination, color.destination );
        
        return EXIT_SUCCESS;
    }

    int body ( ENTITY & entity, COLOR color = { colors::body_a,  colors::transparent } )
    {
        SFML::render_circle ( window, entity.origin, entity.attributes.size, color.stroke, 1, color.fill );
        
        return EXIT_SUCCESS;
    }

    int sense ( ENTITY & entity, COLOR color = { colors::sense_c, colors::transparent } )
    {
        SFML::render_circle ( window, entity.origin, entity.attributes.sense, color.stroke, 1, color.fill );
        
        return EXIT_SUCCESS;
    }

    int sightline ( ENTITY & entity, ENTITY entities[], COLOR color = { colors::yellow_sun, colors::transparent } )
    {
        for ( auto seen : entity.seen )
            if ( seen.second )
                SFML::render_dotted_line (
                    window,
                    entity.origin,
                    entities[seen.first].origin,
                    LINE_SEGMENTS,
                    colors::yellow_sun,
                    false,
                    true
                );

        return EXIT_SUCCESS;
    }

    int steps ( ENTITY & entity )
    {
        sf::VertexArray entity_steps ( sf::Points, STEP_MAX );
        
        for ( int i = 0; i < STEP_MAX; i++ )
            entity_steps[i] =
            {
                sf::Vertex ( sf::Vector2f ( entity.steps[i].x, entity.steps[i].y ), step_colors[i] )
            };
        
        window.draw ( entity_steps );
        
        return EXIT_SUCCESS;
    }

    int grid_location ( ENTITY & entity )
    {
        std::string key = std::string ( ) + std::to_string ( entity.get_matrix_row ( ) ) + ", " + std::to_string ( entity.get_matrix_column ( ) );
        
        grid [ key ].activate ( );
        
        //....................................................................//
        
        for ( int i = 0; i < 8; i++ )
        {
            key = std::to_string ( entity.get_matrix_row ( ) + neighboring_cells[i][0] ) + ", " + std::to_string ( entity.get_matrix_column ( ) + neighboring_cells[i][1] );
            
            if ( grid [ key ].shape.getFillColor ( ) == colors::grid_b )
                 grid [ key ].activate( colors::grid_c );
            else
                 grid [ key ].activate( colors::grid_b );
        }
        
        return EXIT_SUCCESS;
    }
}

#endif /* display_hpp */

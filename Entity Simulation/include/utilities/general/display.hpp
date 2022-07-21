// @File:       debug.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/13/22 at 5:47 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef display_hpp
#define display_hpp

#include "../../utilities/renderer/SFML_utilities.hpp"
#include "../../config.hpp"

extern POINT rotate_origin;
extern POINT rotate_destination;

extern sf::RenderWindow window;
extern sf::Color      * step_colors;

extern std::unordered_map<std::string, CELL> grid;

int neighboring_cells[8][2] =
{
    { -1, -1 }, { -1,  0 }, { -1,  1 },
    {  0, -1 },             {  0,  1 },
    {  1, -1 }, {  1,  0 }, {  1,  1 }
};

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

    int sightline ( ENTITY & entity_a, ENTITY & entity_b, COLOR color = { colors::yellow_sun, colors::transparent } )
    {
        int diff_row    = std::abs ( entity_a.get_matrix_row    ( ) - entity_b.get_matrix_row    ( ) );
        int diff_column = std::abs ( entity_a.get_matrix_column ( ) - entity_b.get_matrix_column ( ) );

        if ( diff_row < 3 && diff_column < 3 )
        {
            if ( entity_a.is_inside_sense ( entity_b ) )
                SFML::render_dotted_line ( window, entity_a.origin, entity_b.origin, LINE_SEGMENTS, colors::red );

            if ( entity_b.is_inside_sense ( entity_a ) )
                SFML::render_dotted_line ( window, entity_b.origin, entity_a.origin, LINE_SEGMENTS, colors::blue_bright );
        }
            
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
        grid [ entity.grid_location ].activate ( );
        
        //....................................................................//
                
        std::string key;
        
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

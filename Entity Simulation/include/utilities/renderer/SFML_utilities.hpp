// @File:       SFML_utilities.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/10/22 at 1:13 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef SFML_utilities_hpp
#define SFML_utilities_hpp

namespace SFML
{
    // Create ............................................................... //

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . CIRCLE . . . . . . . . . . . . . . . . . . .  //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    sf::CircleShape create_circle ( POINT point, int radius, sf::Color stroke, int stroke_size, sf::Color fill )
    {
        sf::CircleShape result;
        
        result.setRadius           ( radius );
        result.setOrigin           ( result.getRadius ( ), result.getRadius ( ) );    // WARNING: Could cause issues with graphical translations !
        result.setOutlineColor     ( stroke );
        result.setOutlineThickness ( stroke_size );
        result.setFillColor        ( fill );
        result.setPosition         ( point.x, point.y );
        
        return result;
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . RECTANGLE . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    sf::RectangleShape create_rectangle ( POINT position, POINT dimensions, sf::Color stroke, int stroke_size, sf::Color fill )
    {
        sf::RectangleShape result;
        
        result.setSize             ( sf::Vector2f ( dimensions.x, dimensions.y ) );
        result.setOutlineColor     ( stroke );
        result.setOutlineThickness ( stroke_size );
        result.setFillColor        ( fill );
        result.setPosition         ( position.x, position.y );
        
        return result;
    }

    // Render ............................................................... //

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . CIRCLE . . . . . . . . . . . . . . . . . . .  //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    int render_circle ( sf::RenderTarget & window, POINT point, int radius, sf::Color stroke, int stroke_size, sf::Color fill )
    {
        sf::CircleShape circle = create_circle ( point, radius, stroke, stroke_size, fill );
        
        window.draw ( circle );
        
        return EXIT_SUCCESS;
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . RECTANGLE . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    int render_rectangle ( sf::RenderTarget & window, POINT position, POINT dimensions, sf::Color stroke, int stroke_size, sf::Color fill )
    {
        sf::RectangleShape rectangle = create_rectangle ( position, dimensions, stroke, stroke_size, fill );
        
        window.draw ( rectangle );
        
        return EXIT_SUCCESS;
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . LINE  . . . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    int render_line ( sf::RenderWindow & window, POINT origin, POINT destination, sf::Color color )
    {
        sf::Vertex line[] =
        {
            sf::Vertex ( sf::Vector2f ( origin.x,      origin.y ),      color ),
            sf::Vertex ( sf::Vector2f ( destination.x, destination.y ), color )
        };

        window.draw ( line, 2, sf::Lines );
        
        return EXIT_SUCCESS;
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . DOTTED LINE . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    int render_dotted_line ( sf::RenderWindow & window, POINT origin, POINT destination, int segments, sf::Color color )
    {
        sf::Vertex lines[segments];
        
        int line_space = POINT().get_distance_from ( origin, destination ) / segments;
        int angle      = ANGLE().get_angle ( origin, destination );
        
        for ( int i = 0; i < segments; i++ )
        {
            origin = ANGLE().rotate ( origin, angle, line_space );
            
            lines[i].position = sf::Vector2f ( origin.x, origin.y );
            lines[i].color    = color;
        }
        
        window.draw ( lines, segments, sf::Points );
        
        return EXIT_SUCCESS;
    }
}

#endif /* SFML_utilities_hpp */

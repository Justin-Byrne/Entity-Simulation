// @File:       step_colors.cpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/26/22 at 10:04 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef step_colors_hpp
#define step_colors_hpp

#include <SFML/Graphics/Color.hpp>

sf::Color * generate_step_colors ( sf::Uint8 top_color, bool invert = false )
{
    const  sf::Uint8 COLOR_MIN = 84;
    
    static sf::Color result[STEP_MAX];
    
    int difference = ( invert ) ? ( top_color - COLOR_MIN ) / STEP_MAX : top_color / STEP_MAX;
    
    if ( invert )
        for ( int i = STEP_MAX - 1; i > -1; i-- )
            result[i] =
            {
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) ),
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) ),
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) )
            };
    else
        for ( int i = 0; i < STEP_MAX; i++ )
            result[i] =
            {
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) ),
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) ),
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) )
            };
    
    return result;
}

#endif /* step_colors_hpp */

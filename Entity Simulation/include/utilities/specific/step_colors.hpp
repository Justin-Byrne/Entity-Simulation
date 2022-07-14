//
//  step_colors.hpp
//  Entity Simulation
//
//  Created by Justin Byrne on 6/26/22.
//

#ifndef step_colors_hpp
#define step_colors_hpp

#include <SFML/Graphics/Color.hpp>

/// Generates a series of gray colors
/// @param      top_color                 Highest number, preferable white... RGB values
/// @param      invert                 Invert colors
sf::Color * generate_step_colors ( sf::Uint8 top_color, bool invert = false )
{
    const  sf::Uint8 COLOR_MIN = 84;
    
    static sf::Color result[STEP_MAX];
    
    int difference = ( invert ) ? ( top_color - COLOR_MIN ) / STEP_MAX : top_color / STEP_MAX;
    
    if ( invert )
        for ( int i = STEP_MAX - 1; i > -1; i-- )
            result[i] = {
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) ),
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) ),
                static_cast<sf::Uint8> ( ( top_color - ( i * difference ) ) )
            };
    else
        for ( int i = 0; i < STEP_MAX; i++ )
            result[i] = {
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) ),
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) ),
                static_cast<sf::Uint8> ( ( ( (sf::Uint8) i + 1 ) * difference ) )
            };
    
    return result;
}

#endif /* step_colors_hpp */

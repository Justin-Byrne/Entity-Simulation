// @File:       main.cpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 10:04 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#include <SFML/Graphics.hpp>

#include "include/headers.hpp"

sf::RenderWindow window;

int main ( int argc, const char * argv[] )
{
    srand ( ( unsigned ) time ( NULL ) );                                       // Seed Randomizer
    
    
    window.create ( sf::VideoMode ( WINDOW_WIDTH, WINDOW_HEIGHT ), WINDOW_TITLE );
    
    window.setFramerateLimit ( FRAME_RATE );

    
    SIMULATION & simulation = SIMULATION::instance ( );
    
    simulation.populate ( );

    
    while ( window.isOpen ( ) )                                                 // Simulation Loop
    {
        window.clear ( colors::gray_dark );                                     // Clear screen
 
        simulation.update ( );

        window.display ( );                                                     // Update the window

        sf::Event event;                                                        // Process events
        
        while ( window.pollEvent ( event ) )
            if ( event.type == sf::Event::Closed ) window.close ( );            // Close window: exit
    }
 
    return EXIT_SUCCESS;
}
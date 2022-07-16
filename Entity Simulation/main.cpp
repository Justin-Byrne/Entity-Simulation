// @File:       main.cpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 10:04 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "include/headers.hpp"

#pragma mark - GLOBAL VARIABLE DECLARATIONS

sf::RenderWindow window;

ENTITY entity[ENTITY_MAX];

POINT rotate_origin, rotate_destination;

sf::Color * step_colors = generate_step_colors ( 255, true );

std::unordered_map<std::string, CELL> grid;

#pragma mark - GLOBAL FUNCTION DECLARATIONS

int seed_randomizer        ( );
int init_window            ( );
int populate_with_entities ( int pad_entities = 0 );

#pragma mark - MAIN

int main ( int argc, const char * argv[] )
{
    seed_randomizer ( );
    
    init_window ( );
  
    populate_with_entities ( 50 );
    
    #if DEBUG_UNIFORM_GRID
    UNIFORM_GRID::generate ( );
    #endif
    
    while ( window.isOpen ( ) )                                                 // Simulation Loop
    {
        window.clear ( colors::gray_dark );                                     // Clear screen
 
        #if DEBUG_UNIFORM_GRID
        UNIFORM_GRID::display ( );
        #endif
        
        for ( int i = 0; i < ENTITY_MAX; i++ )
        {
            switch ( entity[i].state )
            {
                case SILENT:
                case ROTATE:
                    
                    #if DEBUG_ROTATE
                    DISPLAY::rotation ( entity[i] );
                    #endif
                    
                    ( entity[i].angle.clockwise ) ? entity[i].angle.advance ( ) : entity[i].angle.regress ( );
                    
                    if ( entity[i].angle.distance == 0 )
                        entity[i].set_walk ( RNG::get_random ( 1, 30 ) );
                    
                    break;
                    
                case MOVING:
                    
                    entity[i].next_step ( 2 );

                    if ( entity[i].walk == 0 )
                        entity[i].set_angle ( entity[i].angle.b, RNG::get_random ( 0, 360 ) );

                    break;
            }
            
            #if DEBUG_BODY
            DISPLAY::body ( entity[i] );
            #endif
            
            #if DEBUG_SENSE
            DISPLAY::sense( entity[i] );
            #endif
            
            #if DEBUG_SIGHTLINE
            for ( int j = 1; j < ENTITY_MAX; j++ )
                DISPLAY::sightline ( entity[i], entity[j] );
            #endif
            
            #if DEBUG_STEPS
            DISPLAY::steps ( entity[i] );
            #endif
            
            #if DEBUG_UNIFORM_GRID
            DISPLAY::grid_location ( entity[i] );
            #endif
        }
        
        window.display ( );                                                     // Update the window
        
        sf::Event event;                                                        // Process events
        
        while ( window.pollEvent ( event ) )
            if ( event.type == sf::Event::Closed ) window.close ( );            // Close window: exit
    }
 
    return EXIT_SUCCESS;
}

int seed_randomizer ( )
{
    srand ( ( unsigned ) time ( NULL ) );
    
    return EXIT_SUCCESS;
}

int init_window ( )
{
    window.create ( sf::VideoMode ( WINDOW_WIDTH, WINDOW_HEIGHT ), WINDOW_TITLE );
    
    window.setFramerateLimit ( FRAME_RATE );
    
    return EXIT_SUCCESS;
}

int populate_with_entities ( int pad_entities )
{
    for ( int i = 0; i < ENTITY_MAX; i++ )
    {
        entity[i] =
        {
            POINT {
                (float) RNG::get_random ( pad_entities, WINDOW_WIDTH  - pad_entities ),
                (float) RNG::get_random ( pad_entities, WINDOW_HEIGHT - pad_entities )
            },
            RNG::get_random ( 0, 360 ),
            RNG::get_random ( 0, 360 )
        };
    }
    
    return EXIT_SUCCESS;
}

// @File:       simulation.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/23/22 at 9:55 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef simulation_hpp
#define simulation_hpp

#include <stdlib.h>

#include "../common/structs/custom/entity.hpp"

#include "../common/structs/general/point.hpp"

#include "../utilities/general/RNG.hpp"

#include "../utilities/general/display.hpp"

struct SIMULATION
{
    static SIMULATION & instance ( )
    {
        static SIMULATION simulation;
        
        return simulation;
    };
    
    int populate ( )
    {
        this->_add_entities ( );
    
        #if DEBUG_UNIFORM_GRID
        UNIFORM_GRID::generate ( );
        #endif
        
        return EXIT_SUCCESS;
    }
    
    int update ( )
    {
        for ( int i = 0; i < ENTITY_MAX; i++ )
        {
            _state_control ( this->_entity[i] );
            _display_block ( this->_entity[i] );
        }
        
        #if DEBUG_UNIFORM_GRID
        UNIFORM_GRID::display ( );
        #endif
        
        return EXIT_SUCCESS;
    }

private:

    ENTITY _entity[ENTITY_MAX];
    
    SIMULATION ( ) { };
    
    SIMULATION ( const SIMULATION & );
    
    SIMULATION & operator = ( const SIMULATION & );
    
    int _add_entities ( )
    {
        for ( int i = 0; i < ENTITY_MAX; i++ )
        {
            this->_entity[i] =
            {
                POINT
                {
                    (float) RNG::get_random ( 0, WINDOW_WIDTH  ),
                    (float) RNG::get_random ( 0, WINDOW_HEIGHT )
                },
                RNG::get_random ( 0, 360 ),
                RNG::get_random ( 0, 360 )
            };
    
            #if DEBUG_ENTITY_PRINT_ATTRIBUTES
            this->_entity[i].print_attributes ( );
            #endif
        }
        
        return EXIT_SUCCESS;
    }
    
    int _state_control ( ENTITY & entity )
    {
        switch ( entity.state )
        {
            case SILENT:
            case ROTATE:
    
                #if DEBUG_ROTATE
                DISPLAY::rotation ( entity );
                #endif
    
                ( entity.angle.clockwise )
                    ? entity.angle.advance ( )
                    : entity.angle.regress ( );
    
                if ( entity.angle.distance == 0 )
                     entity.set_walk ( RNG::get_random ( entity.attributes.walk_distance ) );
    
                break;
    
            case MOVING:
    
                entity.next_step ( );
    
                for ( int i = 0; i < ENTITY_MAX; i++ )                          // proximity check
                    if ( i != entity.id )
                        entity.check_proximity ( this->_entity[i] );
                    else
                        continue;
                
                if ( entity.walk == 0 )
                     entity.set_angle ( entity.angle.b, RNG::get_random ( 0, 360 ) );
    
                break;
        }
    
        return EXIT_SUCCESS;
    }
    
    int _display_block ( ENTITY & entity )
    {
        #if DEBUG_BODY
        DISPLAY::body ( entity );
        #endif
    
        #if DEBUG_SENSE
        DISPLAY::sense ( entity );
        #endif
    
//        #if DEBUG_SIGHTLINE
//        for ( int i = 1; i < ENTITY_MAX; i++ )
//            DISPLAY::sightline ( entity, this->_entity[i] );
//        #endif
    
        #if DEBUG_SIGHTLINE
        DISPLAY::sightline ( entity, this->_entity );
        #endif
        
        #if DEBUG_STEPS
        DISPLAY::steps ( entity );
        #endif
    
        #if DEBUG_UNIFORM_GRID
        DISPLAY::grid_location ( entity );
        #endif
    
        return EXIT_SUCCESS;
    }
};

#endif /* simulation_hpp */

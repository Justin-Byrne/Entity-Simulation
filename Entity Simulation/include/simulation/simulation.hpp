// @File:       simulation.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/23/22 at 9:55 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef simulation_hpp
#define simulation_hpp

struct SIMULATION
{
    static SIMULATION & instance ( )
    {
        static SIMULATION simulation;
        
        return simulation;
    };
    
    int populate_with_entities ( int padding = 0 )
    {
        for ( int i = 0; i < ENTITY_MAX; i++ )
        {
            this->entity[i] =
            {
                POINT
                {
                    (float) RNG::get_random ( padding, WINDOW_WIDTH  - padding ),
                    (float) RNG::get_random ( padding, WINDOW_HEIGHT - padding )
                },
                RNG::get_random ( 0, 360 ),
                RNG::get_random ( 0, 360 )
            };
    
            #if DEBUG_ENTITY_PRINT_ATTRIBUTES
            this->entity[i].print_attributes ( );
            #endif
        }
    
        #if DEBUG_UNIFORM_GRID
        UNIFORM_GRID::generate ( );
        #endif
        
        return EXIT_SUCCESS;
    }
    
    int update ( )
    {
        for ( int i = 0; i < ENTITY_MAX; i++ )
        {
            state_control ( this->entity[i] );
            display_block ( this->entity[i] );
        }
        
        #if DEBUG_UNIFORM_GRID
        UNIFORM_GRID::display ( );
        #endif
        
        return EXIT_SUCCESS;
    }

private:

    ENTITY entity[ENTITY_MAX];
    
    SIMULATION ( ) { };                                                         // Default
    
    SIMULATION ( const SIMULATION & );                                          // Copy
    
    SIMULATION & operator = ( const SIMULATION & );                             // Copy Assignment
    
    int state_control ( ENTITY & entity )
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
    
                if ( entity.walk == 0 )
                    entity.set_angle ( entity.angle.b, RNG::get_random ( 0, 360 ) );
    
                break;
        }
    
        return EXIT_SUCCESS;
    }
    
    int display_block ( ENTITY & entity )
    {
        #if DEBUG_BODY
        DISPLAY::body ( entity );
        #endif
    
        #if DEBUG_SENSE
        DISPLAY::sense ( entity );
        #endif
    
        #if DEBUG_SIGHTLINE
        for ( int i = 1; i < ENTITY_MAX; i++ )
            DISPLAY::sightline ( entity, entity[i] );
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

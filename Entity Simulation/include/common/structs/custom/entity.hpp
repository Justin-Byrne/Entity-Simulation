// @File:       entity.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:39 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef entity_hpp
#define entity_hpp

#include "../../static/states.hpp"
#include "../../structs/general/point.hpp"
#include "../../structs/general/angle.hpp"
#include "../../structs/custom/attributes.hpp"

struct ENTITY
{
    int id;
    static int ID;
    
    int state = SILENT;
    int walk  = 0;
    
    POINT origin = { 0, 0 };
    POINT steps[STEP_MAX];
    
    ANGLE angle;
    
    ATTRIBUTES attributes;
    
    std::string grid_location;
    
    // Constructors ......................................................... //
    
    ENTITY ( POINT origin )
    {
        this->origin = origin;
        this->id     = ID++;
        
        this->update_grid_location ( );
    }
    
    ENTITY ( POINT origin, int angle_a, int angle_b )
    {
        this->origin = origin;
        this->id     = ID++;
        
        this->angle.a = angle_a;
        this->angle.b = angle_b;
        
        this->angle.init ( );
        this->update_grid_location ( );
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . CONSTRUCTORS (GENERIC) . . . . . . . . . . .  //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    ENTITY  ( ) { };

    ~ENTITY ( ) { };

    // Functions ............................................................ //

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . SETTERS . . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    void set_walk ( int steps = 2 )
    {
        this->state = MOVING;
        
        this->walk = steps;
    }
    
    void set_angle ( int angle_a, int angle_b )
    {
        this->state = SILENT;
        
        this->angle = { angle_a, angle_b };
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . GETTERS . . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //

    POINT rotate ( int degree )
    {
        this->state = ROTATE;

        return ANGLE().rotate ( this->origin, degree );
    }

    POINT rotate ( int degree, int step_length )
    {
        this->state = ROTATE;

        return ANGLE().rotate ( this->origin, degree, step_length );
    }
    
    int get_matrix_row ( )
    {
        return this->matrix.row;
    }
    
    int get_matrix_column ( )
    {
        return this->matrix.column;
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . ITERATORS . . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    void next_step ( int step_size = 2 )
    {
        step_size = this->attributes.walk_speed + step_size;
        
        #if DEBUG_STEPS
        this->cache_steps ( );
        #endif
        
        this->origin = ANGLE().rotate ( this->origin, this->angle.a, step_size );
        
        this->walk = ( step_size > this->walk ) ? 0 : this->walk - step_size;
        
        this->check_boundary ( );
        
        this->update_grid_location ( );
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . VALIDATORS  . . . . . . . . . . . . . . . . . //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    void check_boundary ( )
    {
        this->origin.x = ( this->origin.x <= 0 ) ? 1 : this->origin.x;                              // left
        this->origin.y = ( this->origin.y <= 0 ) ? 1 : this->origin.y;                              // top
        
        this->origin.x = ( this->origin.x >= WINDOW_WIDTH  ) ? WINDOW_WIDTH  - 1 : this->origin.x;  // right
        this->origin.y = ( this->origin.y >= WINDOW_HEIGHT ) ? WINDOW_HEIGHT - 1 : this->origin.y;  // bottom
    }
    
    bool is_inside_sense ( ENTITY & entity )
    {
        int distance = POINT().get_distance_from ( this->origin, entity.origin ) - this->attributes.sense;
        
        return ( distance <= entity.attributes.size ) ? true : false;
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . MISC . . . . . . . . . . . . . . . . . . . .  //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    void print_attributes ( )
    {
        std::string OUTPUT = std::string ( ) +
            "Entity:               %d\n"     +
            "----------------------------\n" +
            "Vitality:             %d <<<\n" +
            "----------------------------\n" +
            "Size:                 %d\n"     +
            "Sense:                %d\n"     +
            "Health:               %d\n"     +
            "Walk Speed:           %d\n"     +
            "Walk Distance:        %d\n"     +
            "Stamina:              %d\n"     +
            "Stamina Refactor:     %d\n\n";
        
        printf (
                OUTPUT.c_str ( ),
                this->id,
                attributes.vitality,
                attributes.size,
                attributes.sense,
                attributes.health,
                attributes.walk_speed,
                attributes.walk_distance,
                attributes.stamina,
                attributes.stamina_refactor
        );
    }
    
private:
    
    // Functions ............................................................ //

    // . . . . . . . . . . . . . . . . . . . . . . . . //
    // . MISC . . . . . . . . . . . . . . . . . . . .  //
    // . . . . . . . . . . . . . . . . . . . . . . . . //
    
    void cache_steps ( )
    {
        for ( int i = STEP_MAX - 1; i > 0; i-- )
            this->steps[i] = this->steps[i - 1];
        
        this->steps[0] = this->origin;
    }
    
    void update_grid_location ( )
    {
        this->matrix.row    = std::floor ( this->origin.y / CELL_SIZE );
        this->matrix.column = std::floor ( this->origin.x / CELL_SIZE );
        
        this->grid_location = std::string ( ) + std::to_string ( this->matrix.row ) + ", " + std::to_string ( this->matrix.column );
    }
    
    struct MATRIX
    {
        int row    = 0;
        int column = 0;
    }
    matrix;
};

int ENTITY::ID;

#endif /* entity_hpp */

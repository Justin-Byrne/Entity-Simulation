// @File:       entity.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:39 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef entity_hpp
#define entity_hpp

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
    
    std::unordered_map<int, int> seen;
    
//    int seen [ SEEN_MAX ];
    
    // Constructors ......................................................... //
    
    ENTITY ( POINT origin )
    : origin ( origin )
    , id     ( ID++   )
    {
        this->_update_grid_location ( );
    }
    
    ENTITY ( POINT origin, int angle_a, int angle_b )
    : origin ( origin )
    , id     ( ID++   )
    {
        this->angle.a = angle_a;
        this->angle.b = angle_b;
    
        this->angle.init ( );
        this->_update_grid_location ( );
    }
    
    ENTITY  ( ) { };

    ~ENTITY ( ) { };

    // Functions ............................................................ //

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . [ SETTERS ]  . //
    
    void set_walk ( int distance )
    {
        this->state = MOVING;
        
        this->walk  = distance;
    }
    
    void set_angle ( int angle_a, int angle_b )
    {
        this->state = SILENT;
        
        this->angle = { angle_a, angle_b };
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . [ GETTERS ]  . //

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
        return this->_matrix.row;
    }
    
    int get_matrix_column ( )
    {
        return this->_matrix.column;
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . [ ITERATORS ]  . //
    
    void next_step ( int step_size = 1 )
    {
        #if DEBUG_STEPS
        this->_cache_steps ( );
        #endif
        
        if ( this->_walk_gait < this->attributes.walk_speed )                   // increase _walk_gait
             this->_walk_gait += 1;
        
        step_size     += this->_walk_gait;                                      // calculate step_size
        
        this->origin   = ANGLE().rotate ( this->origin, this->angle.a, step_size );
        
        if ( step_size > this->walk )
            this->walk = this->_walk_gait = 0;                                  // reset walk && _walk_gait
        else
            this->walk -= step_size;                                            // subtract step_size from walk
        
        // TODO: CHECK COLLISION AGAINST OTHER ENTITIES

        this->_check_boundary ( );
        
        this->_update_grid_location ( );
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . .  [ VALIDATORS ]  . //
    
    bool is_inside_sense ( ENTITY & entity )
    {
        int distance = POINT().get_distance_from ( this->origin, entity.origin ) - this->attributes.sense;
        
        return ( distance <= entity.attributes.size ) ? true : false;
    }
    
    bool is_near ( ENTITY & entity )
    {
        int diff_row    = std::abs ( this->_matrix.row    - entity.get_matrix_row    ( ) );
        int diff_column = std::abs ( this->_matrix.column - entity.get_matrix_column ( ) );

        return ( diff_row < 3 && diff_column < 3 ) ? true : false;
    }
    
    void check_proximity ( ENTITY & entity )
    {
        if ( this->is_near ( entity ) )
        {
            if ( this->is_inside_sense ( entity ) )                             // I SEE YOU
            {
                if ( ! this->seen [ entity.id ] )                   // == 0
                {
                       this->seen [ entity.id ] = 1;
                }
                else                                                // != 0
                {
                       this->seen.insert ( { entity.id, 1 } );
                }
            }
            else                                                                // I CAN'T SEE YOU YET || ANYMORE
            {
                if ( this->seen [ entity.id ] )
                {
                     this->seen.erase ( entity.id );
                }
            }
        }
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  [ MISC ]  . //

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
        
        std::printf (
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
    
    void print_seen ( )
    {
        if ( ! this->seen.empty ( ) )
        {
            std::printf ( "Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.o\n\n" );
            
            for ( auto & element : this->seen )
                if ( element.second == 1 )
                     std::printf (
                         "[%d] see: --> entity: %d\n    value: %d\n\n------------------------\n\n",
                         this->id,
                         element.first,
                         element.second
                     );
        }
    }

private:
    
    int _walk_gait = 0;
    
    struct MATRIX
    {
        int row    = 0;
        int column = 0;
    }
    _matrix;
    
    // Functions ............................................................ //

    // . . . . . . . . . . . . . . . . . . . . . . . . . .  [ VALIDATORS ]  . //
    
    void _check_boundary ( )
    {
        this->origin.x = ( this->origin.x <= 0 ) ? 1 : this->origin.x;                              // left
        this->origin.y = ( this->origin.y <= 0 ) ? 1 : this->origin.y;                              // top
        
        this->origin.x = ( this->origin.x >= WINDOW_WIDTH  ) ? WINDOW_WIDTH  - 1 : this->origin.x;  // right
        this->origin.y = ( this->origin.y >= WINDOW_HEIGHT ) ? WINDOW_HEIGHT - 1 : this->origin.y;  // bottom
    }
    
    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  [ MISC ]  . //
    
    void _cache_steps ( )
    {
        for ( int i = STEP_MAX - 1; i > 0; i-- )
            this->steps[i] = this->steps[i - 1];
        
        this->steps[0] = this->origin;
    }
    
    void _update_grid_location ( )
    {
        this->_matrix.row    = std::floor ( this->origin.y / CELL_SIZE );
        this->_matrix.column = std::floor ( this->origin.x / CELL_SIZE );
    }
};

int ENTITY::ID;

#endif /* entity_hpp */

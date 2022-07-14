// @File:       attributes.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:30 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef attributes_hpp
#define attributes_hpp

#include "../../../utilities/general/RNG.hpp"

//#include <random>       // TODO: MOVE TO RNG.HPP

struct ATTRIBUTES
{
    int vitality;
    
    int size;
    int sense;
    
    int health;
    int walk_speed;
    int walk_distance;
    int stamina;
    int stamina_refactor;
    
    // Constructors ......................................................... //
    
    ATTRIBUTES ( )
    {
        // . . . . . . . . . . . . . . . . . . . . . . . . //
        // . SET MASTER ATTRIBUTE  . . . . . . . . . . . . //
        // . . . . . . . . . . . . . . . . . . . . . . . . //
        
        this->vitality = RNG::get_distributed ( 50, 20 );
        
        // . . . . . . . . . . . . . . . . . . . . . . . . //
        // . DISTRIBUTE TO SLAVE ATTRIBUTES  . . . . . . . //
        // . . . . . . . . . . . . . . . . . . . . . . . . //
        
        // TODO: FIX THIS SHIT FOR SIZE & SENSE !!!
        int mean               = ( this->vitality < 5 ) ? this->vitality : this->vitality * 0.1;
        int standard_deviation = ( this->vitality < 2 ) ? this->vitality : this->vitality * 0.2;
        
        this->size = RNG::get_distributed ( mean, standard_deviation );
        
        do
            this->sense = RNG::get_distributed ( mean, standard_deviation );
        while ( this->sense < this->size );
        
        this->health           = RNG::get_distributed ( mean, standard_deviation );
        this->walk_speed       = RNG::get_distributed ( mean, standard_deviation );
        this->walk_distance    = RNG::get_distributed ( mean, standard_deviation );
        this->stamina          = RNG::get_distributed ( mean, standard_deviation );
        this->stamina_refactor = RNG::get_distributed ( mean, standard_deviation );
    }
    
    ~ATTRIBUTES ( ) { };
};

#endif /* attributes_hpp */

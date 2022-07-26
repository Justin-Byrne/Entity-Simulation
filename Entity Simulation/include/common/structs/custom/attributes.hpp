// @File:       attributes.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:30 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef attributes_hpp
#define attributes_hpp

#include "../../../utilities/general/RNG.hpp"
#include "../../../utilities/general/scale.hpp"

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
        this->vitality = RNG::get_distributed ( this->_mean, this->_stddev );

        this->_scale ( );
    }
    
    ~ATTRIBUTES ( ) { };
    
private:

    int _mean   = 50;
    int _stddev = 20;
    
    void _scale ( )
    {
        this->size             = scale_to ( this->vitality, SIZE_CAP             );
        this->sense            = scale_to ( this->vitality, SENSE_CAP            );
        this->health           = scale_to ( this->vitality, HEALTH_CAP           );
        this->walk_speed       = scale_to ( this->vitality, WALK_SPEED_CAP       );
        this->walk_distance    = scale_to ( this->vitality, WALK_DISTANCE_CAP    );
        this->stamina          = scale_to ( this->vitality, STAMINA_CAP          );
        this->stamina_refactor = scale_to ( this->vitality, STAMINA_REFACTOR_CAP );
    }
};

#endif /* attributes_hpp */

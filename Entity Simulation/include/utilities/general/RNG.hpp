// @File:       rng.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:31 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef rng_hpp
#define rng_hpp

namespace RNG
{
    // Random ............................................................... //

    int get_random ( int upper )
    {
        return ( std::rand ( ) % ( upper + 1 ) );
    }

    int get_random ( int lower, int upper )
    {
        return ( std::rand ( ) % ( upper - lower + 1 ) ) + lower;
    }

    // Distributed .......................................................... //

    int get_distributed ( int mean, int standard_deviation )
    {
        int result = 0;
        
        std::random_device               random_device;
        std::default_random_engine       random_engine ( random_device ( ) );
        std::normal_distribution<double> distribution  ( mean, standard_deviation );
        
        do
            result = (int) std::round ( distribution ( random_engine ) );
        while ( result < 1 );
        
        return result;
    }
}

#endif /* rng_hpp */

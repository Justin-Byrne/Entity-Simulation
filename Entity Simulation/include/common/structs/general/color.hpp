// @File:       color.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 7/13/22 at 8:54 AM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef color_hpp
#define color_hpp

#include "../../static/colors.hpp"

struct COLOR
{
    sf::Color one         = colors::null;
    sf::Color two         = colors::null;
    
    sf::Color stroke      = colors::null;
    sf::Color fill        = colors::null;
    
    sf::Color origin      = colors::null;
    sf::Color destination = colors::null;
    
    // Constructors ......................................................... //
    
    COLOR ( sf::Color one, sf::Color two )
    {
        this->one    = one;
        this->stroke = one;
        this->origin = one;
        
        this->two         = two;
        this->fill        = two;
        this->destination = two;
    }
    
    COLOR ( )  { }
    
    ~COLOR ( ) { }
};

#endif /* color_hpp */

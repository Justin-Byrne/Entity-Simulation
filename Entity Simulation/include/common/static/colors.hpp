// @File: 		colors.hpp
// @Project: 	Entity Simulation
// @Author:		Justin Byrne
// @Date:		Created 6/23/22 at 1:13 PM
// @Copyright:	Copyright (c) 2022 Byrne-Systems

#ifndef colors_hpp
#define colors_hpp

#include <SFML/Graphics/Color.hpp>

namespace colors
{
    sf::Color white          = { 255, 255, 255 };
    sf::Color yellow_sun     = { 237, 235,   0 };
    sf::Color green_apple    = { 146, 195,   0 };
    sf::Color blue_ice       = {  28,  50, 251 };
    sf::Color blue_bright    = {   0, 248, 250 };
    sf::Color blue_baby      = {  84, 212, 255 };
    sf::Color red            = { 255,   0,  10 };
    sf::Color red_apple      = { 153,  55,  55 };
    sf::Color gray_brilliant = {  84,  84,  84 };
    sf::Color gray_faded     = { 100, 100, 100 };
    sf::Color gray_charcoal  = {  54,  56,  62 };
    sf::Color black          = {   0,   0,   0 };

    sf::Color transparent    = sf::Color::Transparent;
    sf::Color null           = sf::Color::Transparent;
}

#endif /* colors_hpp */

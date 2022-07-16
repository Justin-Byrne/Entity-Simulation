// @File:       config.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 11:07 AM
// @Copyright:	Copyright (c) 2022 Byrne-Systems

#ifndef config_hpp
#define config_hpp

// GLOBAL CONSTS ............................................................ //

// DEBUG
#define DEBUG_ROTATE                   0
#define DEBUG_BODY                     0
#define DEBUG_SENSE                    0
#define DEBUG_SIGHTLINE                1
#define DEBUG_STEPS                    0
#define DEBUG_UNIFORM_GRID             1

// PROGRAM
#define WINDOW_TITLE "Entity Simulation"
#define WINDOW_WIDTH                 800
#define WINDOW_HEIGHT                800
#define ENTITY_MAX                   500
#define STEP_MAX                      25
#define LINE_SEGMENTS                  5
#define FRAME_RATE                    30
#define CELL_SIZE                     20

#define NULL_COLOR 			colors::null

#endif /* config_hpp */

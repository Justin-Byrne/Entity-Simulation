// @File:       headers.hpp
// @Project:    Entity Simulation
// @Author:     Justin Byrne
// @Date:       Created 6/23/22 at 1:43 PM
// @Copyright:  Copyright (c) 2022 Byrne-Systems

#ifndef headers_hpp
#define headers_hpp

// HEADERS .................................................................. //

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . CONFIG . . . . . . . . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "config.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . MATH . . . . . . . . . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "common/math/math.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . STRUCTS (CUSTOM) . . . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "common/structs/custom/attributes.hpp"
#include "common/structs/custom/entity.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . STRUCTS (GENERAL)  . . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "common/structs/general/angle.hpp"
#include "common/structs/general/point.hpp"
#include "common/structs/general/color.hpp"
#include "common/structs/general/cell.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . STATIC  . . . . . . . . . . . . . . . . . . . //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "common/static/colors.hpp"
#include "common/static/states.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . UTILITIES (GENERAL)  . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "utilities/general/RNG.hpp"
#include "utilities/general/display.hpp"
#include "utilities/general/uniform_grid.hpp"
#include "utilities/general/scale.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . UTILITIES (RENDERER)   . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "utilities/renderer/SFML_utilities.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . UTILITIES (SPECIFIC)   . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "utilities/specific/step_colors.hpp"

// . . . . . . . . . . . . . . . . . . . . . . . . //
// . SIMULATION . . . . . . . . . . . . . . . . .  //
// . . . . . . . . . . . . . . . . . . . . . . . . //

#include "simulation/simulation.hpp"

#endif /* headers_hpp */

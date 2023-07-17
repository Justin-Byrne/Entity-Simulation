# Entity Simulation

![issues](https://img.shields.io/github/issues/Justin-Byrne/Entity-Simulation)
![forks](https://img.shields.io/github/forks/Justin-Byrne/Entity-Simulation)
![stars](https://img.shields.io/github/stars/Justin-Byrne/Entity-Simulation)
![license](https://img.shields.io/github/license/Justin-Byrne/Entity-Simulation)
<img src="https://img.shields.io/badge/SFML-2.5.1-yellow" />

Entity simulator for simulated experiments

## Table of Contents
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
  - [Linux/Mac](#linux/mac)
  - [Windows](#windows)
- [Configuration](#configuration)
- [Examples](#examples)
  - [Body](#body)
  - [Rotate](#rotate)
  - [Sense](#sense)
  - [Sightline](#sightline)
  - [Steps](#steps)
  - [Uniform Grid](#uniform-grid)
  - [Body & Steps](#body-&-steps)
  - [Body, Steps, and Sense](#body,-steps,-and-sense)
- [Support](#support)
- [Structure](#structure)
- [Copyright](#copyright)

## Requirements

| Program | Function | Required | Download |
| :---: | :--- | :---: | :---: |
| SFML | Media Rendering Library | :white_check_mark: | [:floppy_disk:](https://www.sfml-dev.org/download.php) |

## Installation

Migrate to your desired download location on your local machine using (either) your console or terminal, and download this repository to your system using git clone:

```sh
git clone https://github.com/Justin-Byrne/Entity-Simulation.git
```

Compile project, under `(root)/Entity Simulation/`

```sh
> make
> make clean
```

## Usage

### Linux/Mac

```sh
> ./Entity-Simulation
```

### Windows

```sh
> Entity-Simulation
```

## Configuration

You can toggle and augment various configuration options under `config.hpp`


```c++
// DEBUG
#define DEBUG_ROTATE                   0
#define DEBUG_BODY                     1
#define DEBUG_SENSE                    0
#define DEBUG_SIGHTLINE                0
#define DEBUG_STEPS                    1
#define DEBUG_UNIFORM_GRID             0
#define DEBUG_ENTITY_PRINT_ATTRIBUTES  0

// ENTITY ATTRIBUTE CAPS
#define SIZE_CAP                      10    // 10
#define SENSE_CAP                     40    // 40
#define HEALTH_CAP                    20    // 20
#define WALK_SPEED_CAP                20    // 20
#define WALK_DISTANCE_CAP             70    // 70
#define STAMINA_CAP                   20    // 20
#define STAMINA_REFACTOR_CAP          10    // 10

// PROGRAM
#define WINDOW_TITLE "Entity Simulation"
#define WINDOW_WIDTH                 800
#define WINDOW_HEIGHT                800
#define ENTITY_MAX                   200
#define STEP_MAX                      25
#define SEEN_MAX     ( ENTITY_MAX / 25 )
#define LINE_SEGMENTS                  5
#define FRAME_RATE                    30
#define CELL_SIZE                     50

#define NULL_COLOR          colors::null

```

## Examples

### Body

![Body](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/body.gif)

### Rotate

![Rotate](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/rotate.gif)

### Sense

![Sense](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/sense.gif)

### Sightline

![Sightline](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/sighline.gif)

### Steps

![Steps](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/steps.gif)

### Uniform Grid

![Uniform Grid](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/uniform_grid.gif)

### Body & Steps

![Body & Steps](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/body_n_steps.gif)

### Body, Steps, and Sense

![Body, Steps, and Sense](https://github.com/Justin-Byrne/Entity-Simulation/blob/main/images/body_n_steps_n_sense.gif)

## Support

Please [open an issue](https://github.com/Justin-Byrne/Entity-Simulation/issues/new) for support.

## Structure

    . (root)
    │
    │
    ├── Entity Simulation
    │   │
    │   ├── include/
    │   │   │
    │   │   ├── common/
    │   │   │   │
    │   │   │   ├── math/
    │   │   │   │   │
    │   │   │   │   └── math.hpp
    │   │   │   │
    │   │   │   ├── static/
    │   │   │   │   │
    │   │   │   │   ├── colors.hpp
    │   │   │   │   │
    │   │   │   │   └── states.hpp
    │   │   │   │
    │   │   │   └── structs/
    │   │   │       │
    │   │   │       ├── custom/
    │   │   │       │   │
    │   │   │       │   ├── attributes.hpp
    │   │   │       │   │
    │   │   │       │   └── entity.hpp
    │   │   │       │
    │   │   │       └── general/
    │   │   │           │
    │   │   │           ├── angle.hpp
    │   │   │           │
    │   │   │           ├── cell.hpp
    │   │   │           │
    │   │   │           ├── color.hpp
    │   │   │           │
    │   │   │           ├── matrix.hpp
    │   │   │           │
    │   │   │           └── point.hpp
    │   │   │
    │   │   ├── simulation/
    │   │   │   │
    │   │   │   └── simulation.hpp
    │   │   │
    │   │   ├── utilities/
    │   │   │   │
    │   │   │   ├── general/
    │   │   │   │   │
    │   │   │   │   ├── display.hpp
    │   │   │   │   │
    │   │   │   │   ├── RNG.hpp
    │   │   │   │   │
    │   │   │   │   ├── scale.hpp
    │   │   │   │   │
    │   │   │   │   └── uniform_grid.hpp
    │   │   │   │
    │   │   │   ├── renderer/
    │   │   │   │   │
    │   │   │   │   └── SFML_utilities.hpp
    │   │   │   │
    │   │   │   └── specific/
    │   │   │       │
    │   │   │       └── step_colors.hpp
    │   │   │
    │   │   ├── config.hpp
    │   │   │
    │   │   └── headers.hpp
    │   │
    │   ├── libs/
    │   │   │
    │   │   └── SFML/     (SFML Raw Header Files)
    │   │
    │   ├── main.cpp
    │   └── Makefile
    │
    ├── images/           (Media files...)
    │
    ├── LICENSE
    └── README.md


## Copyright

![Byrne-Systems](http://byrne-systems.com/content/static/cube_sm.png)

== Byrne-Systems © 2022 - All rights reserved. ==

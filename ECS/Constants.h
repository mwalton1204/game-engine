#pragma once

#include <bitset>

using Entity = int; // Defines an entity as a 32-bit integer
const Entity MAX_ENTITIES = 5000;

using Component = int; // Defines a component as an 8-bit integer
const Component MAX_COMPONENTS = 50;

using ComponentTracker = std::bitset<MAX_COMPONENTS>; // Defines ComponentTracker as a bitset that will store whether or not an entity has each component
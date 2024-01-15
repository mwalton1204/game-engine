#pragma once

#include <bitset>
#include <any>

using Entity = int; // Define an entity as a 32-bit integer
const Entity MAX_ENTITIES = 5000;

using Component = int; // Define a component as an 8-bit integer
const Component MAX_COMPONENTS = 50;

using ComponentTracker = std::bitset<MAX_COMPONENTS>; // Define ComponentTracker as a bitset

using ComponentType = std::any; // Define Component Type as any type
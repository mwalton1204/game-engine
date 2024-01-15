#pragma once

#include <cstdint>
#include <bitset>

using Entity = std::uint32_t; // Defines an entity as a 32-bit integer
const Entity MAX_ENTITIES = 5000;

using Component = std::uint8_t; // Defines a component as an 8-bit integer
const Component MAX_COMPONENTS = 50;
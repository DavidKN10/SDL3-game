export module ComponentsAndEntities;

import <SDL3/SDL.h>;
import std;

// components

// entities
class Entity {
private:
	std::string m_tag;
public:
	Entity(std::string givenString) : m_tag(givenString) {};
};

class EntityManager {

};

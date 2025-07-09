export module ComponentsAndEntities;

import <SDL3/SDL.h>;
import std;

// components
struct Location {
	float x;
	float y;
};

struct Velocity {
	int x;
	int y;
};

struct Playable {
	bool isPlayable;
};

struct Damagable {
	bool isDamagable;
};

struct RenderBox {
	SDL_Rect size;
};

struct CollisionBox {
	SDL_Rect size;
};

// entities
class Entity {
private:
	const int m_id = 0;
	std::string m_tag = "default";
	bool isAlive = true;
public:
	Entity(const std::string& tagName, const int id) : m_tag{ tagName }, m_id(id) {};
	std::shared_ptr<Location> location;
	std::shared_ptr<Velocity> velocity;
	std::shared_ptr<SDL_Texture> texture;
	std::shared_ptr<Playable> playable;
	std::shared_ptr<Damagable> damagable;
	std::shared_ptr<RenderBox> renderBox;
	std::shared_ptr<CollisionBox> collisionBox;
};

class EntityManager {

};

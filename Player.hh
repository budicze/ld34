#ifndef PLAYER_HH
#define PLAYER_HH

#include "Renderer.hh"
#include "Listeners.hh"
#include "Texture.hh"

class Player : public Listener {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y;
		int xv, yv;
	public:
		Player(Renderer* r);
		~Player(){}
		void event(SDL_Event *e);
		void update();
		void render();

};

#endif

#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>
#include <map>

class Renderer {
private:
	static bool initialized;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool ok;
	int height, width;
	int xoff = 0, yoff = 0;
	std::map<std::string, SDL_Texture*> availableTextures;

public:
enum Align {RIGHT, LEFT};
	Renderer(int width, int height, const char *windowName);

	Renderer(const Renderer&) = delete;

	Renderer& operator=(const Renderer&) = delete;
	~Renderer();
	void update();
	void clear();
	void renderRect(int x, int y, int w, int h, SDL_Color col);
	void changeSize(int w, int h){width = w; height = h;}

	bool isOk(){return ok;}
	operator SDL_Renderer*() const {return renderer;}
	int getHeight(){return height;}
	int getWidth(){return width;}
	void setOffset(int xoff_, int yoff_){xoff = xoff_; yoff = yoff_;}
	int getXOffset(){return xoff;}
	int getYOffset(){return yoff;}
	SDL_Texture* getTexture(const char* name){return availableTextures[name];}
	void addTexture(const char* name, SDL_Texture* tex){availableTextures[name] = tex;}

	const SDL_Color cBlack = {0, 0, 0, 255};
	const SDL_Color cRed = {255, 0, 0, 255};
	const SDL_Color cGreen = {0, 255, 0, 255};
	const SDL_Color cBlue = {0, 0, 255, 255};
	const SDL_Color cLightblue = {0, 0, 63, 255};
	const SDL_Color cYellow = {255, 255, 0, 255};
};

#endif

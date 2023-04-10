#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_set>

class Object
{
	public:
		Object(SDL_Renderer* rend, std::string name, double x, double y, char* filename);
		~Object();
		void move(double dx, double dy);
		void moveTo(double dx, double dy);
		void moveARad(double angle, double magnitude);
		void moveADeg(double angle, double magnitude);
		void draw(SDL_Renderer* rend);
		void enableCollision();
		void disableCollision();
		bool hasCollision();
		bool collidesWith(Object obj);
		double getX();
		double getY();
		int getW();
		int getH();
		std::string getName();
		void setName(std::string newname);
		std::unordered_set<std::string> getTags();
		bool hasTag(std::string search);
		void addTag(std::string add);
		void removeTag(std::string rem);
		void setAlpha(uint8_t a);
	protected:
		double x,y;
		int w,h;
		bool collides;
		std::string name;
		std::unordered_set<std::string> tags;
		SDL_Texture* img;
		SDL_Rect rect;
};

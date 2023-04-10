#include "Object.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <unordered_set>

Object::Object(SDL_Renderer* rend, std::string name, double x, double y, char* filename){
	img = IMG_LoadTexture(rend, filename);
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(img, SDL_BLENDMODE_BLEND);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->collides = false;
	this->name = name;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Object::move(double dx, double dy){
	this->x += dx;
	this->y += dy;
	rect.x = this->x;
	rect.y = this->y;
}
void Object::moveTo(double dx, double dy){
	this->x = dx;
	this->y = dy;
	rect.x = this->x;
	rect.y = this->y;
}
void Object::moveARad(double angle, double magnitude){
	this->x += magnitude * cos(angle);
	this->y += magnitude * sin(angle);
	rect.x = this->x;
	rect.y = this->y;
}
void Object::moveADeg(double angle, double magnitude){
	angle = angle * M_PI/180;
	moveARad(angle, magnitude);
}
void Object::draw(SDL_Renderer* rend){
	SDL_RenderCopy(rend, img, NULL, &rect);	
}

void Object::enableCollision(){
	this->collides = true;
}
void Object::disableCollision(){
	this->collides = false;
}
bool Object::hasCollision(){
	return this->collides;
}
bool Object::collidesWith(Object obj){
	if(
		this->x < obj.x + obj.w &&
		this->x + this->h > obj.x &&
		this->y < obj.y + obj.h &&
		this->y + this->w > obj.y
		){
		return true;
	}
	return false;
}

double Object::getX(){
	return this->x;
}
double Object::getY(){
	return this->y;
}
int Object::getW(){
	return this->w;
}
int Object::getH(){
	return this->h;
}

std::string Object::getName(){
	return this->name;
}
void Object::setName(std::string newname){
	this->name = newname;
}

std::unordered_set<std::string> Object::getTags(){
	return tags;
}

bool Object::hasTag(std::string search){
	return tags.find(search) != tags.end();
}

void Object::addTag(std::string add){
	tags.insert(add);
}

void Object::removeTag(std::string rem){
	tags.erase(rem);
}
void Object::setAlpha(uint8_t a){
	SDL_SetTextureAlphaMod(img, a);
}
Object::~Object(){

}

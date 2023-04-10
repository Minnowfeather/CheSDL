// SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// C++ includes
#include <cstdlib>
#include <chrono>
#include <string>
#include <map>
#include <cmath>
#include <iostream>


// custom classes include
#include "Object.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

uint64_t currentTimeMilli()
{
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
uint64_t currentTimeNano()
{
	using namespace std::chrono;
	return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

void getAngleDeg(double dx, double dy, double& angle, double& magnitude);

int main(int argc, char *argv[])
{
	// returns zero on success else non-zero
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, 0);
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	// r g b a
	// SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
	SDL_RenderClear(rend);
	SDL_RenderPresent(rend);
	

	// set up time delta
	uint64_t delta = 0;
	uint64_t startTime = currentTimeNano();
	uint64_t elapsed = 0;
	uint64_t timeBefore, timeAfter;
	timeBefore = currentTimeNano();


	bool quit = false;


	while(!quit){
		// time upkeep
		timeBefore = currentTimeNano();
		delta += timeBefore - timeAfter;
		//std::cout << delta << std::endl;
		// handle events
		SDL_Event e;
		if(SDL_PollEvent(&e)){
			// handle quit
			if(e.type == SDL_QUIT)
				quit = true;
			else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_q)
				quit = true;
		}
		
		//draw
		SDL_RenderClear(rend);
		SDL_RenderPresent(rend);

		// time upkeep
		timeAfter = currentTimeNano();
		delta = timeAfter - timeBefore;
		elapsed = currentTimeNano() - startTime;
	}
	//SDL_DestroyTexture(myImg);
	SDL_DestroyRenderer(rend);
	SDL_Quit();
	return 0;
}

void getAngleDeg(double dx, double dy, double& angle, double& magnitude){
	if(dx == 0){
		if(dy == 1){
			angle = 90;
			magnitude = 1;
		}else if(dy == -1){
			angle = -90;
			magnitude = 1;
		}else
			angle = 0;
	}
	else if(dx == 1){
		if(dy == 1)
			angle = 45;
		else if(dy == -1)
			angle = -45;
		else
			angle = 0;
		magnitude = 1;
	}
	else if(dx == -1){
		if(dy == 1)
			angle = 135;
		else if(dy == -1)
			angle = -135;
		else
			angle = 180;
		magnitude = 1;
	}
}

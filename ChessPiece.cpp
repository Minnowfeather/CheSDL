#include "ChessPiece.h"
ChessPiece::ChessPiece(SDL_Renderer* rend, char type, int team, char* filename)
	: Object(rend,"chesspiece",0,0,filename)
{
	this->type = type;
	this->team = team;
	
}

ChessPiece::~ChessPiece()
{
}

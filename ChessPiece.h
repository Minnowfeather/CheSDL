#include "Object.h"

class ChessPiece : public Object
{
	public:
		ChessPiece(SDL_Renderer* rend, char type, int team, char* filename);
		~ChessPiece();
		char type;
		int team;
	private:
};

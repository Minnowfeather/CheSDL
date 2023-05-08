#pragma once
#include "ChessPiece.h"
#include <unordered_set>

class ChessBoard : public Object {
	public:
		ChessBoard(SDL_Renderer* rend);
		void movePiece(ChessPiece* src, ChessPiece* tgt);
		ChessPiece* getPiece(int x, int y);
		std::unordered_set<ChessPiece*> getValidMoves(ChessPiece* src);
		void flipSide();
		~ChessBoard();
	private:
		ChessPiece* board[8][8];
		void getIndex(ChessPiece* find, int& x, int& y);
};

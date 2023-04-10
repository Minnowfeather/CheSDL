#include "ChessBoard.h"
#include <unordered_set>

ChessBoard::ChessBoard()
	: Object(rend,"chessboard",0,0,"board.png"){

}

void movePiece(ChessPiece* src, ChessPiece* tgt){
	ChessPiece* tmp = src;
	src = tgt;
	tgt = tmp;
}

ChessPiece* getPiece(int x, int y){
	return board[x][y];
}

std::unordered_set<ChessPiece*> getValidMoves(ChessPiece* src){
	int x,y;
	getIndex(src,x,y);

	unordered_set<ChessPiece*> output;
	switch(src->type){
		case 'p': // pawn
			if(y < 7){
				ChessPiece* tmp = getPiece(x,y+1); // move forward
				if(tmp == nullptr){
					output.insert(tmp);
				}
				if(x < 7){ /// capture up right
					tmp = getPiece(x+1,y+1);
					if(tmp != nullptr && tmp->team != src->team){
						output.insert(tmp);
					}
					if(x > 0){ // capture up left
						tmp = getPiece(x-1,y+1);
						if(tmp != nullptr && tmp->team != src->team){
							output.insert(tmp);
						}
					} 
				} else if(x > 0){ // capture up left
					tmp = getPiece(x-1,y+1);
						if(tmp != nullptr && tmp->team != src->team){
							output.insert(tmp);
						}
				}

			}
			break;
		case 'r': // rook
			int i = x + 1;
			bool firstPieceFound = false;
			while(i < 8 && !firstPieceFound){ // viable moves to the right
				ChessPiece* tmp = getPiece(i,y);
				if(tmp == nullptr){
					output.insert(tmp);
				} else{
					if(tmp->team != src->team){
						output.insert(tmp);
					}
					firstPieceFound = true;
				}
				i++;
			}
			i = x - 1;
			firstPieceFound = false;
			while(i >= 0 && !firstPieceFound){ // viable moves to the left
				ChessPiece* tmp = getPiece(i,y);
				if(tmp == nullptr){
					output.insert(tmp);
				} else{
					if(tmp->team != src->team){
						output.insert(tmp);
					}
					firstPieceFound = true;
				}
				i--;
			}
			i = y + 1;
			firstPieceFound = false;
			while(i < 8 && !firstPieceFound){ // viable moves up
				ChessPiece* tmp = getPiece(x,i);
				if(tmp == nullptr){
					output.insert(tmp);
				} else{
					if(tmp->team != src->team){
						output.insert(tmp);
					}
					firstPieceFound = true;
				}
				i++;
			}
			i = y - 1;
			firstPieceFound = false;
			while(i >= 0 && !firstPieceFound){ // viable moves down
				ChessPiece* tmp = getPiece(x,i);
				if(tmp == nullptr){
					output.insert(tmp);
				} else{
					if(tmp->team != src->team){
						output.insert(tmp);
					}
					firstPieceFound = true;
				}
				i--;
			}
			break;
		case 'k': // king
			for(int i = x-1; i <= x+1; i++){
				for(int j = y-1; j <= y+1; j++){ // 3x3 square
					if(
						i >= 8 || y >= 8 ||
						i < 0 || y < 0 ||
						i = x || j = y
					  ) {
						// dont add if OOB or the king itself
					} else {
						output.insert(getPiece(i,j));
					}
				}
			}
			break;
		case 'n': // knight
			if(
			break;
		case 'q': // queen
			break;
		case 'b': // bishop
			break;

	}
}

ChessBoard::~ChessBoard()
{

}

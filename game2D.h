#pragma once
#include<string>
#include"player.h"
using std::string;
using namespace playerNS;

namespace game2DNS{

	class game2D {
	private:
		player pl1;
		player pl2;
		piece** square;
		int length;
	public:
		//constructor 
		game2D(player&, player&, const int& = 3);

		//set and get
		void setPlayer1(const player&);
		void setPlayer2(const player&);

		player getPlayer1() const { return pl1; }
		player getPlayer2() const { return pl2; }

		//utility functions
		void movePiece(const int&, const int&, const player&);
		void check(player&,player&);   //checking status
		void drawSquare();
	};

}

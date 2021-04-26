#pragma once
#include<string>
#include"player.h"
using std::string;
using namespace playerNS;

namespace game3DNS {

	class game3D {
	private:
		static const int dim = 3;
		player pl1;
		player pl2;
		piece square[dim][dim][dim];  //3x3x3 cube for 3D game
	public:
		//constructor 
		game3D(player&, player&);

		//set and get
		void setPlayer1(const player&);
		void setPlayer2(const player&);

		player getPlayer1() const { return pl1; }
		player getPlayer2() const { return pl2; }

		//utility functions
		void movePiece3D(const int&, const int&, const int&, const player&);
		void check3D(player&, player&);   //checking status
		void drawSquare3D();
	};

}

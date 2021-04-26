#include"game3D.h"

using namespace game3DNS;

game3D::game3D(player& pl1, player& pl2)
	:pl1(pl1), pl2(pl2) {

	//setting game status
	this->pl1.setStatus(Status::game);
	this->pl2.setStatus(Status::game);

	//init the square
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			for (int k = 0; k < dim; k++) {
				square[i][j][k] = piece::no;
			}
		}
	}
}

void game3D::setPlayer1(const player& pl1) {
	this->pl1 = pl1;
}

void game3D::setPlayer2(const player& pl2) {
	this->pl2 = pl2;
}

void game3D::movePiece3D(const int& row, const int& colon, const int& height, const player& pl) {
	if (pl.getStatus() == Status::lose)
		cout << "you lose" << endl;
	else if (pl.getStatus() == Status::game && row < dim && colon < dim && height < dim ) {
		if (square[row][colon][height] == piece::no)
			square[row][colon][height] = pl.getPiece();
		else throw "invalid position";
	}
	else if (row >= dim || colon >= dim || height >= dim ) {
		throw "out of range";
	}
}

void game3D::check3D(player& a, player& b) {

	/*

	 _ _ _ _  <\ y axis
	|\ _ _ _\ 
	| |     | ^   z axis
	| |     | |
     \|_ _ _|
	    ->
		x axis
	    
	*/

	//checking z axis colon
	bool tmp = true;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			for (int k = 0; k < dim; k++) {
				if (square[i][j][k] == a.getPiece())
					tmp = tmp && true;
				else tmp = false;
			}if (tmp == true) {
				a.setStatus(Status::win);
				b.setStatus(Status::lose);
		    }
			else tmp = true;
		}
	}

	//checking row along y axis for every z plane   
	for (int i = 0; i < dim ; i++) {
		for (int k = 0; k < dim; k++) {
			for (int j = 0; j < dim; j++) {
				if (square[i][j][k] == a.getPiece())
					tmp = tmp && true;
				else tmp = false;
			}if (tmp == true) {
				a.setStatus(Status::win);
				b.setStatus(Status::lose);
			}
			else tmp = true;
		}
	}

	//checking colon along x axis for every z plane
	for (int j = 0; j < dim; j++) {
		for (int k = 0; k < dim; k++) {
			for (int i = 0; i < dim; i++) {
				if (square[i][j][k] == a.getPiece())
					tmp = tmp && true;
				else tmp = false;
			}if (tmp == true) {
				a.setStatus(Status::win);
				b.setStatus(Status::lose);
			}
			else tmp = true;
		}
	}

	//checking diagonal 1 for x y plane for every z 
	for (int i = 0, j = 0; i < dim; i++, j++) {
		for (int k = 0; k < dim; k++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 2 for x y plane for every z 
	for (int i = 0, j = dim-1; i < dim; i++, j--) {
		for (int k = 0; k < dim; k++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 1 for y z plane for every x
	for (int j = 0, k = 0; j < dim; j++, k++) {
		for (int i = 0; i < dim; i++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 2 for y z plane for every x
	for (int j = 0, k = dim-1; j < dim; j++, k--) {
		for (int i = 0; i < dim; i++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 1 for x z plane for every y
	for (int i = 0, k = 0; i < dim; i++, k++) {
		for (int j = 0; j < dim; j++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 2 for x z plane for every y
	for (int i = 0, k = dim - 1; i < dim; i++, k--) {
		for (int j = 0; j < dim; j++) {
			if (square[i][j][k] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 1 of cube
	for (int i = 0, j = 0, k = 0; i < dim; i++, j++, k++) {
		if (square[i][j][k] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	//checking diagonal 2 of cube
	for (int i = 0, j = dim, k = dim; i < dim; i++, j--, k--) {
		if (square[i][j][k] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	//checking tie
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			for (int k = 0; k < dim; k++) {
				if (square[i][j][k] == piece::o || square[i][j][k] == piece::x)
					tmp = tmp && true;
				else tmp = false;
			}
		}
	}if (tmp == true) {
		a.setStatus(Status::tie);
		b.setStatus(Status::tie);
	}

}

void game3D::drawSquare3D() {
	cout << "r";
	for (int i = 0; i < dim; i++)
		cout << "   " << i ;
	cout << endl<<endl;
	for (int k = 0; k < dim; k++) {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (i == 0 && j == 0)
					cout << "h "<<k ;
				if (i == 1 && j == 0)
					cout << "     ";
				if (i == 2 && j==0)
					cout << "       ";
				switch (square[i][j][k]) {
				case piece::no:
					if(j!=2)
					cout << "  *  -";
					else
						cout << "  *   ";
					break;
				case piece::o:
					if (j != 2)
					cout << "  o  -";
					else
						cout << "  o   ";
					break;
				case piece::x:
					if(j != 2)
					cout << "  x  -";
					else
						cout << "  x   ";
					break;
				}
				if (j == 2)
					cout << "   c " << i ;
			}cout << endl;
		}
	}
}
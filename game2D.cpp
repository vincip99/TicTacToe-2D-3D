#include"game2D.h"

using namespace game2DNS;

game2D::game2D(player& pl1, player& pl2, const int& length)
	:pl1(pl1), pl2(pl2), length(length) {
	
	//setting game status
	this->pl1.setStatus(Status::game); 
	this->pl2.setStatus(Status::game);

	//creating the dynamic square
	square = new piece * [length];
	for (int i = 0; i < length; i++) {
		square[i] = new piece[length];
	}

	//init the square
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			square[i][j] = piece::no;
		}
	}
}

void game2D::setPlayer1(const player& pl1) {
	this->pl1 = pl1;
}

void game2D::setPlayer2(const player& pl2) {
	this->pl2 = pl2;
}

void game2D::movePiece(const int& row, const int& colon, const player& pl) {
	if (pl.getStatus() == Status::lose)
		cout << "you lose"<<endl;
	else if (pl.getStatus() == Status::game && row<length && colon<length) {
		if (square[row][colon] == piece::no)
			square[row][colon] = pl.getPiece();
		else throw "invalid position";
	}
	else if (row >= length || colon >= length) {
		throw "out of range";
	}
}

void game2D::check(player& a,player& b) {
	int tlength = 0;
	if (length == 3)
		tlength = length;
	else tlength = length - 1;  //in case the square is bigger than 3x3

	//checking row
	bool tmp = true;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < tlength; j++) {
			if (square[i][j] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	for (int i = 0; i < length; i++) {
		for (int j = length-1; j >=length-tlength; j--) {
			if (square[i][j] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking colon
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < tlength; i++) {
			if (square[i][j] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	for (int j = 0; j < length; j++) {
		for (int i = length-1; i >= length-tlength; i--) {
			if (square[i][j] == a.getPiece())
				tmp = tmp && true;
			else tmp = false;
		}if (tmp == true) {
			a.setStatus(Status::win);
			b.setStatus(Status::lose);
		}
		else tmp = true;
	}

	//checking diagonal 1
	for (int i = 0, j = 0; i < tlength; i++,j++) {
		if (square[i][j] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	for (int i = length-1, j = length-1; i >= length-tlength; i--, j--) {
		if (square[i][j] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	//checking diagonal 2
	for (int i = 0, j = length-1; i < length; i++, j--) {
		if (square[i][j] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	for (int i = length-1, j = 0; i >= length-tlength; i--, j++) {
		if (square[i][j] == a.getPiece())
			tmp = tmp && true;
		else tmp = false;
	}if (tmp == true) {
		a.setStatus(Status::win);
		b.setStatus(Status::lose);
	}
	else tmp = true;

	//checking tie
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (square[i][j] == piece::o || square[i][j] == piece::x)
				tmp = tmp && true;
			else tmp = false;
		}
	}if (tmp == true) {
		a.setStatus(Status::tie);
		b.setStatus(Status::tie);
	}

}

void game2D::drawSquare() {
	cout << " ";
	for (int i = 0; i < length; i++)
		cout << " " << i << " ";
	cout << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (j == 0)
				cout << i;
			switch (square[i][j]) {
			case piece::no:
				cout << "   ";
				break;
			case piece::o:
				cout << " o ";
				break;
			case piece::x:
				cout << " x ";
				break;
			}
		}cout << endl;
	}
}







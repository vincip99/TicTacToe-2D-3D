#include"player.h"

using namespace playerNS;

player::player(const string& name, const piece& type)
	:name(name) , type(type) {
	status = Status::game;  //the status game indicate the fact that the player can play
}

void player::setName(const string& name) {
	this->name = name;
}

void player::setPiece(const piece& type) {
	this->type = type;
}

void player::setStatus(const Status& status) {
	this->status = status;
}

void player::printPlayer() const {
	cout << "name: " << name << " color: ";
	switch (type) {
	case piece::no:
		cout << "no type";
		break;
	case piece::o :
		cout << "o";
		break;
	case piece::x:
		cout << "x";
		break;
	}
	cout << " status: ";
	switch (status) {
	case Status::game:
		cout << "in game";
		break;
	case Status::win:
		cout << "you win";
		break;
	case Status::lose:
		cout << "you lose";
		break;
	case Status::tie:
		cout << "tie";
		break;
	}
	cout << endl;
}
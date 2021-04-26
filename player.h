#pragma once
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

namespace playerNS {

	enum class piece{ x, o, no };

	enum class Status{win,lose,game,tie};

	class player {
	private:
		string name;
		piece type;
		Status status;
	public:
		//constructor with 2 parameters
		explicit player(const string& ="", const piece& =piece::no);

		//set and get
		void setName(const string&);
		void setPiece(const piece&);
		void setStatus(const Status&);

		string getName() const { return name; }
		piece getPiece() const { return type; }
		Status getStatus() const { return status; }

		//utility functions
		void printPlayer() const;
	};
}
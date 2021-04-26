// TicTacToe.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include<conio.h>
#include"game2D.h"
#include"game3D.h"
#include"player.h"
using namespace game2DNS;
using namespace game3DNS;
using namespace playerNS;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void instruction(player&, player&, int&);

void instruction3D(player&, player&);

void clearScreen();  //cross platform clear but slow

int main()
{
    in:

    player pl1;
    player pl2;
    int lenght=0, r, c, h, t;

    //select 2D or 3D
    cout << "select 2D or 3D (1 -> 2D  2-> 3D): ";
    cin >> t;
    if (t == 1) {

        //print game instruction
        instruction(pl1, pl2, lenght);

        game2D gg(pl1, pl2, lenght);

        pl1.printPlayer();
        pl2.printPlayer();

        cout << "press any key to continue" << endl;

        char ch = _getch();

        if (ch) {
            system("cls");
        }

        //game loop
        do {

        l1:

            gg.drawSquare();

            cout << "player 1 turn:" << endl;
            cout << "insert row: ";
            cin >> r;
            cout << "insert colon: ";
            cin >> c;

            //pl1 move
            try {
                gg.movePiece(r, c, pl1);
            }
            catch (const char* mess) {
                cerr << mess << endl;
                goto l1;
            }

            gg.check(pl1, pl2);

        l2:

            system("cls");  //not a closs-platform solution 
            gg.drawSquare();

            //pl2 move if is allowed (no tie and no lose)
            if (pl2.getStatus() != Status::lose && pl1.getStatus()!=Status::tie) {
                cout << "player 2 turn:" << endl;
                cout << "insert row: ";
                cin >> r;
                cout << "insert colon: ";
                cin >> c;

                try {
                    gg.movePiece(r, c, pl2);
                }
                catch (const char* mess) {
                    cerr << mess << endl;
                    goto l2;
                }

                gg.check(pl2, pl1);
            }

            system("cls");

        } while (pl1.getStatus() != Status::win && pl2.getStatus() != Status::win && pl1.getStatus()!= Status::tie);

        //print result
        pl1.printPlayer();
        pl2.printPlayer();

        int choice2;
        cout << "do you want to play again (1 yes and 2 no):" << endl;
        cin >> choice2;
        switch (choice2) {
        case 1:
            goto in;
            break;
        case 2:
            cout << "bye" << endl;
            break;
        }

    }if (t == 2) {

        //print game instruction
        instruction3D(pl1, pl2);

        game3D gg3D(pl1, pl2);

        pl1.printPlayer();
        pl2.printPlayer();

        cout << "press any key to continue" << endl;

        char ch = _getch();

        if (ch) {
            system("cls");
        }

        //game loop
        do {

        l3:

            gg3D.drawSquare3D();

            cout << "player 1 turn:" << endl;
            cout << "insert row: ";
            cin >> r;
            cout << "insert colon: ";
            cin >> c;
            cout << "insert height:";
            cin >> h;

            //pl1 move
            try {
                gg3D.movePiece3D(r, c, h,pl1);
            }
            catch (const char* mess) {
                cerr << mess << endl;
                goto l3;
            }

            gg3D.check3D(pl1, pl2);

        l4:

            system("cls");  //not a closs-platform solution 
            gg3D.drawSquare3D();

            //pl2 move
            if (pl2.getStatus() != Status::lose && pl1.getStatus() != Status::tie) {
                cout << "player 2 turn:" << endl;
                cout << "insert row: ";
                cin >> r;
                cout << "insert colon: ";
                cin >> c;
                cout << "insert height:";
                cin >> h;

                try {
                    gg3D.movePiece3D(r, c, h, pl2);
                }
                catch (const char* mess) {
                    cerr << mess << endl;
                    goto l4;
                }

                gg3D.check3D(pl2, pl1);
            }

            system("cls");
        } while (pl1.getStatus() != Status::win && pl2.getStatus() != Status::win && pl1.getStatus() != Status::tie);

        //print result
        pl1.printPlayer();
        pl2.printPlayer();

        int choice2;
        cout << "do you want to play again (1 yes and 2 no):" << endl;
        cin >> choice2;
        switch (choice2) {
        case 1:
            goto in;
            break;
        case 2:
            cout << "bye" << endl;
            break;
        }

    }

}

void instruction(player& pl1,player& pl2,int& lenght) {
    cout << "Tic Tac Toe game" << endl;
    cout << "game piece are o and x" << endl;
    cout << "you can use the length square that you prefer" << endl;
    cout << "classic Tic Tac Toe with 3 square you have to place 3 consecutive piece to win" << endl;
    cout << "for bigger lenght you need to place lenght-1 consecutive piece" << endl;
    cout << "try with: 3x3 5x5 or 7x7 for a better expirience" << endl;
    cout << "press any key to continue" << endl;
    char ch=_getch();

    if (ch) {
        system("cls");
    }

    string buff; int choice1;

    cout << "insert name of player 1:" << endl;
    cin >> buff;
    pl1.setName(buff);
    cout << "select the piece of player 1 (1 for x, 2 for o):" << endl;
    cin >> choice1;
    switch (choice1) {
    case 1:
        pl1.setPiece(piece::x);
        break;
    case 2:
        pl2.setPiece(piece::o);
        break;
    }
    buff.clear();

    cout << "insert name of player 2:" << endl;
    cin >> buff;
    pl2.setName(buff);
    switch (choice1) {
    case 1:
        pl2.setPiece(piece::o);
        break;
    case 2:
        pl2.setPiece(piece::x);
        break;
    }

    cout << "select the dimension of square: " << endl;
    cin >> lenght;

}

void instruction3D(player& pl1, player& pl2) {

    cout << "Tic Tac Toe game in 3D" << endl;
    cout << "game piece are o and x" << endl;
    cout << "Tic Tac Toe with 3x3x3 cube you have to place 3 consecutive piece in any direction to win" << endl;
    cout << "press any key to continue" << endl;
    char ch = _getch();

    if (ch) {
        system("cls");
    }

    string buff; int choice1;

    cout << "insert name of player 1:" << endl;
    cin >> buff;
    pl1.setName(buff);
    cout << "select the piece of player 1 (1 for x, 2 for o):" << endl;
    cin >> choice1;
    switch (choice1) {
    case 1:
        pl1.setPiece(piece::x);
        break;
    case 2:
        pl2.setPiece(piece::o);
        break;
    }
    buff.clear();

    cout << "insert name of player 2:" << endl;
    cin >> buff;
    pl2.setName(buff);
    switch (choice1) {
    case 1:
        pl2.setPiece(piece::o);
        break;
    case 2:
        pl2.setPiece(piece::x);
        break;
    }
}

void clearScreen()  //cross platform clear but slow
{
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

// 
//



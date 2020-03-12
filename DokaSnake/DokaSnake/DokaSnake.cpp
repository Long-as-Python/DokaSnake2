#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <thread>

using namespace std;

void SetXY(short x, short y)
{
	COORD coord = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int X = 5, Y = 10;
const int HEIGHT = 11;
const int WIDTH = 21;
int map[HEIGHT][WIDTH]; //0 - empty, 1 - wall, 2 - food
enum Moves { UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75, Enter = 13 };

class Map {
public:

	void CharPlacer() {
		cout << "#";
	}

	void MapBuilder() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				SetXY(i, j);
				if (map[i][j] == 1) {
					CharPlacer();
				}
			}
		}
	}

	void MapPreSet() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}
	}
private:
};


void HeroSummon(int x, int y) {
	SetXY(x, y);
	X = x;
	Y = y;
	cout << "@";
	Sleep(100);
}

void Erease(int x, int y) {
	SetXY(x, y);
	cout << " ";
}

int main()
{
	bool death = 0;
	Map Map;
	Map.MapPreSet();
	Map.MapBuilder();
	HeroSummon(X, Y);
	while (!death) {
		switch (_getch()) {
		case RIGHT:
			Erease(X, Y);
			HeroSummon(X, Y + 1);
			break;
		case UP:
			Erease(X, Y);
			HeroSummon(X - 1, Y);
			break;
		case LEFT:
			Erease(X, Y);
			HeroSummon(X, Y - 1);
			break;
		case DOWN:
			Erease(X, Y);
			HeroSummon(X + 1, Y);
			break;
		}
		Sleep(100);
	}
	return 0;
}
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

const int HEIGHT = 11;
const int WIDTH = 21;
int map[HEIGHT][WIDTH]; //0 - empty, 1 - wall, 2 - food

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


void HeroInit() {
	SetXY(5, 10);
	cout << "@";
}

int main()
{
	Map Map;
	Map.MapPreSet();
	Map.MapBuilder();
	while (1) {
		HeroInit();
	}
	return 0;
}
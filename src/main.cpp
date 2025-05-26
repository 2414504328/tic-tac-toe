#include "raylib.h"
#include<iostream>

using namespace std;

struct ScreenSize
{
	int width, hight;
};

short tttBoard[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
bool isOTurn = false;

const ScreenSize screenSize = { 600, 640 };
const int bottomBarHight = 40;
const int xOffset = 31;
const int fountSize = 212;
const char* playerChar[3] = {" ", "X", "O"};


void Reset();
void Update();
void DrawGame();
void DrawText(const char* text, int x, int y);

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenSize.width, screenSize.hight, "Tic Tac Toe");

	Reset();
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(WHITE);

		Update();

		DrawGame();
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void Reset() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			tttBoard[i][j] = 0;
		}
	}
	isOTurn = false;
}

void Update() {
	bool isMouseClicked = IsMouseButtonPressed(0);

	if (!isMouseClicked) {
		return;
	}

	int mousePosX = GetMouseX();
	int mousePosY = GetMouseY();
	short coloum = -1;
	short row = -1;
	bool isBottomBarClicked = false;
	//cout << "Mouse Pos: X=" << mousePosX << " Y=" << mousePosY << endl;
	if (mousePosX >= 0 && mousePosX <= 200) { // A colloum clicked
		cout << "A colloum clicked" << endl;
		coloum = 0;
	}
	else if (mousePosX >= 200 && mousePosX <= 400) { // B colloum clicked
		cout << "B colloum clicked" << endl;
		coloum = 1;
	}
	else /*if (mousePosX >= 400 && mousePosX <= 600)*/ { // C colloum clicked
		cout << "C colloum clicked" << endl;
		coloum = 2;
	}
	if (mousePosY >= 0 && mousePosY <= 200) { // 1st Row clicked
		cout << "1st Row clicked" << endl;
		row = 0;
	}
	else if (mousePosY >= 200 && mousePosY <= 400) { // 2nd Row clicked
		cout << "2nd Row clicked" << endl;
		row = 1;
	}
	else if (mousePosY >= 400 && mousePosY <= 600) { // 3rd Row clicked
		cout << "3rd Row clicked" << endl;
		row = 2;
	}
	else { // 4th Row clicked
		cout << "4th Row clicked" << endl;
		row = 3;
		isBottomBarClicked = true;
	}

	if (isBottomBarClicked) {
		return;
	}



	tttBoard[row][coloum] = 1 + isOTurn;
	isOTurn = !isOTurn;
}

void DrawGame() {
	DrawRectangle(194, 0, 9, screenSize.hight - bottomBarHight, BLACK);
	DrawRectangle(397, 0, 9, screenSize.hight - bottomBarHight, BLACK);
	DrawRectangle(0, 194, screenSize.width, 9, BLACK);
	DrawRectangle(0, 397, screenSize.width, 9, BLACK);
	DrawRectangle(0, 600, screenSize.width, bottomBarHight, BLACK);

	// draw X O
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			const char* charToPrint = playerChar[tttBoard[i][j]];
			DrawText(charToPrint, i, j);
		}
	}
}

void DrawText(const char* text, int rowIndex, int coloumIndex)
{
	DrawText(text, coloumIndex * 203 + xOffset, rowIndex * 203, fountSize, BLACK);
}

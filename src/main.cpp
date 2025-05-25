#include "raylib.h"

struct ScreenSize
{
	int width, hight;
};

ScreenSize screenSize = { 600, 600 };
short tttBoard[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
const char* playerChar[3] = {" ", "X", "O"};
int fountSize = 212;
int xOffset = 31;

void DrawText(const char* text, int x, int y);

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenSize.width, screenSize.hight, "Tic Tac Toe");
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(WHITE);

		DrawRectangle(194, 0, 9, screenSize.hight, BLACK);
		DrawRectangle(397, 0, 9, screenSize.hight, BLACK);
		DrawRectangle(0, 194, screenSize.width, 9, BLACK);
		DrawRectangle(0, 397, screenSize.width, 9, BLACK);

		// draw X O
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				const char* charToPrint = playerChar[tttBoard[i][j]];
				DrawText(charToPrint, i, j);
			}
		}
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void DrawText(const char* text, int x, int y)
{
	DrawText(text, x * 203 + xOffset, y * 203, fountSize, BLACK);
}

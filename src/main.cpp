#include <iostream>
#include <raylib.h>

int main()
{
	SetTargetFPS(30);
	InitWindow(800, 450, "my game");

	int pos_x = 30;
	int pos_y = 200;
	int size = 100;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawRectangle(pos_x, pos_y, size, size, BLUE);

		pos_x += 1;
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
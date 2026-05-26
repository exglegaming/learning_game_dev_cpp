#include <raylib.h>
#include "game_main.h"
#include <asserts.h>

struct GameData
{
	float position_x = 100;
	float position_y = 100;
};

GameData game_data;

bool InitGame()
{
	return true;
}

bool UpdateGame()
{
	float delta_time = GetFrameTime();
	if (delta_time > 1.f / 5) { delta_time = 1 / 5.f; }

	if (IsKeyDown(KEY_A)) { game_data.position_x -= 200 * delta_time; } 
	if (IsKeyDown(KEY_D)) { game_data.position_x += 200 * delta_time; } 
	if (IsKeyDown(KEY_W)) { game_data.position_y -= 200 * delta_time; } 
	if (IsKeyDown(KEY_S)) { game_data.position_y += 200 * delta_time; }

	// position_x, position_y, size_x, size_y, color
	DrawRectangle(game_data.position_x, game_data.position_y, 50, 50, {255, 0, 200, 255});

	return true;
}

void CloseGame()
{
}

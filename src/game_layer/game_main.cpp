#include <raylib.h>
#include <asset_manager.h>
#include <asserts.h>
#include "game_main.h"

struct GameData
{
	
};

GameData game_data;
AssetManager asset_manager;

bool InitGame()
{
	asset_manager.LoadAll();
	return true;
}

bool UpdateGame()
{
	float delta_time = GetFrameTime();
	if (delta_time > 1.f / 5) { delta_time = 1 / 5.f; }

	DrawTexturePro(asset_manager.dirt, {0, 0, (float)asset_manager.dirt.width, (float)asset_manager.dirt.height},
		{50, 50, 100, 100}, {}, 0.0, WHITE);

	return true;
}

void CloseGame()
{
}

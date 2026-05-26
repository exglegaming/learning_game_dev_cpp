#include "game_main.h"
#include <raylib.h>
#include <asset_manager.h>
#include <asserts.h>
#include <game_map.h>

struct GameData
{
	GameMap game_map;
};

GameData game_data;
AssetManager asset_manager;

bool InitGame()
{
	asset_manager.LoadAll();

	game_data.game_map.Create(30, 10);

	game_data.game_map.GetBlockUnsafe(0, 0).type = Block::dirt;
	game_data.game_map.GetBlockUnsafe(1, 1).type = Block::dirt;
	game_data.game_map.GetBlockUnsafe(2, 2).type = Block::dirt;
	game_data.game_map.GetBlockUnsafe(3, 3).type = Block::dirt;
	game_data.game_map.GetBlockUnsafe(4, 4).type = Block::dirt;

	return true;
}

bool UpdateGame()
{
	float delta_time = GetFrameTime();
	if (delta_time > 1.f / 5) { delta_time = 1 / 5.f; }

	ClearBackground({75, 75, 150, 255});

	for (int y = 0; y < game_data.game_map.h; y++)
	{
		for (int x = 0; x < game_data.game_map.w; x++)
		{
			auto &b = game_data.game_map.GetBlockUnsafe(x, y);

			if (b.type != Block::air)
			{
				float size = 32.0;
				float pos_x = x * size;
				float pos_y = y * size;

				DrawTexturePro(
					asset_manager.dirt,
					Rectangle{0, 0, (float)asset_manager.dirt.width, (float)asset_manager.dirt.height}, // Source
					{pos_x, pos_y, size, size}, // Destination
					{0, 0}, // Origin (top-left corner)
					0.0f, // Rotaion
					WHITE // Tint
				);
			}
		}
	}
	

	return true;
}

void CloseGame()
{
}

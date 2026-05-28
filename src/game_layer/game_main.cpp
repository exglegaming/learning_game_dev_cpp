#include "game_main.h"
#include <raylib.h>
#include <asset_manager.h>
#include <asserts.h>
#include <game_map.h>
#include <helpers.h>
#include <imgui.h>
#include <cmath>
#include <raymath.h>

struct GameData
{
	GameMap game_map;
	Camera2D camera;
};

GameData game_data;
AssetManager asset_manager;

bool InitGame()
{
	asset_manager.LoadAll();

	game_data.game_map.Create(700, 500);

	for (int i = 0; i < 700; i ++)
	{
		for (int j = 0; j < 500; j++)
		{
			game_data.game_map.GetBlockUnsafe(i, j).type = Block::Stone;
		}
	}

	game_data.game_map.GetBlockUnsafe(0, 0).type = Block::Dirt;
	game_data.game_map.GetBlockUnsafe(1, 1).type = Block::Grass;
	game_data.game_map.GetBlockUnsafe(2, 2).type = Block::GoldBlock;
	game_data.game_map.GetBlockUnsafe(3, 3).type = Block::Glass;
	game_data.game_map.GetBlockUnsafe(4, 4).type = Block::Platform;

	game_data.camera.target = {0, 0};
	game_data.camera.rotation = 0.0f;
	game_data.camera.zoom = 100.0f;

	return true;
}

bool UpdateGame()
{
	float delta_time = GetFrameTime();
	if (delta_time > 1.f / 5) { delta_time = 1 / 5.f; }

	game_data.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

	ClearBackground({75, 75, 150, 255});

	if (IsKeyDown(KEY_A)) game_data.camera.target.x -= 7.f * delta_time;
	if (IsKeyDown(KEY_D)) game_data.camera.target.x += 7.f * delta_time;
	if (IsKeyDown(KEY_W)) game_data.camera.target.y -= 7.f * delta_time;
	if (IsKeyDown(KEY_S)) game_data.camera.target.y += 7.f * delta_time;

	Vector2 world_pos = GetScreenToWorld2D(GetMousePosition(), game_data.camera);
	int block_x = (int)floor(world_pos.x);
	int block_y = (int)floor(world_pos.y);

	ImGui::Begin("Dev Window");

	ImGui::Text("Tile Selector");
	
	ImGui::End();

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		auto b = game_data.game_map.GetBlockSafe(block_x, block_y);
		if (b)
		{
			*b = {};
		}
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		auto b = game_data.game_map.GetBlockSafe(block_x, block_y);
		if (b)
		{
			b->type = Block::GoldBlock;
		}
	}

	BeginMode2D(game_data.camera);

	Vector2 top_left_view = GetScreenToWorld2D({0, 0}, game_data.camera);
	Vector2 bottom_right_view =GetScreenToWorld2D({(float)GetScreenWidth(), (float)GetScreenHeight()}, game_data.camera);

	int start_x_view = (int)floorf(top_left_view.x - 1);
	int end_x_view = (int)ceilf(bottom_right_view.x + 1);
	int start_y_view = (int)floorf(top_left_view.y - 1);
	int end_y_view = (int)ceilf(bottom_right_view.y + 1);

	start_x_view = Clamp(start_x_view, 0, game_data.game_map.w - 1);
	end_x_view = Clamp(end_x_view, 0, game_data.game_map.w - 1);
	start_y_view = Clamp(start_y_view, 0, game_data.game_map.h - 1);
	end_y_view = Clamp(end_y_view, 0, game_data.game_map.h - 1);

	for (int y = start_y_view; y <= end_y_view; y++)
	{
		for (int x = start_x_view; x <= end_x_view; x++)
		{
			auto &b = game_data.game_map.GetBlockUnsafe(x, y);

			if (b.type != Block::Air)
			{
				
				DrawTexturePro(
					asset_manager.textures,
					GetTextureAtlas(b.type, 0, 32, 32), // Source
					{(float)x, (float)y, 1, 1}, // Destination
					{0, 0}, // Origin (top-left corner)
					0.0f, // Rotaion
					WHITE // Tint
				);
			}
		}
	}

	// Draw selected block
	DrawTexturePro(
		asset_manager.frame,
		{0, 0, (float)asset_manager.frame.width, (float)asset_manager.frame.height}, // Source
		{(float)block_x, (float)block_y, 1, 1}, // Destination
		{0, 0}, // Origin (top-left corner)
		0.0f, // Rotation
		WHITE // Tint
	);
	
	EndMode2D();

	DrawFPS(10, 10);
	return true;
}

void CloseGame()
{
}

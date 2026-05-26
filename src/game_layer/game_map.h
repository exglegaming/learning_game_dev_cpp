#pragma once

#include <vector>
#include <blocks.h>

struct GameMap
{
	int w = 0;
	int h = 0;

	std::vector<Block> map_data;

	void Create(int w, int h);
	Block &GetBlockUnsafe(int x, int y);
	Block *GetBlockSafe(int x, int y);
};
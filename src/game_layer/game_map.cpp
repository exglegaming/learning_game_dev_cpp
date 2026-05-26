#include "game_map.h"
#include <asserts.h>

void GameMap::Create(int w, int h)
{
	*this = {}; // Resets all the data
	map_data.resize(w * h);

	this->w = w;
	this->h = h;

	for (auto &e: map_data) { e = {}; } // Clear all block data
}

Block &GameMap::GetBlockUnsafe(int x, int y)
{
	permaAssertCommentDevelopement(map_data.size() ==
		w * h, "Map data not initialized");
	
	permaAssertCommentDevelopement(x >= 0 &&
		y >= 0 && x < w && y < h, "GetBlockUnsafe out of bounds error");

	return map_data[x + y * w];
}

Block *GameMap::GetBlockSafe(int x, int y)
{
	permaAssertCommentDevelopement(map_data.size() ==
		w * h, "Map data not initialized");

	if (x < 0 || y < 0 || x >= w || y >= h) { return nullptr; }

	return &map_data[x + y * w];
}
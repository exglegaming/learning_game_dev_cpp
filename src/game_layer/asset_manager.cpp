#include "asset_manager.h"

void AssetManager::LoadAll()
{
	dirt = LoadTexture("../resources/dirt.png");
	textures = LoadTexture("../resources/textures.png");
	frame = LoadTexture("../resources/frame.png");
}
#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include <game_main.h>

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // No log output to the console by raylib
#endif

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");
	SetExitKey(KEY_NULL); // Disable Esc from closing window
	SetTargetFPS(240);

	rlImGuiSetup(true);
	ImGuiIO &io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2; // You can make it even bigger

	if (!InitGame())
	{
		return 0;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();
		// Docking stuff for ImGui...
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
	
		if (!UpdateGame())
		{
			CloseWindow();
		}

		rlImGuiEnd();
		EndDrawing();
	}

	CloseWindow();
	CloseGame();
	rlImGuiShutdown();
	return 0;
}

#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");

	rlImGuiSetup(true);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();

		Color c;
		c.r = 255;
		c.g = 0;
		c.b = 200;
		c.a = 255;

		DrawText("Congrats! You created your first window!", 190, 200, 20, c);

		ImGui::Begin("test");

		ImGui::Text("hello");
		ImGui::Button("button");

		ImGui::End();
		
		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();

	return 0;
}

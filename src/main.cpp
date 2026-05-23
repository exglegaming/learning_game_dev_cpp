#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");

#pragma region imgui
	rlImGuiSetup(true);

	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2.5; // You can make it even bigger
#pragma endregion

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

	#pragma region imgui
		rlImGuiBegin();

		// Docking stuff for ImGui...
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
	#pragma endregion
	
		Color c;
		c.r = 255;
		c.g = 0;
		c.b = 200;
		c.a = 255;

		DrawText("Congrats! You created your first window!", 190, 200, 20, c);

	#pragma region imgui windows
		ImGui::Begin("test");

		ImGui::ShowDemoWindow();

		ImGui::Text("hello");
		if (ImGui::Button("button"))
		{
			std::cout << "Text\n";
		}
		ImGui::SameLine();
		if (ImGui::Button("Button2"))
		{
			std::cout << "Second Button\n";
		}

		ImGui::End();

		ImGui::Begin("Second Window");

		ImGui::Text("Hello");
		ImGui::Separator();
		ImGui::NewLine();
		static float a = 0;
		ImGui::SliderFloat("Slider", &a, 0, 1);

		ImGui::End();
	#pragma endregion

		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();

	return 0;
}

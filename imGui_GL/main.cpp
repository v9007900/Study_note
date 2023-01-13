#include "include.h"
#include<iostream>

bool  bWnd = true;

void Render()
{

}

static bool 方框 = true;
static bool Home = true; 
float 滑块[10]{};

bool GUI::CreateWnd();

void Menu()
{
	if (Home)//判断 Home 是否按下
	{
		ImGui::SetNextWindowBgAlpha(0.1f);
		ImGui::SetNextWindowSize(ImVec2(450, 600), ImGuiCond(150));//imgui 窗口大小
		if (ImGui::Begin(u8"标题", NULL, ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoCollapse))
		{


			ImGui::Button(u8"と", ImVec2(100, 100));
			ImGui::Button(u8"も", ImVec2(100, 100));
			ImGui::Button(u8"う", ImVec2(100, 100));
			ImGui::Button(u8"ご", ImVec2(100, 100));


			ImGui::Checkbox(u8"开启透视", &方框);//选项框
			ImGui::SliderFloat(u8"确认", 滑块,0,10,"%.3f",1);
			ImGui::Text(u8"%d", &滑块,ImVec2(100, 100));
			//ImGui::PushFont(font2);

		
		}ImGui::End();
	}	
}




int main()
{
	GUI::CreateWnd();
	GUI::WndLoop((DRAWFUN)Render, (DRAWFUN)Menu,bWnd);
	return 0;
}



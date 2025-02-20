//-----------------------------------------------------------------------------
// @brief  メイン処理.
// @remark © -2025 Fujii Gaku-
//-----------------------------------------------------------------------------

/// @brief Applies to "Main func" or something else in this project.
#include "DxLib.h"
#include "Screen.h"
#include "FPS.h"
#include "LoopCondition.h"

/// @brief Header for added scenes and management class.
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "SceneManager.h"


int WINAPI WinMain(_In_		HINSTANCE hInstance,
				   _In_opt_ HINSTANCE hPrevInstance,
				   _In_		LPSTR lpCmdLine, 
				   _In_		int nCmdShow)
{
	{
		SetGraphMode(k_SCREEN_WIDTH, k_SCREEN_HEIGHT, 16);
		ChangeWindowMode(TRUE);
		if (DxLib_Init() == -1)	return -1;
		SetDrawScreen(DX_SCREEN_BACK);
		
		SetMouseDispFlag(TRUE);
	}

	auto* sceneManager = new SceneManager();

	sceneManager->Add<TitleScene> ("TitleScene");
	sceneManager->Add<StageScene> ("StageScene");
	sceneManager->Add<ResultScene>("ResultScene");

	while (LoopCondition())
	{
		sceneManager->Update();
		sceneManager->Draw();
	}

	delete sceneManager;
	DxLib_End();

	return 0;
}
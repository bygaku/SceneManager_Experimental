#include "DxLib.h"
#include "FPS.h"
#include "TitleScene.h"

TitleScene::TitleScene(SceneManager& manager)
	: SceneBase{ manager }
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	isStartSceneTransition = false;
	m_timeScene = 0.0f;
}

void TitleScene::Update()
{
	if (isStartSceneTransition)
	{
		ChangeScene("StageScene");
	}
	
	SceneFinalizeCondition();
}

void TitleScene::Draw() const
{
	DrawString(0, 200, "A", GetColor(255, 255, 255));
	DrawFormatString(0, 220, GetColor(255, 255, 255), "TIMER <AScene>: %.1f", m_timeScene);
}

void TitleScene::SceneFinalizeCondition()
{
	if (CheckHitKey(KEY_INPUT_X))
	{
		isStartSceneTransition = true;
	}
}

void TitleScene::Timer(float deltaTime)
{
	m_timeScene += deltaTime;
}
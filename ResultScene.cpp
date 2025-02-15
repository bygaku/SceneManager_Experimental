#include "DxLib.h"
#include "FPS.h"
#include "ResultScene.h"

ResultScene::ResultScene(SceneManager& manager)
	: SceneBase{ manager }
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize()
{
	isStartSceneTransition = false;
	m_timeScene = 0.0f;
}

void ResultScene::Update()
{
	if (isStartSceneTransition)
	{
		ChangeScene("TitleScene");
	}

	SceneFinalizeCondition();
}

void ResultScene::Draw() const
{
	DrawString(0, 200, "C", GetColor(255, 255, 255));
	DrawFormatString(0, 220, GetColor(255, 255, 255), "TIMER <CScene>: %.1f", m_timeScene);
}

void ResultScene::SceneFinalizeCondition()
{
	if (CheckHitKey(KEY_INPUT_V))
	{
		isStartSceneTransition = true;
	}
}

void ResultScene::Timer(float deltaTime)
{
	m_timeScene += deltaTime;
}
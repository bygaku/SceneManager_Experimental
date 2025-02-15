#include "DxLib.h"
#include "FPS.h"
#include "StageScene.h"

StageScene::StageScene(SceneManager& manager)
	: SceneBase{ manager }
{

}

StageScene::~StageScene()
{

}

void StageScene::Initialize()
{
	isStartSceneTransition = false;
	m_timeScene = 0.0f;
}

void StageScene::Update()
{
	if (isStartSceneTransition)
	{
		ChangeScene("ResultScene");
	}

	SceneFinalizeCondition();
}

void StageScene::Draw() const
{
	DrawString(0, 200, "B", GetColor(255, 255, 255));
	DrawFormatString(0, 220, GetColor(255, 255, 255), "TIMER <BScene>: %.1f", m_timeScene);
}

void StageScene::SceneFinalizeCondition()
{
	if (CheckHitKey(KEY_INPUT_C))
	{
		isStartSceneTransition = true;
	}
}

void StageScene::Timer(float deltaTime)
{
	m_timeScene += deltaTime;
}
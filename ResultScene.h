#pragma once
#include "Scene.h"

/// @brief タイトルシーンクラス
/// @remark SceneManagerクラスで呼ばれます。
class ResultScene : public SceneBase
{
public:
	ResultScene(SceneManager& manager);
	~ResultScene() override;

	/// @brief [初期化]をします。
	/// @remark リロードの時に一緒に初期化したいデータを入れる
	virtual void Initialize() override;

	/// @brief [更新処理]をします。
	virtual void Update() override;

	/// @brief [描画処理]をします。
	virtual void Draw() const override;

	/// @brief カウントアップタイマーをセットします。
	virtual void Timer(float deltaTime) override;
private:
	/// @brief シーンの[後始末]の条件式です。
	virtual void SceneFinalizeCondition() override;

private:
	bool isStartSceneTransition = false;	/// @brief シーン遷移開始フラグ
};

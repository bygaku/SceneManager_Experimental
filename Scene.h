#pragma once
#include <string_view>

class SceneManager;

/// @brief �V�[���̃C���^�[�t�F�C�X
class SceneBase
{
public:
	SceneBase(SceneManager& manager)
		: m_manager(manager) {};

	virtual ~SceneBase() = default;

	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Draw() const {};
	virtual void Timer(float deltaTime) {};
protected:
	/// @brief �V�[����؂�ւ��܂��B
	/// @param sceneName �؂�ւ���̃V�[����
	void ChangeScene(std::string_view sceneName);

	/// @brief �V�[���֑̐ؑO�̏������s���܂��B
	virtual void SceneFinalizeCondition() {};
private:
	SceneManager& m_manager;	/// @brief �V�[���}�l�[�W���[�̎Q��

protected:
	float m_timeScene = 0.0f;	/// @brief Time from current scene.
};

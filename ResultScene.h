#pragma once
#include "Scene.h"

/// @brief �^�C�g���V�[���N���X
/// @remark SceneManager�N���X�ŌĂ΂�܂��B
class ResultScene : public SceneBase
{
public:
	ResultScene(SceneManager& manager);
	~ResultScene() override;

	/// @brief [������]�����܂��B
	/// @remark �����[�h�̎��Ɉꏏ�ɏ������������f�[�^������
	virtual void Initialize() override;

	/// @brief [�X�V����]�����܂��B
	virtual void Update() override;

	/// @brief [�`�揈��]�����܂��B
	virtual void Draw() const override;

	/// @brief �J�E���g�A�b�v�^�C�}�[���Z�b�g���܂��B
	virtual void Timer(float deltaTime) override;
private:
	/// @brief �V�[����[��n��]�̏������ł��B
	virtual void SceneFinalizeCondition() override;

private:
	bool isStartSceneTransition = false;	/// @brief �V�[���J�ڊJ�n�t���O
};

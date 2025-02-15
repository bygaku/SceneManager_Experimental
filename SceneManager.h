#pragma once
#include <unordered_map>
#include <string_view>
#include "Scene.h"

class FPS;

/// @brief �V�[���}�l�[�W���[
/// @brief �V�[����ǉ����邱�ƂŊǗ����邱�Ƃ��ł��܂��B
class SceneManager
{
public:
	SceneManager();
    ~SceneManager();

    /// @brief ���s�V�[����[�X�V����]�����܂��B
    void Update();

    /// @brief ���s�V�[����[�`�揈��]�����܂��B
    void Draw() const;

    /// @brief �Q�[���ǂݍ��ݎ��ɊǗ��������V�[����[�ǉ�]��[������]�̏��������܂��B
    /// @param sceneName �ǉ�����V�[����
    template <typename SceneKind>
    inline auto Add(const std::string_view sceneName)
        -> typename std::enable_if<std::is_class<SceneKind>::value>::type
    {
        m_scenes[sceneName] = new SceneKind{ *this };

        // �ŏ��ɒǉ����ꂽ�V�[�����f�t�H���g�̃V�[���ł��B
        if (m_currentScene == nullptr)
        {
            m_currentScene = m_scenes[sceneName];
            m_currentScene->Initialize();
        }
    };

    /// @brief �V�[����؂�ւ��܂��B
    /// @param sceneName �؂�ւ���̃V�[����
    void ChangeScene(std::string_view sceneName);

private:
	std::unordered_map<std::string_view, SceneBase*> m_scenes; /// @brief �V�[���R���e�i
    SceneBase* m_currentScene;      /// @brief ���s�V�[��
    FPS*       m_fps;               /// @brief ���ԊǗ�

private:
    float m_timeFromBoot = 0.0f;	/// @brief �^�C�}�[
};

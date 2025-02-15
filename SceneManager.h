#pragma once
#include <unordered_map>
#include <string_view>
#include "Scene.h"

class FPS;

/// @brief シーンマネージャー
/// @brief シーンを追加することで管理することができます。
class SceneManager
{
public:
	SceneManager();
    ~SceneManager();

    /// @brief 現行シーンの[更新処理]をします。
    void Update();

    /// @brief 現行シーンを[描画処理]をします。
    void Draw() const;

    /// @brief ゲーム読み込み時に管理したいシーンの[追加]と[初期化]の処理をします。
    /// @param sceneName 追加するシーン名
    template <typename SceneKind>
    inline auto Add(const std::string_view sceneName)
        -> typename std::enable_if<std::is_class<SceneKind>::value>::type
    {
        m_scenes[sceneName] = new SceneKind{ *this };

        // 最初に追加されたシーンがデフォルトのシーンです。
        if (m_currentScene == nullptr)
        {
            m_currentScene = m_scenes[sceneName];
            m_currentScene->Initialize();
        }
    };

    /// @brief シーンを切り替えます。
    /// @param sceneName 切り替え先のシーン名
    void ChangeScene(std::string_view sceneName);

private:
	std::unordered_map<std::string_view, SceneBase*> m_scenes; /// @brief シーンコンテナ
    SceneBase* m_currentScene;      /// @brief 現行シーン
    FPS*       m_fps;               /// @brief 時間管理

private:
    float m_timeFromBoot = 0.0f;	/// @brief タイマー
};

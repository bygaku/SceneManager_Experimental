#include <iostream>
#include <cassert>
#include "DxLib.h"

#include "FPS.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
    m_currentScene = nullptr;

    m_fps = new FPS();
    m_fps->Initialize();

    m_timeFromBoot = 0.0f;
}

SceneManager::~SceneManager()
{
    delete m_fps;

    for (const auto& pair : m_scenes)
    {
        delete pair.second;
    }
};

void SceneManager::Update()
{
    m_fps->Update();
    m_timeFromBoot += m_fps->GetDeltaTime();

    if (m_currentScene != nullptr)
    {
        m_currentScene->Update();
        m_currentScene->Timer (m_fps->GetDeltaTime());
    }
}

void SceneManager::Draw() const
{
    m_fps->Draw();

    if (m_currentScene != nullptr)
    {
        m_currentScene->Draw();
    }
    
#ifdef _DEBUG
    DrawFormatString(0, 40, GetColor(255, 255, 255), "TIMER <FromBoot>: %.1f", m_timeFromBoot);

#endif
}

void SceneManager::ChangeScene(std::string_view sceneName)
{
    m_currentScene = m_scenes.at(sceneName);
    m_currentScene->Initialize();
}
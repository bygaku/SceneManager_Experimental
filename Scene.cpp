#include <iostream>
#include "SceneManager.h"

void SceneBase::ChangeScene(std::string_view sceneName)
{
    m_manager.ChangeScene(sceneName);
}

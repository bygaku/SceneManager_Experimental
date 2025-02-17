//-----------------------------------------------------------------------------
// @brief  FPSèàóù.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "FPS.h"

#ifdef VARIABLE_SYNC
void FPS::Initialize()
{
    m_startTime = GetNowHiPerformanceCount();

    m_frameCount = 1;
    m_average    = 0.0f;
    m_deltaTime  = 0.000001f;
    m_prevTime   = m_startTime;
    m_nowTime    = m_startTime;
}

void FPS::Update()
{
    m_nowTime   = GetNowHiPerformanceCount();
    m_deltaTime = (m_nowTime - m_prevTime) / k_MicroSecond;
    m_prevTime  = m_nowTime;

    if (m_frameCount == k_GAME_FPS)
    {
        float totalFrameTime = static_cast<float>(m_nowTime - m_startTime);
        float calcAverage    = totalFrameTime / k_GAME_FPS;

        m_average    = k_MicroSecond / calcAverage;
        m_startTime  = GetNowHiPerformanceCount();
        m_frameCount = 1;
    }
    else
    {
        m_frameCount++;
    }

    //Wait();
}

void FPS::Draw() const
{
#ifdef _DEBUG
    DrawFormatString(0, 0,  GetColor(255, 255, 255), "%.1f", m_average  );
    DrawFormatString(0, 20, GetColor(255, 255, 255), "%.1f", m_deltaTime);
#endif // _DEBUG
}

#else
void FPS::Wait() const
{
    auto wait = 0.0f;   /// @brief ë“ã@éûä‘

    wait = k_MicroSecond / k_GAME_FPS * m_frameCount
         - (m_nowTime - m_startTime);

    wait /= k_MillSecond;

    if (wait > 0 && wait <= k_WaitTimeMill)
        WaitTimer(static_cast<int>(wait));
}
#endif // å≈íËFPSê›íËéû

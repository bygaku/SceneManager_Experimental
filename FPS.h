#pragma once

#define VARIABLE_SYNC 0;		/// @brief 可変FPS
constexpr int  k_GAME_FPS = 60;	/// @brief 固定FPS

class FPS
{
	static constexpr int   k_WaitTimeMill = 1000;		/// @brief 最大値
	static constexpr float k_MillSecond   = 1000.0f;	/// @brief １ミリ秒
	static constexpr float k_MicroSecond  = 1000000.0f;	/// @brief １マイクロ秒

	LONGLONG m_startTime = 0;			/// @brief １フレーム目の計測時間
	LONGLONG m_nowTime   = 0;			/// @brief 現在の計測時間
	LONGLONG m_prevTime  = 0;			/// @brief 以前の計測時間
	int	  m_frameCount   = 1;			/// @brief 現在のフレーム数
	float m_deltaTime    = 0.000001f;	/// @brief デルタタイム	
	float m_average      = 0.0f;		/// @brief 平均FPS値
public:
	/// @brief 初期化します。
	void Initialize();

	/// @brief 更新処理をします。
	void Update();

	/// @brief 描画処理をします。
	void Draw() const;

	/// @brief 差分を取得します。
	float GetDeltaTime() const { return m_deltaTime; };

private:
	/// @brief 待機時間を計算します。
	void Wait() const;
};

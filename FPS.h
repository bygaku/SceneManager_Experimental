#pragma once

#define VARIABLE_SYNC 0;		/// @brief ��FPS
constexpr int  k_GAME_FPS = 60;	/// @brief �Œ�FPS

class FPS
{
	static constexpr int   k_WaitTimeMill = 1000;		/// @brief �ő�l
	static constexpr float k_MillSecond   = 1000.0f;	/// @brief �P�~���b
	static constexpr float k_MicroSecond  = 1000000.0f;	/// @brief �P�}�C�N���b

	LONGLONG m_startTime = 0;			/// @brief �P�t���[���ڂ̌v������
	LONGLONG m_nowTime   = 0;			/// @brief ���݂̌v������
	LONGLONG m_prevTime  = 0;			/// @brief �ȑO�̌v������
	int	  m_frameCount   = 1;			/// @brief ���݂̃t���[����
	float m_deltaTime    = 0.000001f;	/// @brief �f���^�^�C��	
	float m_average      = 0.0f;		/// @brief ����FPS�l
public:
	/// @brief ���������܂��B
	void Initialize();

	/// @brief �X�V���������܂��B
	void Update();

	/// @brief �`�揈�������܂��B
	void Draw() const;

	/// @brief �������擾���܂��B
	float GetDeltaTime() const { return m_deltaTime; };

private:
	/// @brief �ҋ@���Ԃ��v�Z���܂��B
	void Wait() const;
};

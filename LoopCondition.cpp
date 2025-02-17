//-----------------------------------------------------------------------------
// @brief  ƒ‹[ƒvˆ—.
// @remark ? -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "LoopCondition.h"

bool LoopCondition()
{
	if (ProcessMessage())				
		return false;

	if (ScreenFlip())					
		return false;

	if (ClearDrawScreen())				
		return false;

	if (CheckHitKey(KEY_INPUT_ESCAPE))
		return false;

	return true;
}

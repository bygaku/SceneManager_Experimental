//-----------------------------------------------------------------------------
// @brief  ƒ‹[ƒvˆ—.
// @remark ? -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "LoopCondition.h"

bool LoopCondition()
{
	if (ProcessMessage() != 0)				
		return false;

	if (ScreenFlip() != 0)					
		return false;

	if (ClearDrawScreen() != 0)				
		return false;

	if (CheckHitKey(KEY_INPUT_ESCAPE) >= 1)
		return false;

	return true;
}

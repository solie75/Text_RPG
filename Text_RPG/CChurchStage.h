#pragma once
#include "CStage.h"
class CChurchStage :
	public CStage
{
public:
	virtual void StageTick() override;
	virtual void StageInit() override;
	virtual void StageRender() override;

public:
	void BasicRender();
	bool bCallRender = true;
	int iCurTextPart = 1;

	void TextPart1();
	void TextPart2();
	void TextPart3();
	void TextPart4();
	void TextPart5();
	void TextPart6();
};


#pragma once
#include "CStage.h"
class CChurchStage :
	public CStage
{
public:
	CChurchStage();
	~CChurchStage();

	virtual void StageTick() override;
	virtual void StageInit() override;
	virtual void StageRender() override;

public:
	void BasicRender();
	void FirstChurchRender();

	void ToChurchTextPart1();
	void ToChurchTextPart2();
	void ToChurchTextPart3();
	void ToChurchTextPart4();
	void ToChurchTextPart5();
	void ToChurchTextPart6();
	void ToChurchTextPart7();
	void ToChurchTextPart8();

	void NoAccessToHealRender();
	bool bCallRender = true;
	int iCurTextPart = 1;
	int iCurFirstTextPart = 1;

	void TextPart1();
	void TextPart2();
	void TextPart3();
	void TextPart4();
	void TextPart5();
	void TextPart6();
};


// � 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_TEXTBOX_H_
#define _W_TEXTBOX_H_

#include "WControl.h"
#include "WLerp.h"

class WTextBox : public WControl
{
public:
	WTextBox(W_INT zIndex = 0);
	WTextBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WTextBox(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WTextBox(WRectF location, W_INT zIndex = 0);
	~WTextBox(void);

	W_FLOAT BorderThickness(W_FLOAT f);
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

	W_FLOAT BorderThickness(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	void Render(void) override;

	void KeyDown(WKeyboardArgs* Args) override;
	void MouseDown(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	wchar_t* FontFamily(void) const;
	wchar_t* Content(UINT32& outLen) const;
	W_FLOAT	FontSize(void) const;

	wchar_t* FontFamily(wchar_t* intake);
	wchar_t* Content(wchar_t* content);
	wchar_t* Content(wchar_t* content, UINT32 Length);
	W_FLOAT	FontSize(W_FLOAT intake);

	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(bool intake);

protected:
	// Dynamic Color
	void HoverBorderTick(WEntity* sender, WEventArgs* args);
	void HoverBorderDone(WEntity* sender, WEventArgs* args);

	void UnHoverBorderTick(WEntity* sender, WEventArgs* args);
	void UnHoverBorderDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorBord;
	WColorTransform* UnHoverColorBord;

	void HoverForegroundTick(WEntity* sender, WEventArgs* args);
	void HoverForegroundDone(WEntity* sender, WEventArgs* args);

	void UnHoverForegroundTick(WEntity* sender, WEventArgs* args);
	void UnHoverForegroundDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorFore;
	WColorTransform* UnHoverColorFore;

	void HoverBackgroundTick(WEntity* sender, WEventArgs* args);
	void HoverBackgroundDone(WEntity* sender, WEventArgs* args);

	void UnHoverBackgroundTick(WEntity* sender, WEventArgs* args);
	void UnHoverBackgroundDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorBack;
	WColorTransform* UnHoverColorBack;

	// Extended Border
	void Extend(WEntity* sender, WEventArgs* args);
	void Shrink(WEntity* sender, WEventArgs* args);

	void ExtendDone(WEntity* sender, WEventArgs* args);
	void ShrinkDone(WEntity* sender, WEventArgs* args);

	WLerp* ExBordLerpExtend;
	WLerp* ExBordLerpShrink;

	W_FLOAT ExBordRatio;

	bool m_UseExtendedBorder;

	// Normal
	wchar_t* m_Content;
	wchar_t* m_family;
	W_FLOAT m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;
};

#endif // !_W_TEXTBOX_H_
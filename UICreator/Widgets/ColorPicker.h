#pragma once

#include <lvgl.h>

class ColorPicker
{
	typedef void(*cp_callback)(uint32_t selectedColor);
	
public:
	ColorPicker(int x, int y, int width, int height, uint32_t startColor, lv_obj_t *parent=nullptr);
	~ColorPicker();
	void SetCallback(cp_callback cb);
	void Show();
	void Hide();

private:
	lv_obj_t *cont;
	enum eChannel
	{
		A,
		R,
		G,
		B
	};
	cp_callback setCB = nullptr;
	
	struct sliderCBData
	{
		ColorPicker *cp;
		eChannel channel;
	};
	sliderCBData *rCBD, *gCBD, *bCBD, *aCBD;
	lv_obj_t *exCol, *rSlider, *gSlider, *bSlider, *aSlider;
	static void sliderCB(lv_obj_t *obj, lv_event_t event);
	static void applyCB(lv_obj_t *obj, lv_event_t event);
	void createObjects(lv_obj_t *parent, int x, int y, int width, int height, uint32_t startColor);
	lv_style_t colStyle;
};
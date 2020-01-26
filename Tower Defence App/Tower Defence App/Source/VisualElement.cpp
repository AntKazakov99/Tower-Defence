#include "VisualElement.h"

void VisualElement::InvokeEventUpdate(Uint32 deltaTime)
{
	Update(this, deltaTime);
}

void VisualElement::InvokeEventMouseMotion(SDL_MouseMotionEvent e)
{
	SDL_Rect* dstRect = GetDestinationRectangle();
	if (dstRect)
	{
		if (e.x >= dstRect->x && e.x <= dstRect->x + dstRect->w &&
			e.y >= dstRect->y && e.y <= dstRect->y + dstRect->h)
		{
			if (!isMouseOver)
			{
				isMouseOver = true;
				MouseEnter(this, e);
			}
			MouseMove(this, e);
		}
		else
		{
			if (isMouseOver)
			{
				isMouseOver = false;
				MouseLeave(this, e);
			}
			isPressed = false;
		}
	}
}

void VisualElement::InvokeEventMouseButtonDown(SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseDown(this, e);
		isPressed = true;
	}
}

void VisualElement::InvokeEventMouseButtonUp(SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseUp(this, e);
		if (isPressed)
		{
			Click(this, e);
		}
	}
	isPressed = false;
}

void VisualElement::InvokeEventMouseWheel(SDL_MouseWheelEvent e)
{
	if (isMouseOver)
	{
		MouseWheel(this, e);
	}
}

void VisualElement::SetUpdate(void Update(VisualElement*, Uint32))
{
	this->Update = Update;
}

void VisualElement::SetClick(void Click(VisualElement*, SDL_MouseButtonEvent))
{
	this->Click = Click;
}

void VisualElement::SetMouseEnter(void MouseEnter(VisualElement*, SDL_MouseMotionEvent))
{
	this->MouseEnter = MouseEnter;
}

void VisualElement::SetMouseLeave(void MouseLeave(VisualElement*, SDL_MouseMotionEvent))
{
	this->MouseLeave = MouseLeave;
}

void VisualElement::SetMouseMove(void MouseMove(VisualElement*, SDL_MouseMotionEvent))
{
	this->MouseMove = MouseMove;
}

void VisualElement::SetMouseDown(void MouseDown(VisualElement*, SDL_MouseButtonEvent))
{
	this->MouseDown = MouseDown;
}

void VisualElement::SetMouseUp(void MouseUp(VisualElement*, SDL_MouseButtonEvent))
{
	this->MouseUp = MouseUp;
}

void VisualElement::SetMouseWheel(void MouseWheel(VisualElement*, SDL_MouseWheelEvent))
{
	this->MouseWheel = MouseWheel;
}

void VisualElement::SetZIndex(int zIndex)
{
	this->zIndex = zIndex;
}

int VisualElement::GetZIndex()
{
	return zIndex;
}

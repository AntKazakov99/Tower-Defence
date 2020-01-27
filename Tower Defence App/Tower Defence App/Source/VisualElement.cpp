#include "VisualElement.h"

void VisualElement::InvokeEventUpdate(Object* owner, Uint32 deltaTime)
{
	Update(owner, this, deltaTime);
}

void VisualElement::InvokeEventMouseMotion(Object* owner, SDL_MouseMotionEvent e)
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
				MouseEnter(owner, this, e);
			}
			MouseMove(owner, this, e);
		}
		else
		{
			if (isMouseOver)
			{
				isMouseOver = false;
				MouseLeave(owner, this, e);
			}
			isPressed = false;
		}
	}
}

void VisualElement::InvokeEventMouseButtonDown(Object* owner, SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseDown(owner, this, e);
		isPressed = true;
	}
}

void VisualElement::InvokeEventMouseButtonUp(Object* owner, SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseUp(owner, this, e);
		if (isPressed)
		{
			Click(owner, this, e);
		}
	}
	isPressed = false;
}

void VisualElement::InvokeEventMouseWheel(Object* owner, SDL_MouseWheelEvent e)
{
	if (isMouseOver)
	{
		MouseWheel(owner, this, e);
	}
}

void VisualElement::SetUpdate(void Update(Object*, Object*, Uint32))
{
	this->Update = Update;
}

void VisualElement::SetClick(void Click(Object*, Object*, SDL_MouseButtonEvent))
{
	this->Click = Click;
}

void VisualElement::SetMouseEnter(void MouseEnter(Object*, Object*, SDL_MouseMotionEvent))
{
	this->MouseEnter = MouseEnter;
}

void VisualElement::SetMouseLeave(void MouseLeave(Object*, Object*, SDL_MouseMotionEvent))
{
	this->MouseLeave = MouseLeave;
}

void VisualElement::SetMouseMove(void MouseMove(Object*, Object*, SDL_MouseMotionEvent))
{
	this->MouseMove = MouseMove;
}

void VisualElement::SetMouseDown(void MouseDown(Object*, Object*, SDL_MouseButtonEvent))
{
	this->MouseDown = MouseDown;
}

void VisualElement::SetMouseUp(void MouseUp(Object*, Object*, SDL_MouseButtonEvent))
{
	this->MouseUp = MouseUp;
}

void VisualElement::SetMouseWheel(void MouseWheel(Object*, Object*, SDL_MouseWheelEvent))
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

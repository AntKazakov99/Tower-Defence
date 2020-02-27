#include "VisualElement.h"

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
				if (MouseEnter)
				{
					MouseEnter(owner, this, e);
				}
			}
			if (MouseMove)
			{
				MouseMove(owner, this, e);
			}
		}
		else
		{
			if (isMouseOver)
			{
				isMouseOver = false;
				if (MouseLeave)
				{
					MouseLeave(owner, this, e);
				}
			}
			isPressed = false;
		}
	}
}

void VisualElement::InvokeEventMouseButtonDown(Object* owner, SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		if (MouseDown)
		{
			MouseDown(owner, this, e);
		}
		isPressed = true;
	}
}

void VisualElement::InvokeEventMouseButtonUp(Object* owner, SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		if (MouseUp)
		{
			MouseUp(owner, this, e);
		}
		if (isPressed)
		{
			if (Click)
			{
				Click(owner, this, e);
			}
		}
	}
	isPressed = false;
}

void VisualElement::InvokeEventMouseWheel(Object* owner, SDL_MouseWheelEvent e)
{
	if (isMouseOver)
	{
		if (MouseWheel)
		{
			MouseWheel(owner, this, e);
		}
	}
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

bool VisualElement::GetIsVisible()
{
	return isVisible;
}

void VisualElement::SetIsVisible(bool IsVisible)
{
	isVisible = IsVisible;
	isMouseOver = false;
}

SDL_Rect* VisualElement::GetDestinationRectangle()
{
	return dstRect;
}

void VisualElement::SetDestinationRectangle(SDL_Rect* dstRect)
{
	delete this->dstRect;
	this->dstRect = dstRect;
}

int VisualElement::GetLeft()
{
	if (dstRect)
	{
		return dstRect->x;
	}
	else
	{
		return 0;
	}

}

void VisualElement::SetLeft(int left)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->x = left;
}

int VisualElement::GetTop()
{
	if (dstRect)
	{
		return dstRect->y;
	}
	else
	{
		return 0;
	}
}

void VisualElement::SetTop(int top)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->y = top;
}

void VisualElement::SetSize(int width, int height)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->w = width;
	dstRect->h = height;
}

void VisualElement::SetLocation(int left, int top)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->x = left;
	dstRect->y = top;
}

int VisualElement::GetWidth()
{
	if (dstRect)
	{
		return dstRect->w;
	}
	else
	{
		return 0;
	}
}

void VisualElement::SetWidth(int width)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->w = width;
}

int VisualElement::GetHeight()
{
	if (dstRect)
	{
		return dstRect->h;
	}
	else
	{
		return 0;
	}
}

void VisualElement::SetHeight(int height)
{
	if (!dstRect)
	{
		dstRect = new SDL_Rect();
	}
	dstRect->h = height;
}

#include "VisualElement.h"

void VisualElement::MouseEnter(SDL_MouseMotionEvent e)
{
	// virtual
}

void VisualElement::MouseLeave(SDL_MouseMotionEvent e)
{
	// virtual
}

void VisualElement::MouseMove(SDL_MouseMotionEvent e)
{
	// virtual
}

void VisualElement::MouseDown(SDL_MouseButtonEvent e)
{
	// virtual
}

void VisualElement::MouseUp(SDL_MouseButtonEvent e)
{
	// virtual
}

void VisualElement::MouseWheel(SDL_MouseWheelEvent e)
{
	// virtual
}

void VisualElement::SetTexture(SDL_Texture* texture)
{
	this->texture = texture;
}

SDL_Texture* VisualElement::GetTexture()
{
	return texture;
}

void VisualElement::SetSourceRect(SDL_Rect* srcRect)
{
	this->srcRect = srcRect;
}

SDL_Rect* VisualElement::GetSourceRect()
{
	return srcRect;
}

void VisualElement::SetDestinationRect(SDL_Rect* dstRect)
{
	this->dstRect = dstRect;
}

SDL_Rect* VisualElement::GetDestinationRect()
{
	return dstRect;
}

int VisualElement::GetZIndex()
{
	return zIndex;
}

void VisualElement::InvokeEventMouseMotion(SDL_MouseMotionEvent e)
{
	// Проверяет находится ли курсор в пределах данного элемента
	if (e.x >= dstRect->x && e.x <= dstRect->x + dstRect->w &&
		e.y >= dstRect->y && e.y <= dstRect->y + dstRect->h)	
	{
		if (!isMouseOver)
		{
			isMouseOver = true;
			MouseEnter(e);
		}
		MouseMove(e);
	}
	else
	{
		if (isMouseOver)
		{
			isMouseOver = false;
			MouseLeave(e);
		}
	}
}

void VisualElement::InvokeEventMouseButtonDown(SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseDown(e);
	}
}

void VisualElement::InvokeEventMouseButtonUp(SDL_MouseButtonEvent e)
{
	if (isMouseOver)
	{
		MouseUp(e);
	}
}

void VisualElement::InvokeEventMouseWheel(SDL_MouseWheelEvent e)
{
	if (isMouseOver)
	{
		MouseWheel(e);
	}
}

#include "VisualElement.h"

void VisualElement::SetZIndex(int zIndex)
{
	this->zIndex = zIndex;
}

int VisualElement::GetZIndex()
{
	return zIndex;
}

// Методы класса Text

void Text::CreateSurface()
{
	if (font)
	{
		SDL_FreeSurface(surface);
		surface = TTF_RenderUTF8_Blended(font, this->text.c_str(), foreground);
		dstRect->h = surface->h;
		dstRect->w = surface->w;
	}
}

int Text::GetLeft()
{
	return dstRect->x;
}

void Text::SetLeft(int left)
{
	dstRect->x = left;
}

int Text::GetTop()
{
	return dstRect->y;
}

void Text::SetTop(int top)
{
	dstRect->y = top;
}

void Text::SetText(const char* text)
{
	this->text = text;
	CreateSurface();
}

const char* Text::GetText()
{
	return text.c_str();
}

void Text::SetFontFile(const char* file)
{
	fontFile = file;
	TTF_CloseFont(font);
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	CreateSurface();
}

void Text::SetFontSize(int pt)
{
	fontSize = pt;
	TTF_CloseFont(font);
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	CreateSurface();
}

int Text::GetFontSize()
{
	return fontSize;
}

void Text::SetForeground(SDL_Color foreground)
{
	this->foreground = foreground;
	CreateSurface();
}

SDL_Color Text::GetForeground()
{
	return foreground;
}

SDL_Surface* Text::GetSurface()
{
	return surface;
}

SDL_Rect* Text::GetSourceRectangle()
{
	return nullptr;
}

SDL_Rect* Text::GetDestinationRectangle()
{
	return dstRect;
}

// Методы класса Image

void Image::SetSurface(SDL_Surface* surface)
{
	this->surface = surface;
}

void Image::SetSourceRectangle(SDL_Rect* srcRect)
{
	this->srcRect = srcRect;
}

void Image::SetDestinationRectangle(SDL_Rect* dstRect)
{
	this->dstRect = dstRect;
}

SDL_Surface* Image::GetSurface()
{
	return surface;
}

SDL_Rect* Image::GetSourceRectangle()
{
	return srcRect;
}

SDL_Rect* Image::GetDestinationRectangle()
{
	return dstRect;
}

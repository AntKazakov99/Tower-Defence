#include "Text.h"

void Text::CreateSurface()
{
	if (font)
	{
		resource->SetSurface(TTF_RenderUTF8_Blended(font, this->text.c_str(), foreground));
		if (resource->GetSurface())
		{
			SetWidth(resource->GetSurface()->w);
			SetHeight(resource->GetSurface()->h);
		}
	}
}

Text::Text()
{
	CreateSurface();
}

Text::Text(const char* text):
	text(text)
{
	CreateSurface();
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

VisualResource* Text::GetVisualResource()
{
	return resource;
}

SDL_Rect* Text::GetSourceRectangle()
{
	return nullptr;
}

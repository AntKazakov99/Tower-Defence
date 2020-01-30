#include "Image.h"

void Image::SetVisualResource(VisualResource* resource)
{
	this->resource = resource;
}

void Image::SetSourceRectangle(SDL_Rect* srcRect)
{
	this->srcRect = srcRect;
}

VisualResource* Image::GetVisualResource()
{
	return resource;
}

SDL_Rect* Image::GetSourceRectangle()
{
	return srcRect;
}

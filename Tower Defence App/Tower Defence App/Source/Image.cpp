#include "Image.h"

void Image::SetVisualResource(VisualResource* resource)
{
	this->resource = resource;
}

void Image::SetSourceRectangle(SDL_Rect* srcRect)
{
	this->srcRect = srcRect;
}

void Image::SetDestinationRectangle(SDL_Rect* dstRect)
{
	this->dstRect = dstRect;
}

VisualResource* Image::GetVisualResource()
{
	return resource;
}

SDL_Rect* Image::GetSourceRectangle()
{
	return srcRect;
}

SDL_Rect* Image::GetDestinationRectangle()
{
	return dstRect;
}

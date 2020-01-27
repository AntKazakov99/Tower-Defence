#include "Image.h"

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

#include "VisualResource.h"

VisualResource::VisualResource()
{
	// Для неинициализированного объекта
}

VisualResource::VisualResource(SDL_Surface* surface)
{
	this->surface = surface;
	isUpdated = true;
}

SDL_Surface* VisualResource::GetSurface()
{
	return surface;
}

void VisualResource::SetSurface(SDL_Surface* surface)
{
	SDL_FreeSurface(this->surface);
	this->surface = surface;
	isUpdated = true;
}

SDL_Texture* VisualResource::GetTexture()
{
	return texture;
}

void VisualResource::UpdateTexture(SDL_Renderer* renderer)
{
	SDL_DestroyTexture(texture);
	if (surface)
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		isUpdated = false;
	}
}

bool VisualResource::GetIsUpdated()
{
	return isUpdated;
}

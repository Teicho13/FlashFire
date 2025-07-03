#include "debugLines.h"
#include "core/graphics/renderer.h"

namespace FF
{
    void debugLines::Plot(const float posX, const float posY, const SDL_Color& color)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), color.r, color.g, color.b, color.a);
        SDL_RenderDrawPointF(renderer::GetRenderer(),posX,posY);
    }

    void debugLines::DrawBox(const float posX, const float posY, const float width, const float height)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), 255, 0, 0, 255);
        const SDL_FRect tempRect = SDL_FRect{posX, posY, width, height};
        SDL_RenderDrawRectF(renderer::GetRenderer(), &tempRect);
    }

    void debugLines::DrawBox(const float posX, const float posY, const float width, const float height,
        const SDL_Color& color)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), color.r,color.g,color.b,color.a);
        const SDL_FRect tempRect = SDL_FRect{posX, posY, width, height};
        SDL_RenderDrawRectF(renderer::GetRenderer(), &tempRect);
    }

    void debugLines::DrawBoxFill(const float posX, const float posY, const float width, const float height)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), 255, 0, 0, 255);
        const SDL_FRect tempRect = SDL_FRect{ posX, posY, width, height };
        SDL_RenderFillRectF(renderer::GetRenderer(), &tempRect);
    }

    void debugLines::DrawBoxFill(const float posX, const float posY, const float width, const float height,
        const SDL_Color& color)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), color.r,color.g,color.b,color.a);
        const SDL_FRect tempRect = SDL_FRect{ posX, posY, width, height };
        SDL_RenderFillRectF(renderer::GetRenderer(), &tempRect);
    }

    void debugLines::DrawLine(const float posX, const float posY, const float posX2, const float posY2)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), 255, 0, 0, 255);
        SDL_RenderDrawLineF(renderer::GetRenderer(), posX, posY, posX2, posY2);
    }

    void debugLines::DrawLine(const float posX, const float posY, const float posX2, const float posY2, const SDL_Color& color)
    {
        SDL_SetRenderDrawColor(renderer::GetRenderer(), color.r,color.g,color.b,color.a);
        SDL_RenderDrawLineF(renderer::GetRenderer(), posX, posY, posX2, posY2);
    }
}

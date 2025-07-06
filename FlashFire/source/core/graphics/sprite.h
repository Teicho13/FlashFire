#pragma once
#include <SDL_rect.h>
#include <string>

struct SDL_Texture;
namespace FF
{
    class sprite
    {
    public:
        sprite(const std::string& texturePath);
        sprite(const std::string& texturePath, int columns, int rows);

        void Draw(const SDL_FRect PositionAndSize);
        void SetFrame(int frame);
        int GetCurrentFrame() const;
        
        SDL_Texture* GetTexture() const;
        SDL_Point GetSize() const;
        void GetSourceRec(SDL_Rect &rec) const;

    protected:
        void CalculateSizeAndFrames(int columns, int rows);
        
        SDL_Texture* m_Texture = nullptr;
        SDL_Point m_Size = {0,0};
        
        int m_FrameColumns = 0;
        int m_FrameRows = 0;
        int m_Frames = 0;
        int m_CurrentFrame = 0;
    }; 
}


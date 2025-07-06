#include "sprite.h"
#include <SDL_render.h>

#include <algorithm>

#include "core/managers/textureManager.h"

namespace FF
{
    sprite::sprite(const std::string& texturePath)
    {
        //Get the width & height of the image from our surface.
        m_Texture = textureManager::CreateTexture(texturePath,m_Size.x,m_Size.y);
        m_Frames = 1;
        m_FrameRows = 1;
        m_FrameColumns = 1;
    }

    sprite::sprite(const std::string& texturePath, int columns, int rows)
    {
        //Get the width & height of the image from our surface.
        m_Texture = textureManager::CreateTexture(texturePath,m_Size.x,m_Size.y);
        CalculateSizeAndFrames(columns,rows);
    }

    void sprite::SetFrame(int frame)
    {
        //Check if frames are within bounds

        frame = std::max(frame, 0);
        frame = std::min(frame, m_Frames - 1);

        m_CurrentFrame = frame;
    }

    int sprite::GetCurrentFrame() const
    {
        return m_CurrentFrame;
    }

    void sprite::GetSourceRec(SDL_Rect& rec) const
    {
        //Set Default assumed values

        int frameW = m_CurrentFrame;
        int frameH = 0;

        //Check if current frame is bigger than max frames per column
        if(m_CurrentFrame >= m_FrameColumns)
        {
            //Check how many times the frame count goes past the max (giving us the rows)
            frameH = m_CurrentFrame / m_FrameColumns;
            //Check remainder for the current column
            frameW = m_CurrentFrame % m_FrameColumns;
        }

        rec.x = (m_Size.x * frameW);
        rec.y = (m_Size.y * frameH);
        rec.w = (m_Size.x);
        rec.h = (m_Size.y);
    }

    SDL_Texture* sprite::GetTexture() const
    {
        return m_Texture;
    }

    SDL_Point sprite::GetSize() const
    {
        return m_Size;
    }

    //Calculate correct sprite size based on the columns and rows
    //Calculate Frames based on the columns and rows
    void sprite::CalculateSizeAndFrames(int columns, int rows)
    {
        //Make sure columns and rows are not 0 or below
        if (columns <= 0)
            columns = 1;

        if (rows <= 0)
            rows = 1;

        //Calculate the size of each frame
        m_Size.x = m_Size.x / columns;
        m_Size.y = m_Size.y / rows;

        m_Frames = columns * rows;

        m_FrameRows = rows;
        m_FrameColumns = columns; 
    }
}

#include "map.h"
#include <fstream>
#include <sstream>
#include "core/graphics/sprite.h"

namespace FF
{
    void map::SetTileMap(const std::string& mapTileTexturesPath, const std::string& mapTileDataPath, const int columns, const int rows)
    {
        m_MapSheet = std::make_unique<sprite>(mapTileTexturesPath, columns, rows);
        CreateTiles(mapTileDataPath);
        m_Pickups.reserve(245);
    }

    void map::CreateTiles(const std::string& mapTileDataPath)
    {
        bool hasReachedWhile = false;
        
        //Create temporary files for handling strings
        std::ifstream file;
        std::string line;
        std::string final;

        //Open Texture Map
        file.open(mapTileDataPath);

        //Create one long string with all numbers seperated with commas

        while (std::getline(file, line))
        {
            final.append(line);
            final.append(",");
        }

        int type;
        std::string temp;
        int itX = 0;
        int itY = 0;
        std::istringstream str_buf {final};
        
        //Loop over all numbers and assign to the right array index.
        while (str_buf >> type)
        {
            hasReachedWhile = true;

            m_Map[itY][itX] = type;

            //Check if we should spawn a big or small pickup
            
            if (type == 45)
            {
                SpawnPickup(itX,itY,false);
            }

            if (type == 47)
            {
                SpawnPickup(itX,itY,true);
            }
            
            if (itX < (m_MapColumns - 1))
            {
                itX++;
            }
            else
            {
                itX = 0;
                if (itY < m_MapRows)
                {
                    itY++;
                }
            }

            if ((str_buf >> std::ws).peek() == ',')
                str_buf.ignore();

            
        }

        file.close();

        //Temporary safeguard to guarantee it has at least tried to make objects
        if (hasReachedWhile)
        {
            m_IsInitialized = true;
        }
    }

    void map::DrawMap() const
    {
        if (!m_IsInitialized) return;

        for (int i = 0; i < m_MapRows; ++i)
        {
            for (int j = 0; j < m_MapColumns; ++j)
            {
                m_MapSheet->SetFrame(m_Map[i][j]);
                const float posX = 32.f * static_cast<float>(j);
                const float PosY = 32.f * static_cast<float>(i);
                const SDL_FRect tempRec{ posX, PosY, 32, 32};
                m_MapSheet->Draw(tempRec);
            }
        }

        if (!m_Pickups.empty())
        {
            for (const auto& pickup : m_Pickups)
            {
                pickup->Draw();
            }
        }
    }

    void map::SpawnPickup(int column, int row, bool pickUp)
    {
        auto posX = column * 32.f + (pickUp ? 4.f : 12.f);
        auto posY = row * 32.f + (pickUp ? 4.f : 12.f);
        
        m_Pickups.emplace_back(std::make_unique<pickup>(posX, posY, pickUp));
    }

    int map::GetTileData(int column, int row) const
    {
        return m_Map[row][column];
    }
}

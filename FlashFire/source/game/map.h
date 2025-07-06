#pragma once
#include <array>
#include <memory>
#include <string>

namespace FF
{
    class sprite;
    class map
    {
    public:

        void SetTileMap(const std::string& mapTileTexturesPath, const std::string& mapTileDataPath, const int columns, const int rows);
        void CreateTiles(const std::string& mapTileDataPath);

        void DrawMap() const;

        int GetTileData(int column, int row) const;
    
    private:
        std::unique_ptr<sprite> m_MapSheet = nullptr;
        bool m_IsInitialized = false;

        static constexpr int m_MapRows = 31;
        static constexpr int m_MapColumns = 28;
        std::array<std::array<int, m_MapColumns>, m_MapRows> m_Map;
    };
}


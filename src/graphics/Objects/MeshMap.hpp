#pragma once

#include "IGraphic.hpp"

namespace Indie {
    class MeshMap: public IGraphic {
        public:
        MeshMap(std::string path = "EMPTY") {
            _img = LoadImage(path.c_str());
            _mesh = GenMeshCubicmap(_img, { 2.0f, 2.0f, 2.0f });
            _mod = LoadModelFromMesh(_mesh);
            _text = LoadTexture("assets/map/texture_map.png");
            _mod.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _text;
        }
        void draw(void) override { DrawModel(_mod, {-17, 0, -17}, 1.0f, WHITE); }
        void onHover(void) override {}
        void onHoverEnd(void) override {}
        bool isHover(void) override { return false; }
        bool getIs3D(void) override { return true; }
        void onClick(void) override {}
        Rectangle getRect(void) override { return { 0 }; }
        ~MeshMap() {}

        private:
        Image _img;
        Texture2D _text;
        Mesh _mesh;
        Model _mod;
    };
}
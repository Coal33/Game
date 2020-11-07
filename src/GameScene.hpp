#include <Siv3D.hpp>

#include "Define.hpp"

class GameScene : public SceneMgr::Scene {
   private:
   public:
    GameScene(const InitData&);
    void update() override;
    void draw() const override;
};
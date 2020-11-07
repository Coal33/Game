#include <Siv3D.hpp>
using SceneMgr = SceneManager<String>;

class TitleScene : public SceneMgr::Scene {
   private:
   public:
    TitleScene(const InitData&);
    void update() override;
    void draw() const override;
};
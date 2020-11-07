#pragma once
#include <Siv3D.hpp>
#include "Define.hpp"

class TitleScene : public SceneMgr::Scene {
  private:
  public:
	TitleScene(const InitData&);
	void update() override;
	void draw() const override;
};
#pragma once
#include <Siv3D.hpp>
#include "Define.hpp"

class SettingScene : public SceneMgr::Scene {
  private:
  public:
	SettingScene(const InitData&);
	void update() override;
	void draw() const override;
};
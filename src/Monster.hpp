#pragma once
#include <Siv3D.hpp>

#include "Define.hpp"

class Monster {
  private:
	AbilityValue currentAvilityValue;     //能力現在値
	AbilityValue absoluteAvilityValue;    //能力絶対値
	AbilityValue experienceAvilityValue;  //能力経験値
	AbilityValue eigenvalueAvirityValue;  //能力固有値
	int level;                            //レベル
	int experience;                       //経験値
	String feature;                       //特性
	String[4] skill;                      //スキル

  public:
	Monster();
	~Monster();
};
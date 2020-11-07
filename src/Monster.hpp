#pragma once
#include <Siv3D.hpp>

#include "Define.hpp"

class Monster {
   private:
    AbilityValues currentAvilityValues;     //能力現在値
    AbilityValues absoluteAvilityValues;    //能力絶対値
    AbilityValues experienceAvilityValues;  //能力経験値
    AbilityValues eigenvalueAvirityValues;  //能力固有値
    int level;                              //レベル
    int experience;                         //経験値
    String feature;                         //特性
    String skill[4];                        //スキル
    String speciesName;                     //種族名
    String individualName;                  //個体名
   public:
    Monster();
    ~Monster();
};
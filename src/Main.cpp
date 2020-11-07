#include <Siv3D.hpp>

#include "Define.hpp"

void Main() {
    Window::SetTitle(GameName + U" " + GameVersion);
    while(System::Update()) {
    }
}
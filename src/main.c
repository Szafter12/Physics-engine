#include "Engine/Engine.h"

int main(void) {
    Engine engine;

    InitWin(&engine, 800, 600, 60);
    run();

    CloseWindow();
    return 0;
}

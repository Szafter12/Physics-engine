#include "Engine/Engine.h"

int main(void) {
    Engine engine;

    InitWin(&engine, 800, 600, 60);
    run(&engine);

    CloseWindow();
    return 0;
}

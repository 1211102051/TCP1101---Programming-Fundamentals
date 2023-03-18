#pragma once

namespace menu {
    void quit();
    void help();
    void settingMenu(int rows, int columns, int zombiecount);
    void changeSettings(int &rows, int &columns, int &zombiecount);
    void mainMenu();
}

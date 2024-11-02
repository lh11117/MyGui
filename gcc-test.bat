@echo off
g++ src\MyGuiCheckbox.cpp src\MyGuiFont.cpp src\MyGui.cpp src\MyGuiButton.cpp src\MyGuiEntry.cpp src\MyGuiLabel.cpp -shared -o lib.lib -static -I"include" -std=c++20 -DUNICODE -lgdi32
pause
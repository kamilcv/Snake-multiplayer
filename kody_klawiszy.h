#include <time.h>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <sstream>

using namespace std;

string nazwa_klawisza( int klawisz )
{
    string nazwa = "";
    switch( klawisz )
    {
    case -1:
        nazwa = "Nieprzypisano";
        break;
    case 0:
        nazwa = "A";
        break;
    case 1:
        nazwa = "B";
        break;
    case 2:
        nazwa = "C";
        break;
    case 3:
        nazwa = "D";
        break;
    case 4:
        nazwa = "E";
        break;
    case 5:
        nazwa = "F";
        break;
    case 6:
        nazwa = "G";
        break;
    case 7:
        nazwa = "H";
        break;
    case 8:
        nazwa = "I";
        break;
    case 9:
        nazwa = "J";
        break;
    case 10:
        nazwa = "K";
        break;
    case 11:
        nazwa = "L";
        break;
    case 12:
        nazwa = "M";
        break;
    case 13:
        nazwa = "N";
        break;
    case 14:
        nazwa = "O";
        break;
    case 15:
        nazwa = "P";
        break;
    case 16:
        nazwa = "Q";
        break;
    case 17:
        nazwa = "R";
        break;
    case 18:
        nazwa = "S";
        break;
    case 19:
        nazwa = "T";
        break;
    case 20:
        nazwa = "U";
        break;
    case 21:
        nazwa = "V";
        break;
    case 22:
        nazwa = "W";
        break;
    case 23:
        nazwa = "X";
        break;
    case 24:
        nazwa = "Y";
        break;
    case 25:
        nazwa = "Z";
        break;
    case 26:
        nazwa = "Num0";
        break;
    case 27:
        nazwa = "Num1";
        break;
    case 28:
        nazwa = "Num2";
        break;
    case 29:
        nazwa = "Num3";
        break;
    case 30:
        nazwa = "Num4";
        break;
    case 31:
        nazwa = "Num5";
        break;
    case 32:
        nazwa = "Num6";
        break;
    case 33:
        nazwa = "Num7";
        break;
    case 34:
        nazwa = "Num8";
        break;
    case 35:
        nazwa = "Num9";
        break;
    //case 36:
        //nazwa = "Escape";
        //break;
    case 37:
        nazwa = "LControl";
        break;
    case 38:
        nazwa = "LShift";
        break;
    case 39:
        nazwa = "LAlt";
        break;
    //case 40:
        //nazwa = "L System";
        //break;
    case 41:
        nazwa = "RControl";
        break;
    case 42:
        nazwa = "RShift";
        break;
    case 43:
        nazwa = "RAlt";
        break;
    //case 44:
        //nazwa = "R System";
        //break;
    case 45:
        nazwa = "Menu";
        break;
    case 46:
        nazwa = "[";
        break;
    case 47:
        nazwa = "]";
        break;
    case 48:
        nazwa = ";";
        break;
    case 49:
        nazwa = ",";
        break;
    case 50:
        nazwa = ".";
        break;
    case 51:
        nazwa = "'";
        break;
    case 52:
        nazwa = "/";
        break;
    case 53:
        nazwa = "\\";
        break;
    case 54:
        nazwa = "~";
        break;
    case 55:
        nazwa = "=";
        break;
    case 56:
        nazwa = "-";
        break;
    case 57:
        nazwa = "Space";
        break;
    case 58:
        nazwa = "Enter";
        break;
    case 59:
        nazwa = "Backspace";
        break;
    case 60:
        nazwa = "Tab";
        break;
    case 61:
        nazwa = "Page Up";
        break;
    case 62:
        nazwa = "Page Down";
        break;
    case 63:
        nazwa = "End";
        break;
    case 64:
        nazwa = "Home";
        break;
    case 65:
        nazwa = "Insert";
        break;
    case 66:
        nazwa = "Delete";
        break;
    case 67:
        nazwa = "+";
        break;
    case 68:
        nazwa = "-";
        break;
    case 69:
        nazwa = "*";
        break;
    case 70:
        nazwa = "/";
        break;
    case 71:
        nazwa = "L Strz";
        break;
    case 72:
        nazwa = "P Strz";
        break;
    case 73:
        nazwa = "G Strz";
        break;
    case 74:
        nazwa = "D Strz";
        break;
    case 75:
        nazwa = "Numpad0";
        break;
    case 76:
        nazwa = "Numpad1";
        break;
    case 77:
        nazwa = "Numpad2";
        break;
    case 78:
        nazwa = "Numpad3";
        break;
    case 79:
        nazwa = "Numpad4";
        break;
    case 80:
        nazwa = "Numpad5";
        break;
    case 81:
        nazwa = "Numpad6";
        break;
    case 82:
        nazwa = "Numpad7";
        break;
    case 83:
        nazwa = "Numpad8";
        break;
    case 84:
        nazwa = "Numapd9";
        break;
    case 85:
        nazwa = "F1";
        break;
    case 86:
        nazwa = "F2";
        break;
    case 87:
        nazwa = "F3";
        break;
    case 88:
        nazwa = "F4";
        break;
    case 89:
        nazwa = "F5";
        break;
    case 90:
        nazwa = "F6";
        break;
    case 91:
        nazwa = "F7";
        break;
    case 92:
        nazwa = "F8";
        break;
    case 93:
        nazwa = "F9";
        break;
    case 94:
        nazwa = "F10";
        break;
    case 95:
        nazwa = "F11";
        break;
    case 96:
        nazwa = "F12";
        break;
    }
    return nazwa;
}

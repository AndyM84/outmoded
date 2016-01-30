#pragma once

#ifdef _WIN32
#include <Windows.h>

#define OKEY_BACKSPACE VK_BACK //BACKSPACE key
#define OKEY_CLEAR VK_CLEAR //CLEAR key
#define OKEY_ENTER VK_RETURN //ENTER key
#define OKEY_ESCAPE VK_ESCAPE //ESC key
#define OKEY_SPACEBAR VK_SPACE //SPACEBAR
#define OKEY_PAGEUP VK_PRIOR //PAGE UP key
#define OKEY_PAGEDOWN VK_NEXT //PAGE DOWN key
#define OKEY_END VK_END //END key
#define OKEY_HOME VK_HOME //HOME key
#define OKEY_LEFT VK_LEFT //LEFT ARROW key
#define OKEY_UP VK_UP //UP ARROW key
#define OKEY_RIGHT VK_RIGHT //RIGHT ARROW key
#define OKEY_DOWN VK_DOWN //DOWN ARROW key
#define OKEY_DELETE VK_DELETE //DEL key
#define OKEY_0 '0' //0 key
#define OKEY_1 '1' //1 key
#define OKEY_2 '2' //2 key
#define OKEY_3 '3' //3 key
#define OKEY_4 '4' //4 key
#define OKEY_5 '5' //5 key
#define OKEY_6 '6' //6 key
#define OKEY_7 '7' //7 key
#define OKEY_8 '8' //8 key
#define OKEY_9 '9' //9 key
#define OKEY_A 'A' //A key
#define OKEY_B 'B' //B key
#define OKEY_C 'C' //C key
#define OKEY_D 'D' //D key
#define OKEY_E 'E' //E key
#define OKEY_F 'F' //F key
#define OKEY_G 'G' //G key
#define OKEY_H 'H' //H key
#define OKEY_I 'I' //I key
#define OKEY_J 'J' //J key
#define OKEY_K 'K' //K key
#define OKEY_L 'L' //L key
#define OKEY_M 'M' //M key
#define OKEY_N 'N' //N key
#define OKEY_O 'O' //O key
#define OKEY_P 'P' //P key
#define OKEY_Q 'Q' //Q key
#define OKEY_R 'R' //R key
#define OKEY_S 'S' //S key
#define OKEY_T 'T' //T key
#define OKEY_U 'U' //U key
#define OKEY_V 'V' //V key
#define OKEY_W 'W' //W key
#define OKEY_X 'X' //X key
#define OKEY_Y 'Y' //Y key
#define OKEY_Z 'Z' //Z key
#define OKEY_F1 VK_F1 //F1 key
#define OKEY_F2 VK_F2 //F2 key
#define OKEY_F3 VK_F3 //F3 key
#define OKEY_F4 VK_F4 //F4 key
#define OKEY_F5 VK_F5 //F5 key
#define OKEY_F6 VK_F6 //F6 key
#define OKEY_F7 VK_F7 //F7 key
#define OKEY_F8 VK_F8 //F8 key
#define OKEY_F9 VK_F9 //F9 key
#define OKEY_F10 VK_F10 //F10 key
#define OKEY_F11 VK_F11 //F11 key
#define OKEY_F12 VK_F12 //F12 key
#define OKEY_F13 VK_F13 //F13 key
#define OKEY_F14 VK_F14 //F14 key
#define OKEY_F15 VK_F15 //F15 key
#define OKEY_F16 VK_F16 //F16 key
#define OKEY_F17 VK_F17 //F17 key
#define OKEY_F18 VK_F18 //F18 key
#define OKEY_F19 VK_F19 //F19 key
#define OKEY_F20 VK_F20 //F20 key
#define OKEY_F21 VK_F21 //F21 key
#define OKEY_F22 VK_F22 //F22 key
#define OKEY_F23 VK_F23 //F23 key
#define OKEY_F24 VK_F24 //F24 key
#else
#include <ncurses.h>

#define OKEY_BACKSPACE KEY_BACKSPACE //BACKSPACE key
#define OKEY_CLEAR KEY_CLEAR //CLEAR key
#define OKEY_ENTER 10 //ENTER key
#define OKEY_ESCAPE 27 //ESC key
#define OKEY_SPACEBAR ' ' //SPACEBAR
#define OKEY_PAGEUP KEY_PPAGE //PAGE UP key
#define OKEY_PAGEDOWN KEY_NPAGE //PAGE DOWN key
#define OKEY_END KEY_END //END key
#define OKEY_HOME KEY_HOME //HOME key
#define OKEY_LEFT KEY_LEFT //LEFT ARROW key
#define OKEY_UP KEY_UP //UP ARROW key
#define OKEY_RIGHT KEY_RIGHT //RIGHT ARROW key
#define OKEY_DOWN KEY_DOWN //DOWN ARROW key
#define OKEY_DELETE KEY_DL //DEL key
#define OKEY_0 '0' //0 key
#define OKEY_1 '1' //1 key
#define OKEY_2 '2' //2 key
#define OKEY_3 '3' //3 key
#define OKEY_4 '4' //4 key
#define OKEY_5 '5' //5 key
#define OKEY_6 '6' //6 key
#define OKEY_7 '7' //7 key
#define OKEY_8 '8' //8 key
#define OKEY_9 '9' //9 key
#define OKEY_A 'A' //A key
#define OKEY_B 'B' //B key
#define OKEY_C 'C' //C key
#define OKEY_D 'D' //D key
#define OKEY_E 'E' //E key
#define OKEY_F 'F' //F key
#define OKEY_G 'G' //G key
#define OKEY_H 'H' //H key
#define OKEY_I 'I' //I key
#define OKEY_J 'J' //J key
#define OKEY_K 'K' //K key
#define OKEY_L 'L' //L key
#define OKEY_M 'M' //M key
#define OKEY_N 'N' //N key
#define OKEY_O 'O' //O key
#define OKEY_P 'P' //P key
#define OKEY_Q 'Q' //Q key
#define OKEY_R 'R' //R key
#define OKEY_S 'S' //S key
#define OKEY_T 'T' //T key
#define OKEY_U 'U' //U key
#define OKEY_V 'V' //V key
#define OKEY_W 'W' //W key
#define OKEY_X 'X' //X key
#define OKEY_Y 'Y' //Y key
#define OKEY_Z 'Z' //Z key
#define OKEY_F1 KEY_F1 //F1 key
#define OKEY_F2 KEY_F2 //F2 key
#define OKEY_F3 KEY_F3 //F3 key
#define OKEY_F4 KEY_F4 //F4 key
#define OKEY_F5 KEY_F5 //F5 key
#define OKEY_F6 KEY_F6 //F6 key
#define OKEY_F7 KEY_F7 //F7 key
#define OKEY_F8 KEY_F8 //F8 key
#define OKEY_F9 KEY_F9 //F9 key
#define OKEY_F10 KEY_F10 //F10 key
#define OKEY_F11 KEY_F11 //F11 key
#define OKEY_F12 KEY_F12 //F12 key
#define OKEY_F13 KEY_F13 //F13 key
#define OKEY_F14 KEY_F14 //F14 key
#define OKEY_F15 KEY_F15 //F15 key
#define OKEY_F16 KEY_F16 //F16 key
#define OKEY_F17 KEY_F17 //F17 key
#define OKEY_F18 KEY_F18 //F18 key
#define OKEY_F19 KEY_F19 //F19 key
#define OKEY_F20 KEY_F20 //F20 key
#define OKEY_F21 KEY_F21 //F21 key
#define OKEY_F22 KEY_F22 //F22 key
#define OKEY_F23 KEY_F23 //F23 key
#define OKEY_F24 KEY_F24 //F24 key
#endif

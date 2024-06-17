#ifndef CTOOL_H
#define CTOOL_H
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

void paintWindow(int startX,int startY,int width, int height);

void gotoxy(int x,int y);

void glb_string(int maxLen,int inputType,int ips,char str[]);

int getkey();

#endif

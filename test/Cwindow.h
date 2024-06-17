#ifndef CWINDOW_H
#define CWINDOW_H
#define LABEL 1
#define EDIT 2
#define BUTTON 3

typedef struct label_t
{
	int startx;
	int starty;
	int width;
	int height;
	char content[20];
};

typedef struct edit_t
{
	int startx;
	int starty;
	int width;
	int height;
	char content[20];
	int inputType;
	int ips;
	int maxLen;
};

typedef struct button_t
{
	int startx;
	int starty;
	int width;
	int height;
	char content[20];
};

typedef struct control_t
{
	int startx;
	int starty;
	int width;
	int height;
	int maxLen;
	int inputType;
	int ips;
	int ctrlType;
	char content[20];
}CONTROL_T;

typedef struct win_t
{
	int startx;
	int starty;
	int width;
	int height;
	CONTROL_T ctrlArr[20];
	int ctrlCount;
	int foucsIndex;
}WIN_T;

int addControl(CONTROL_T ctrl,CONTROL_T ctrlArr[20],int ctrlCount);

void showWindow(WIN_T win);

WIN_T winRun(WIN_T win);

void editKeyListen(CONTROL_T ctrl,char ch,char content[]);

#endif

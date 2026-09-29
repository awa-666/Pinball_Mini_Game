#include<stdio.h>
#include<easyx.h>
#include<conio.h>
int main() {
	while (1) {
		char c;
		printf("开始请按1：");
		c = _getch();
		if (c == 1) {
			initgraph(800, 600);
			setorigin(400, 300);
			setaspectratio(1, -1);
			setbkcolor(RGB(164, 225, 202));
			cleardevice();
			getchar();
			closegraph();
		}
		else {
			printf("游戏结束！\n");
			return 0;
		}
	}
}
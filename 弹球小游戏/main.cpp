#include<stdio.h>
#include<easyx.h>
#include<conio.h>
//绘制挡板函数
void board(int x){
	if (x < -250)
		x = -250;
	if (x > 250)
		x = 250;
	solidrectangle(x - 150, -280, x + 150, 280);
}
int main() {
	while (1) {
		char c;
		//绘制窗体
		initgraph(800, 600);
		setorigin(400, 300);
		setaspectratio(1, -1);
		setbkcolor(RGB(164, 225, 202));
		cleardevice();
		//绘制球和挡板的初始状态
		setfillcolor(WHITE);
		solidcircle(0, 0, 50);
		solidrectangle(-150, -280, 150, -300);
		//判断游戏开始
		printf("开始请按1：");
		c = getchar();
		getchar();		//吸收换行符
		if (c == '1') {
			printf("游戏没结束！\n");
			getchar();
		}
		else {
			printf("游戏结束！\n");
			closegraph();
			return 0;
		}
	}
}
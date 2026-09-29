#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<math.h>
#define Speed 5
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
			int x = 0, y = 0, k = 0,num = 0;
			int dx = Speed;
			int dy = Speed;
			while (1) {
				if (y < -300) {				//重置时随机位置
					x = rand() % 401 - 200;
					y = rand() % 301 - 150;
					int j;
					j = rand() % 4 + 1;
					switch (j) {			//重置时随机方向
						case 1:
							dx = Speed;
							dy = Speed;
							break;
						case 2:
							dx = Speed;
							dy = -Speed;
							break;
						case 3:
							dx = -Speed;
							dy = Speed;
							break;
						case 4:
							dx = -Speed;
							dy = -Speed;
					}
				}
				cleardevice();
				if (x <= -350 || x >= 350){
					dx = -dx;
				}
				if (y >= 250) {
					dy = -dy;
				}
				if (x >= k - 150 && x <= k + 150 && y <= -230 && num > 12) {
					dy = -dy;
					num = 0;
				}
				num++;
				solidcircle(x, y, 50);
				int c = 0;
				if (_kbhit() != 0) {
					c = _getch();
					switch (c) {
						case 'a':
							k -= 15;
							break;
						case 'd':
							k += 15;
					}
				}
				if (k < -250)
					k = -250;
				if (k > 250)
					k = 250;
				solidrectangle(k - 150, -280, k + 150, -300);

				x += dx;
				y += dy;
				Sleep(40);		//动画为25帧
			}
		}
		else {
			printf("游戏结束！\n");
			closegraph();
			return 0;
		}
	}
}
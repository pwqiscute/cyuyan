#include"contact.h"
void menu() {
	printf("----------1.add     2.del---------\n");
	printf("----------3.search  4.modify------\n");
	printf("----------5.show    6.sort--------\n");
	printf("----------0.exit---------\n");
}
void tect() {
	menu();
	contact con;
	Initialize(&con);//--初始化
	int input = 0;
	do {
		
	scanf_s("%d", &input);
		switch (input) {
		case 1:
			Add(&con);
			break;
		case 2:
			del(&con);
			break;
		case 3:
			search(&con);
			break;
		case 4:
		modify(&con);
		break;
		case 5:
			show(&con);
			break;
		case 6:
			sort(&con);
			break;
		case 0:
			DestroyContact(&con);
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}


int main() {
	tect();

	return 0;
}
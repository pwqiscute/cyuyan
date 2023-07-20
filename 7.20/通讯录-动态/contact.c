#include"contact.h"
//-----------------初始化
//void Initialize(contact* con) {
//	assert(con);
//	con->count = 0;
//	memset(con->date, 0, sizeof(con->date));
//}
// void Initialize(contact* con) {
//----------------------------------------动态
void Initialize(contact* con) {
	assert(con);
	con->capacity = 3;
	malloc(con->capacity * sizeof(people));
	if (malloc(con->capacity * sizeof(people) != NULL)) {
		con->date = (people*)malloc(con->capacity * sizeof(people));
		memset(con->date, 0, con->capacity * sizeof(people));
		con->count = 0;
	}
	else {
		printf("内容放不下\n");
		return;
	}
}
//------------------------查找联系人
int check(contact* con, char name[20]) {
	for (int i = 0; i < con->count; i++) {
		if (0 == strcmp(con->date[i].name, name)) {
			return i;
		}
	}
	return -1;
}
//---------------------------------用名字比较
int name_cmp(const void* e1, const void* e2) {
	return strcmp(((people*)e1)->name, ((people*)e2)->name);
}
//------------------------------------用年龄来比较
int age_cmp(const void* e1, const void* e2) {
return (((people*)e1)->age-((people*)e2)->age);
}
//---------------------------------用电话来比较
 int tele_cmp(const void* e1, const void* e2) {
return strcmp(((people*)e1)->tele, ((people*)e2)->tele);
}
//--------------------------------字节交换
void exchance(people* e1, people* e2,size_t num) {
	assert(e1 && e2);
	char tep = 0;
	while (num--) {
		tep = *(char*)e1;
		*(char*)e1 = *(char*)e2;
		*(char*)e2 = tep;
		e1 = (char*)e1 + 1;
		e2 = (char*)e2 + 1;
	}
}
//-----------------------------------展示
void show(const contact* con) {
	assert(con);
	printf("%20s\t%5s\t%3s\t%20s", "名字", "年龄", "性别", "电话");
	printf("\n");
	for (int i = 0; i < con->count; i++) {
		printf("%20s\t%5d\t%3s\t%20s\n", con->date[i].name, con->date[i].age, con->date[i].sex, con->date[i].tele);
	}
}
void DestroyContact(contact* con) {
	assert(con);
	free(con->date);
	con->date = NULL;
}
//----------------------------------------加联系人
void Add(contact* con) {
	assert(con);
	if (con->count == con->capacity) {
		con->capacity += 2;
		people* p=(people*) realloc(con->date, con->capacity * sizeof(people));
		if (p != NULL) {
			con->date = p;
		}
		else {
			printf("内存不够\n");
			return;
		}
	}
	printf("你要加的联系人的名字是：\n");
	scanf_s("%s", con->date[con->count].name);
	printf("你要加的联系人的年龄是：\n");
	scanf_s("%d", &con->date[con->count].age);
	printf("你要加的联系人的性别是：\n");
	scanf_s("%3s", &con->date[con->count].sex);
	printf("你要加的联系人的电话是：\n");
	scanf_s("%20s", &con->date[con->count].tele);
	con->count++;
	printf("添加成功\n");
}
//--------------------------------------------删除联系人
void del(contact* con) {
	if (con->count == 0) {
		printf("无联系人，无法删除\n");
		return;
	}
	
	char name[20] = { 0 };
	printf("请输入你要删除的联系人的名字\n");
	scanf_s("%20s", &name);
	int ret = check(con, name);
	if (ret == -1) {
		printf("查无此人\n");
		return;
	}
	int i = 0;
	for (int i = ret; i < con->count-1; i++) {
		con->date[i] = con->date[i + 1];
	}
	con->count--;
	printf("删除成功\n");
}
//------------------------查找联系人
void search(const contact* con) {
	assert(con);
	if (con->count == 0) {
		return;
	}
	else {
		char name[20] = { 0 };
		printf("请输入你要查找的人的名字：\n");
		scanf_s("%s", name);
		int ret = check(con, name);
		if (ret == -1) {
			printf("查无此人\n");
			return;
		}
		printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	}
}
//----------------------------修改
void modify(contact* con) {
	assert(con);
	if (con->count == 0) {
		printf("没东西修改\n");
		return;
	}
	char name[20] = { 0 };
	printf("请输入你要修改人的名字\n");
	scanf_s("%s", name);
	int ret = check(con, name);
	if (ret == -1) {
		printf("联系人中没有此人\n");
		return;
	}
	printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	printf("你要改的联系人的名字是：\n");
	scanf_s("%s", con->date[ret].name);
	printf("你要改的联系人的年龄是：\n");
	scanf_s("%d", &con->date[ret].age);
	printf("你要改的联系人的性别是：\n");
	scanf_s("%3s", &con->date[ret].sex);
	printf("你要改的联系人的电话是：\n");
	scanf_s("%20s", &con->date[ret].tele);
	printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	printf("修改成功\n");
}
//------------------------------排序
void sort(contact* con) {
	int sz = sizeof(people);
	int a = 0;
	do {
		printf("请用一种你喜欢的方法来排序\t1----名字\t2-----年龄\t3--------电话\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			qsort(con->date, con->count, sz, name_cmp);
			break;
		case 2:
			qsort(con->date, con->count, sz, age_cmp);
			break;
		case 3:
			qsort(con->date, con->count, sz, tele_cmp);
			break;
		default:
			printf("输入错误！\n");
		}
	} while (a != 1 || a != 2 || a != 3);
	printf("排序成功\n");
}  
#include"contact.h"
//-----------------��ʼ��
//void Initialize(contact* con) {
//	assert(con);
//	con->count = 0;
//	memset(con->date, 0, sizeof(con->date));
//}
// void Initialize(contact* con) {
//----------------------------------------��̬
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
		printf("���ݷŲ���\n");
		return;
	}
}
//------------------------������ϵ��
int check(contact* con, char name[20]) {
	for (int i = 0; i < con->count; i++) {
		if (0 == strcmp(con->date[i].name, name)) {
			return i;
		}
	}
	return -1;
}
//---------------------------------�����ֱȽ�
int name_cmp(const void* e1, const void* e2) {
	return strcmp(((people*)e1)->name, ((people*)e2)->name);
}
//------------------------------------���������Ƚ�
int age_cmp(const void* e1, const void* e2) {
return (((people*)e1)->age-((people*)e2)->age);
}
//---------------------------------�õ绰���Ƚ�
 int tele_cmp(const void* e1, const void* e2) {
return strcmp(((people*)e1)->tele, ((people*)e2)->tele);
}
//--------------------------------�ֽڽ���
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
//-----------------------------------չʾ
void show(const contact* con) {
	assert(con);
	printf("%20s\t%5s\t%3s\t%20s", "����", "����", "�Ա�", "�绰");
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
//----------------------------------------����ϵ��
void Add(contact* con) {
	assert(con);
	if (con->count == con->capacity) {
		con->capacity += 2;
		people* p=(people*) realloc(con->date, con->capacity * sizeof(people));
		if (p != NULL) {
			con->date = p;
		}
		else {
			printf("�ڴ治��\n");
			return;
		}
	}
	printf("��Ҫ�ӵ���ϵ�˵������ǣ�\n");
	scanf_s("%s", con->date[con->count].name);
	printf("��Ҫ�ӵ���ϵ�˵������ǣ�\n");
	scanf_s("%d", &con->date[con->count].age);
	printf("��Ҫ�ӵ���ϵ�˵��Ա��ǣ�\n");
	scanf_s("%3s", &con->date[con->count].sex);
	printf("��Ҫ�ӵ���ϵ�˵ĵ绰�ǣ�\n");
	scanf_s("%20s", &con->date[con->count].tele);
	con->count++;
	printf("��ӳɹ�\n");
}
//--------------------------------------------ɾ����ϵ��
void del(contact* con) {
	if (con->count == 0) {
		printf("����ϵ�ˣ��޷�ɾ��\n");
		return;
	}
	
	char name[20] = { 0 };
	printf("��������Ҫɾ������ϵ�˵�����\n");
	scanf_s("%20s", &name);
	int ret = check(con, name);
	if (ret == -1) {
		printf("���޴���\n");
		return;
	}
	int i = 0;
	for (int i = ret; i < con->count-1; i++) {
		con->date[i] = con->date[i + 1];
	}
	con->count--;
	printf("ɾ���ɹ�\n");
}
//------------------------������ϵ��
void search(const contact* con) {
	assert(con);
	if (con->count == 0) {
		return;
	}
	else {
		char name[20] = { 0 };
		printf("��������Ҫ���ҵ��˵����֣�\n");
		scanf_s("%s", name);
		int ret = check(con, name);
		if (ret == -1) {
			printf("���޴���\n");
			return;
		}
		printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	}
}
//----------------------------�޸�
void modify(contact* con) {
	assert(con);
	if (con->count == 0) {
		printf("û�����޸�\n");
		return;
	}
	char name[20] = { 0 };
	printf("��������Ҫ�޸��˵�����\n");
	scanf_s("%s", name);
	int ret = check(con, name);
	if (ret == -1) {
		printf("��ϵ����û�д���\n");
		return;
	}
	printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	printf("��Ҫ�ĵ���ϵ�˵������ǣ�\n");
	scanf_s("%s", con->date[ret].name);
	printf("��Ҫ�ĵ���ϵ�˵������ǣ�\n");
	scanf_s("%d", &con->date[ret].age);
	printf("��Ҫ�ĵ���ϵ�˵��Ա��ǣ�\n");
	scanf_s("%3s", &con->date[ret].sex);
	printf("��Ҫ�ĵ���ϵ�˵ĵ绰�ǣ�\n");
	scanf_s("%20s", &con->date[ret].tele);
	printf(" %20s\t %5d\t %3s\t %20s\n", con->date[ret].name, con->date[ret].age, con->date[ret].sex, con->date[ret].tele);
	printf("�޸ĳɹ�\n");
}
//------------------------------����
void sort(contact* con) {
	int sz = sizeof(people);
	int a = 0;
	do {
		printf("����һ����ϲ���ķ���������\t1----����\t2-----����\t3--------�绰\n");
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
			printf("�������\n");
		}
	} while (a != 1 || a != 2 || a != 3);
	printf("����ɹ�\n");
}  
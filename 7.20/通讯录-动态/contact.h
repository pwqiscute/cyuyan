#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
typedef struct people {
	char name[20];
	int age;
	char sex[3];
	char tele[20];
}people;
//-----------------��̬
//typedef struct contact {
//	struct people date[100];
//	int count;
//}contact;
//-------------------��̬
typedef struct contact {
	people* date;
	int count;
	int capacity;//---��������count==capacityʱ���ݣ�
}contact;
void Initialize(contact* con);
void show(const contact* con);
void Add(contact* con);
void del(contact* con);
void search(const contact* con);
void sort(contact* con);
void modify(contact* con);
void DestroyContact(contact* con);
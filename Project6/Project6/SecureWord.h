#pragma once
#include<string>
#include<iostream>
using namespace std;
class SecureWord
{
public:
	SecureWord(string str, string encrypt, string keyWord);
	string decode();
	void code();
	string getword();
	~SecureWord();
private:
	//���������
	string word; 
	//  ��־�Ƿ���� false �򱣴��Ϊ����
	// true�� ����
	bool encryption ;
	// ��Կ
	int key;
};


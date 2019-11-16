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
	//保存的数据
	string word; 
	//  标志是否加密 false 则保存的为明文
	// true是 密文
	bool encryption ;
	// 密钥
	int key;
};


#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"SecureWord.h"
#include <string>
using namespace std;

vector<SecureWord> fileReading(ifstream & stream) {
	// 读取的每一行
	string line;
	vector<SecureWord> result;
	while (getline(stream, line))
	{
		istringstream m(line);
		string word;
		string encrypt;
		string key;

		//进行单词分解
		// 按照题目要求 第一个是字符串
		// 第二个 是否加密 第三个是 密钥 key
		
		m >> word;
		m >> encrypt;
		m >> key;
		// 在构造函数中自动加密
		result.push_back(SecureWord(word, encrypt, key));
	}
	return result;
}
int main()
{
	ifstream in("input.txt");

	//得到相关数组
	vector<SecureWord> result = fileReading(in);

    //保存用户输入的字符串
	string word; 
	cout << "请您输入要查询的字符串 \n";
	cin >> word;
	bool finded = false;// 标志是否找的 相对应的字符串
	cout << "一下为所有加密后的数字\n";
	for (int i=0;i<result.size();++i)
	{
		cout << result[i].getword()<<endl;
	}
	cout << "以下为所有的解密后的数字 \n";
	for (int i=0;i<result.size();++i)
	{
		cout << result[i].decode()<<endl;
	}
	cout << "\n";
	for (int i=0 ;i<result.size();++i)
	{
		// 返回解密的字符串
		string deCodeWord = result[i].decode();
		//cout << deCodeWord << endl;
		if (deCodeWord==word)
		{
			finded = true;
			cout << "您输入的单词在数组中存在";
		}
	}
	if (!finded)
	{
		cout << "您输入的单词在数组中不存在";
	}
	system("pause");
	
}

#include "SecureWord.h"

SecureWord::SecureWord(string str, string encrypt, string keyWord)
{
	// stoi�ǽ��ַ���ת�����ֵĺ���
	word = str;
	if (stoi(encrypt)== 1)
	{
		encryption = true; //��־�Ѿ���������
	}
	else
	{
		encryption = false;//����
	}
	// ��������ַ��� ת������
	this->key = stoi(keyWord);

	//ÿ������  �ַ�����Ҫ���м���
	if (!encryption)
	{
		code();
		encryption = true;
	}
	
}

string SecureWord::decode()
{
	// ���ĲŽ���
	if (encryption)
	{
		string str = word;
		int num;
		num = 26 - key;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{

				str[i] = ((str[i] - 'A') + num) % 26 + 'A';

			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{

				str[i] = ((str[i] - 'a') + num) % 26 + 'a';

			}
		}
		return str;
	}
	else
	{
		return word;
	}
}

void SecureWord::code()
{
		
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] <= 'z'&&word[i] >= 'a')
			{

				word[i]= (char)((word[i] - 'a' + key) % 26 + 'a');

			}
			else if (word[i] <= 'Z'&&word[i] >= 'A')
			{

				word[i]= (char)((word[i] - 'A' + key) % 26 + 'A');

			}
		}
		this->encryption = true;
}

string SecureWord::getword()
{
	return word;
}


SecureWord::~SecureWord()
{
}

// week12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int max(vector<int>& v)
{
	int max;
	int max_num;
	for (int i = 0; i < v.size()-1; i++)
	{
		if (v[i] >= v[i + 1])
		{
			max = v[i];
			max_num = i;
		}
		else
		{
			max = v[i + 1];
			max_num = i + 1;
		}
	}
	return max_num;
}
int main()
{
	try
	{
		int num;
		vector<string>dic;
		vector<string>suffix;
		vector<int>suffix_num;
		cout << "how many letters:";
		cin >> num;
		fstream dictionary("dictionary.txt");
		if (!dictionary)
		{//如果没有成功
			throw runtime_error("file cannot open!\n");
			return -1;
		}
		else
		{
			string word;
			while (!dictionary.eof())
			{
				getline(dictionary, word);
				dic.push_back(word);
			}
		}
		for (int i = 0; i < dic.size(); i++)
		{
			if (dic[i].size() >= num)
			{
				string temp_suffix = dic[i].substr(dic[i].size() - num, dic[i].size());
				if (suffix.size() == 0)
				{
					suffix.push_back(temp_suffix);
					suffix_num.push_back(1);
				}
				else
				{
					for (int j = 0; j <= suffix.size(); j++)
					{
						if (j == suffix.size())
						{
							suffix.push_back(temp_suffix);
							suffix_num.push_back(1);
							break;
						}
						if (suffix[j] == temp_suffix)//若已存在
						{
							suffix_num[j] += 1;
							break;
						}
					}
				}
			}
		}
		cout << suffix.size();
		for (int i = 0; i < 10; i++)
		{
			int num1 = max(suffix_num);
			cout << suffix[max(suffix_num)] << suffix_num[max(suffix_num)] << endl;
			suffix_num[(max(suffix_num))] = 0;
		}
		return 0;
	}
	catch (runtime_error& e)
	{
		cerr << e.what();
		return -1;
	}
	catch (...)
	{
		cerr << "something wrong!\n";
		return -1;
	}
}


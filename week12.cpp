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
	int max_num;
	int max = v[0];
	for (int i = 1; i < v.size()-1; i++){
		if (v[i] >= max){
			max_num = i;
			max = v[i];
		}
	}
	return max_num;
}

void Suffix(const vector<string>& dic,vector<string>&suffix, vector<int>&suffix_num, int num)
{
	for (int i = 0; i < dic.size(); i++) {
		if (dic[i].size() >= num) {
			string temp_suffix = dic[i].substr(dic[i].size() - num, dic[i].size());
			if (suffix.size() == 0) {
				suffix.push_back(temp_suffix);
				suffix_num.push_back(1);
			}
			else {
				for (int j = 0; j <= suffix.size(); j++) {
					if (j == suffix.size()) {
						suffix.push_back(temp_suffix);
						suffix_num.push_back(1);
						break;
					}
					if (suffix[j] == temp_suffix) {//若已存在
						suffix_num[j] += 1;
						break;
					}
				}
			}
		}
	}
}
//功能一：排名前十的单词
void Top_ten(const vector<string>&dic)
{
	int num;
	vector<string>suffix;
	vector<int>suffix_num;
	cout << "how many letters:";
	cin >> num;
	Suffix(dic, suffix, suffix_num, num);
	for (int i = 0; i < 10; i++){
		int num1 = max(suffix_num);
		cout << suffix[num1] << suffix_num[num1] << endl;
		suffix_num[num1] = 0;
	}
}
//功能二：
void query_suffix(const vector<string>& dic)
{

}
int main()
{
	try{
		vector<string>dic;
		fstream dictionary("dictionary.txt");
		if (!dictionary) {//如果没有成功
			throw runtime_error("file cannot open!\n");
			return -1;
		}
		else {
			string word;
			while (!dictionary.eof()) {
				getline(dictionary, word);
				dic.push_back(word);
			}
		}
		Top_ten(dic);
	}
	catch (runtime_error& e){
		cerr << e.what();
		return -1;
	}
	catch (...){
		cerr << "something wrong!\n";
		return -1;
	}
}



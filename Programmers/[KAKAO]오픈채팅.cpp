#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {

	//id�� key�� �ϰ�, name�� value�� �ϴ� map
	unordered_map <string, string> idmap;

	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it) {
		stringstream ss(*it);	//�������� �����ϱ� ����.
		string cmd, id, name;
	
		ss >> cmd;	//�������� �������� ������� �Է�
		
		if (cmd.compare("Enter") == 0) {
			ss >> id >> name;
			idmap[id] = name;
		}
		else if (cmd.compare("Change") == 0) {
			ss >> id >> name;
			idmap[id] = name;
		}
	}

	vector<string> ans;
	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it) {
		stringstream ss(*it);
		string cmd, id;

		ss >> cmd;
		if (cmd.compare("Enter")==0) {
			ss >> id;
			ans.push_back(idmap[id] + "���� ���Խ��ϴ�.");
		}
		else if (cmd.compare("Leave") == 0) {
			ss >> id;
			ans.push_back(idmap[id] + "���� �������ϴ�.");
		}
	}

	return ans;
}

int main() {
	vector<string> str = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
	vector<string> ans = solution(str);

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;

	return 0;
}


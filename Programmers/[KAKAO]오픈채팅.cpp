#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {

	//id를 key로 하고, name을 value로 하는 map
	unordered_map <string, string> idmap;

	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it) {
		stringstream ss(*it);	//공백으로 구분하기 위함.
		string cmd, id, name;
	
		ss >> cmd;	//공백으로 나뉘어진 순서대로 입력
		
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
			ans.push_back(idmap[id] + "님이 들어왔습니다.");
		}
		else if (cmd.compare("Leave") == 0) {
			ss >> id;
			ans.push_back(idmap[id] + "님이 나갔습니다.");
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


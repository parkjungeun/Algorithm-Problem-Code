#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution1(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> name;

	for (int i = 0; i < completion.size(); ++i) {
		if (name.find(completion[i]) == name.end())
			name.insert(make_pair(completion[i], 1));
		else
			name[completion[i]]++;
	}

	for (int i = 0; i <participant.size(); ++i) {
		if (name.find(participant[i]) == name.end())
			return participant[i];
		else {
			if ((--name[participant[i]]) < 0)
				return participant[i];
		}
	}
}

string solution2(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); ++i) {
		if (participant[i] != completion[i])
			return participant[i];
	}
	return participant[participant.size() - 1];
}
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int N, M;
//	cin >> N >> M;
//	
//	map<string, int> idMap;
//	string name;
//	for (int i = 0; i < N; ++i) {
//		cin >> name;
//		idMap[name] = 1;
//	}
//
//	vector<string> ans;
//	for (int i = 0; i < M; ++i) {
//		cin >> name;
//		if (idMap.find(name) != idMap.end())
//			ans.push_back(name);
//	}
//
//	sort(ans.begin(), ans.end());
//
//	cout << ans.size() << '\n';
//	for (int i = 0; i < ans.size(); ++i)
//		cout << ans[i] << '\n';
//	return 0;
//}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;

	vector<string> v(N);
	string name;
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<string> ans;
	for (int i = 0; i < M; ++i) {
		cin >> name;
		//찾았을 때, true를 반환
		if (binary_search(v.begin(), v.end(), name))
			ans.push_back(name);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
	return 0;
}

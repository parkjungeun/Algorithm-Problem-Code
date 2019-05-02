//https://programmers.co.kr/learn/courses/30/lessons/42583
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, curWeight = 0, finishTruck = 0;
	int sz = truck_weights.size(), idx = 0;
	vector<int> curPosition;

	while (finishTruck != sz) {

		if (idx < sz && curWeight + truck_weights[idx] <= weight) {
			curPosition.push_back(0);	//���� Ʈ���� �÷��� �� �����̸�, �ø���
			curWeight += truck_weights[idx];
			idx++;
		}
		
		//1�ʾ� ���� �� ����, 1�̵� 
		for (int i = finishTruck; i < curPosition.size(); ++i) {
			curPosition[i]++;
		}

		for (int i = finishTruck; i < curPosition.size(); ++i) {
			if (curPosition[i] == bridge_length) {
				curWeight -= truck_weights[i];
				finishTruck++;
			}
		}
		answer++;
	}
	return answer + 1;
}

int main() {
	cout << solution(2, 10, { 7,4,5,6 }) << endl;
	cout << solution(100, 100, { 10 }) << endl;
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
	return 0;
}
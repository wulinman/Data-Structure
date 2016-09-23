#include <iostream>
using namespace std;
#include <stack>

int main() {
	
	string s;
	bool flag;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> front;
		stack<char>	last;
		flag = 1;
		cin >> s; 
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
				front.push(s[j]);
			}
		}
	//	cout << front.size();
		for (int j = s.length()-1; j >= 0; j--) {
			if (s[j] == '}'|| s[j] == ']' || s[j] == ')') {
				last.push(s[j]);
			}
		}
	//	cout << last.size();
		if (front.size() != last.size()) flag = 0;
		if (front.size() == last.size() && front.size() == 0) flag = 1;
		//cout << flag << endl;
		//cout << front.top();
		else if (front.size() == last.size() && front.size() != 0) {
			while (!front.empty()) {
				if (!((front.top() == '[' && last.top() == ']') || (front.top() == '{' && last.top() == '}') || (front.top() == '(' && last.top() == ')'))) {
					flag = 0;
					break;
				}
				front.pop();
				last.pop();
				
			}
		}
		
		if (flag == 0) cout << "No" << endl;
		else cout << "Yes" << endl;
		
		
	}
}

#include <map>
#include <string>
#include <iostream>

using namespace std;
int main()
{
	map<string, int> m {
		{"one", 1},
		{"two", 2},
		{"three", 3}
	};
	cout << m.size() << endl;
	return 0;
}


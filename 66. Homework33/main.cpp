#include <iostream>
using namespace std;

class ReversibleString
{
public:
	ReversibleString()
	{

	}

	ReversibleString(string s)
	{
		_reversibleString = s;
	}

	void Reverse()
	{
		Reverse(_reversibleString, _reversibleString.length() - 1, 0);
	}

	string ToString() const
	{
		return _reversibleString;
	}
private:
	string _reversibleString;

	void Reverse(string& greet, int n, int i) {

		if (n <= i) { return; }

		swap(greet[i], greet[n]);
		Reverse(greet, n - 1, i + 1);

	}
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}

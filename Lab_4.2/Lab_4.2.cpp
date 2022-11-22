#include <iostream>
#include <string>
#include <fstream>


using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

void menu() {
	string func[7] = { "File format", "File name", "File path", "File disk", "File rename", "File copy", "Exit" };
	cout << "+---------------+\n";
	for (int i = 0; i < 7; i++) {
		cout << "|" << i + 1 << ". " << func[i] << "\t|" << "\n";
		if (i != 6) {
			cout << "|---------------|\n";
		}
	}
	cout << "+---------------+\n";
	cout << "\nEnter the action number: ";
}

bool check_path(const string str) {
	if (str.find('.') == str.npos)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void cut_off_quotes(string& str) {
	if (str[0] == '\'' || str[0] == '"')
	{
		str = str.substr(1, str.length());
	}

	if (str[str.length() - 1] == '\'' || str[str.length() - 1] == '"')
	{
		str = str.substr(0, str.length() - 1);
	}
}

void replace_slash(string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '/')
		{
			str[i] = '\\';
		}
	}
}

string file_format(const string str) {
	size_t str_len = str.length(), dot = str.rfind('.');
	string f_format;

	f_format = str.substr(dot + 1, str_len - dot - 1);

	return f_format;
}

string file_name(const string str) {
	size_t str_len = str.length(), dot = str.rfind('.'), r_slh = str.rfind('\\');
	string f_name;

	f_name = str.substr(r_slh + 1, dot - r_slh - 1);

	return f_name;
}

string file_path(const string str) {
	size_t str_len = str.length(), l_slh = str.find('\\'), r_slh = str.rfind('\\');
	string f_path;

	f_path = str.substr(l_slh + 1, r_slh - l_slh - 1);

	return f_path;
}

char file_disk(const string str) {
	return str[0];
}

bool file_rename(string& str, const string new_name) {
	size_t str_len = str.length(), r_slh = str.rfind('\\'), dot = str.rfind('.');
	string f_rename;

	str = str.substr(0, r_slh + 1) + new_name + str.substr(dot, str_len - dot);

	return true;
}

string file_name_copy(const string str) {
	size_t str_len = str.length(), dot = str.rfind('.');
	string copy_name;

	copy_name = str.substr(0, dot) + "_copy" + str.substr(dot, str.length() - dot);

	return copy_name;
}

bool file_copy(const string str) {
	string copy_name = file_name_copy(str);
	ifstream in(str, ios::in | ios::binary);
	ofstream out(copy_name, ios::in | ios::trunc | ios::binary);
	char buf = '\0';

	if (!in) {
		cout << "\x1B[31m\nFile \"" << str.substr(str.rfind('\\') + 1, str.length() - str.rfind('\\')) << "\" doesn't exist\n\n\033[0m";;
		return false;
	}
	if (!out) {
		cout << "\x1B[31m\nFailed to create file \"" << copy_name << "\"\n\n\033[0m";
		return false;
	}

	while (in) {
		in.get(buf);
		if (in)
		{
			out.put(buf);
		}
	}

	in.close();
	out.close();
	return true;
}

int main() {
	int choise = 0;
	string str, new_name;
	bool result = false;
	while (true)
	{
		menu();
		cin >> choise;
		switch (choise)
		{
		case 1: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			if (check_path(str))
			{
				cout << "\nFile format is \"\x1B[32m" << file_format(str) << "\033[0m\"\n\n";
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 2: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			if (check_path(str))
			{
				cout << "\nFile name is \"\x1B[32m" << file_name(str) << "\033[0m\"\n\n";
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 3: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			if (check_path(str))
			{
				cout << "\nFile path is \"\x1B[32m" << file_path(str) << "\033[0m\"\n\n";
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 4: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			if (check_path(str))
			{
				cout << "\nFile disk is \"\x1B[32m" << file_disk(str) << "\033[0m\"\n\n";
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 5: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			cout << "\nEnter new file name: ";
			getline(cin, new_name);

			if (check_path(str))
			{
				file_rename(str, new_name);
				cout << "\nNew file path is \"\x1B[32m" << str << "\033[0m\"\n\n";
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 6: {
			cout << "\nEnter the file path: ";
			cin.ignore(1, '\n');
			getline(cin, str);
			cut_off_quotes(str);
			replace_slash(str);

			if (check_path(str))
			{
				if (file_copy(str))
				{
					cout << "\x1B[32m\nFile copy was successful\n\n\033[0m";
				}
				else
				{
					cout << "\x1B[31m\nFile copy was unsuccessful\n\n\033[0m";
				}
			}
			else
			{
				cout << "\x1B[31m\nInvalid path entered\n\n\033[0m";
			}
			break;
		}
		case 7:
			exit(0);
			break;
		default:
			break;
		}
	}
}
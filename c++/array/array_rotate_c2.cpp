#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
void print_1d_vector(const vector<int> &);

/*
 * Complete the 'rotLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER d
 */

vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    int dd = d % n;

    vector<int> r(n);

    for (int i = 0; i < n; i++) {
        int rem = i - dd;
        if(rem < 0) {
           rem = rem + n;
           //cout << rem << endl;
        }
        r[rem] = a[i];
    }
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    print_1d_vector(result);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

void print_1d_vector(const vector<int> &v) {
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),find_if(s.begin(), s.end(), [](int c) {return !isspace(c);}));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), [](int c) {return !isspace(c);}).base(), s.end());

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

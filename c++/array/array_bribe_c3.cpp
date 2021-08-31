#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
void print_1d_vector(const vector<int> &);
/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    // ofstream fout(getenv("OUTPUT_PATH"));
    int n = q.size();

    int bribes = 0;

    bool chaotic = 0;

    for (int i = 0; i < n; i++) {
        if ((q[i] - i) > 3) {
          chaotic = 1;
          //fout << "Too chaotic" << endl;
          //cout << "Too chaotic" << endl;
        }
        int l = q[i] - 1;
        if (l < 0){ l = 0;}
        // cout << "[" << i << "] " << q[i] << ": \n";
        for (int j = 0; j < i; j++) {
            // cout << "(" << q[j] << ", " << q[i] << ") ";
            if (q[j] > q[i]) {
                bribes = bribes + 1;
            }
        }
        // cout << " " << endl;
    }

    if (chaotic) {
        // fout << "Too chaotic" << endl;
        cout << "Too chaotic" << endl;
    }
    else {
      // fout << bribes << endl;
      cout << bribes << endl;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

void print_1d_vector(const vector<int> &v) {
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
    cout << endl;
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

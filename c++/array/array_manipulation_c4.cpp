#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
void print_1d_vector(const vector<long> &);
/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    long r = -10000000;
    vector<long> v(n+2);

    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        v[a] = v[a] + k;
        v[b+1] = v[b+1] - k;
        print_1d_vector(v);
    }

    long new_val = 0;
    for (int i = 0; i < n; i++) {
        new_val = new_val + v[i];

        if (new_val > r) {
          r = new_val;
        }
    }
    cout << r << endl;
    return r;
}

long arrayManipulation_brute(int n, vector<vector<int>> queries) {
    long r = -10000000;
    vector<long> v(n);

    for (int i = 0; i < queries.size(); i++) {
        for (int j = queries[i][0]; j <= queries[i][1]; j++) {
          v[j-1] = v[j-1] + queries[i][2];
        }
        print_1d_vector(v);
        cout << endl;
    }
    cout << "---------------" << endl;
    print_1d_vector(v);
    cout << "---------------" << endl;
    //cout << max_element(v.begin(), v.end()) << endl;
    for (int i = 0; i < n; i++) {
        if (v[i] > r) { r = v[i];}
    }
    cout << r << endl;
    return r;
}

void print_1d_vector(const vector<long> &v) {
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
    cout << endl;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
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

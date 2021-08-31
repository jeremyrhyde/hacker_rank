#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
// static inline string ltrim(string &)
// static inline string rtrim(string &);
vector<string> split(const string &);
void print_2d_vector(const vector<vector<int> > &);
void print_1d_vector(const vector<string> &);
vector <vector <int> > get_input(void);
/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int> > arr) {

    vector <vector <int> > kernel = {{1,1,1}, {0,1,0}, {1,1,1}};

    int max_sum = -100000;

    vector <vector <int> > max_kernel = {{0,0,0}, {0,0,0}, {0,0,0}};

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {

            int sum = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {

                  sum = sum + kernel[k+1][l+1]*arr[i+k][j+l];
                  // cout << arr[i+k][j+l] << "*" << kernel[k+1][l+1] << " [" << i+k << "," << j+l << "] " << " [" << k << "," << l << "] " << sum << endl;
                }
            }
            //cout << "------------" << endl;
            // cout << sum << endl;

            if (max_sum < sum) {
                max_sum = sum;

                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        max_kernel[k+1][l+1] = arr[i+k][j+l];
                    }
                }

            }
        }

    }
    cout << "max_sum: " << max_sum << endl;
    print_2d_vector(max_kernel);
    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector < vector <int> > arr = get_input();
    //vector < vector <int> > arr = {{-9,-9,-9,1,1,1},{0,-9,0,4,3,2},{-9,-9,-9,1,2,3},{0,0,8,6,6,0},{0,0,0,-2,0,0},{0,0,1,2,4,0}};

    print_2d_vector(arr);


    int result = hourglassSum(arr);

    fout << result << "\n";
    fout.close();

    return 0;
}

void print_2d_vector(const vector<vector<int> > &v) {
    cout << "-----------------" << endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------------" << endl;
}

void print_1d_vector(const vector<string> &v) {
    for (int j = 0; j < 6; j++) {
        cout << v[j] << " ";
    }
}


vector <vector <int> > get_input(void) {
    vector<vector<int> > arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);
        //
        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));
        //
        //cout << arr_row_temp[0];
        for (int j = 0; j < 6; j++) {
          //cout << arr_row_temp[j] << endl;
            arr[i][j] = stoi(arr_row_temp[j]);
          //cout << i << '\n';
           // int arr_row_item = 1;//stoi(arr_row_temp[j]);
           // arr[i][j] = arr_row_item;
           // cout << arr[i][j] << "\n";
        }
    }
    return arr;
}
// static inline string &ltrim(string &s) {
//     s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
//     return s;
// }
//
// static inline string &rtrim(string &s) {
//     string s(str);
//
//     s.erase(find_if(s.begin(), s.rend(), [](int c) {return !std::isspace(c);}), s.end());
//     return s;
// }


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
//
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

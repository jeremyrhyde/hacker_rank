#include<iostream>
#include<vector>

using namespace std;

void print(std::vector <int> const &a) {
   cout << "The vector elements are : \n";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i) << ' ' << endl;
}

int main() {
   vector<int> a = {2,4,3,5,6};
   print(a);
   cout.flush();
   return 0;
}

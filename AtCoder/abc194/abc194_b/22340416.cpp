// detail: https://atcoder.jp/contests/abc194/submissions/22340416
#include <bits/stdc++.h>
using namespace std;

struct TestCaseChecker{
  ifstream fin;
  ofstream fout;
  string file_name;
  TestCaseChecker():file_name("a.txt"){
    fout.open(file_name);
  }
  TestCaseChecker(string name):file_name(name){
    fout.open(file_name);
  }

  friend bool isDifferent(TestCaseChecker &a,TestCaseChecker &b){
    a.fin.open(a.file_name);
    vector<string> answer1;
    string temp;
    while(getline(a.fin,temp)){
      answer1.emplace_back(temp);
    }
    cout<<temp<<endl;

    a.fin.close();
    b.fin.open(b.file_name);

    vector<string> answer2;
    while(getline(b.fin,temp)){
      answer2.emplace_back(temp);
    }

    for(int i=0;i<(int)answer1.size();i++){
      cout<<answer1[i]<<' '<<answer2[i]<<endl;
      if(answer1[i] != answer2[i]) return false;
    }
    return true;
  }
};

int main(){
  TestCaseChecker checker1;
  TestCaseChecker checker2("b.txt");

  checker1.fout<<10<<'\n'<<10<<'\n';
  checker2.fout<<20<<'\n'<<1000<<'\n';

  bool result = isDifferent(checker1, checker2);

  cout<<boolalpha;
  cout<<result<<endl;
}
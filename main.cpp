#include <fstream>
#include <iostream>
#include <algorithm>

int main() {
  std::ifstream myfile;
  int ans1 = 0;
  int ans2 = 0;
  myfile.open("input.txt");
  std::string s;
  std::getline(myfile, s);
  while (myfile) {
    int a1,b1,a2,b2;
    std::string e1 = s.substr(0, s.find(','));
    std::string e2 = s.substr(s.find(',')+1, s.length());
    a1 = stoi(e1.substr(0, e1.find('-')));
    b1 = stoi(e1.substr(e1.find('-')+1, e1.length()));
    a2 = stoi(e2.substr(0, e2.find('-')));
    b2 = stoi(e2.substr(e2.find('-')+1, e2.length()));
    //std::cout<<a1<<"*"<<b1<<"==="<<a2<<"*"<<b2<<std::endl;

    if(a1<=a2&&b1>=b2||a1>=a2&&b1<=b2)
    {
      //std::cout<<"cont:"<<s<<std::endl;
      ans1++;
      ans2++;
    }
    else if(b1>=a2&&a1<a2||b2>=a1&&a2<a1)
    {
      ans2++;
      //std::cout<<"part:"<<s<<std::endl;
    }
    else
    {
      //std::cout<<"none:"<<s<<std::endl;
    }
    
    std::getline(myfile, s);
  }
  std::cout<<"Answer1:"<<ans1<<std::endl;
  std::cout<<"Answer2:"<<ans2<<std::endl;
}
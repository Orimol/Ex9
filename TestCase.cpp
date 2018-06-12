//
// Created by ori on 6/7/18.
//
#include "TestCase.hpp"


TestCase::TestCase(string name, std::ostream& cerr):test_name(name),omessage(cerr) {
    counter=1;
    failer_count=0;
}


void TestCase:: print() {
    ostringstream absorb;
    absorb<<test_name<<": "<<failer_count<<" failed, "<<counter-failer_count-1<<" passed, "<<counter-1<< " total."<<endl<<"---"<<endl;
    string s=absorb.str();
    omessage.write(s.c_str(),s.size());
    omessage.flush();
    cout<<"\n";
   // omessage.write(s.c_str(),s.size());


}

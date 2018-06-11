//
// Created by ori on 6/7/18.
//
#include <iostream>
#include <string>
#include <sstream>



#ifndef EX9_TESTCASE_HPP
#define EX9_TESTCASE_HPP
using namespace std;

class TestCase {
private:
    string test_name;
    ostream& omessage; // trying not use a declaration of ostream in the class
    int counter;
    int failer_count;

public:
    TestCase(string name, std::ostream& cerr);
//
//    template <typename T> TestCase check_equal(T A, T B);
//
//    template <typename T> TestCase check_different(T A, T B);
//
//    template <typename T> TestCase check_output(T A, string s);
//
//    template <typename T, typename T2, typename T3> TestCase check_function(T foo, T2 A, T3 B);


    template <typename T> TestCase check_equal(T A, T B){
        if (A==B) {}
        else{
            failer_count++;
            ostringstream absorb;
            absorb<<test_name<<": Failure in test #"<<counter<<A<<": should equal"<<B<<endl;
            string s=absorb.str();
            omessage.write(s.c_str(),s.size());
        }
        counter++;
        return  *this;
    }


    template <typename T> TestCase check_different(T A, T B){
        if (A==B) {
            failer_count++;
            ostringstream absorb;
            absorb<<test_name<<": Failure in test #"<<counter<<A<<": is not different from "<<B<<endl;
            string s=absorb.str();
            omessage.write(s.c_str(),s.size());
        }
        counter++;
        return  *this;
    }

    template <typename T> TestCase check_output(T A, string s){
        ostringstream absorb, text;
        absorb<<A;
        if(absorb.str()!=s){
            failer_count++;
            text<<test_name<<": Failure in test # "<<counter<<": string value should be "<<s<<" but is "<<absorb.str()<<endl;
            string s1=text.str();
            omessage.write(s1.c_str(),s1.size());
        }
        counter++;
        return  *this;
    }

    template <typename T, typename T2, typename T3> TestCase check_function(T foo, T2 A, T3 B) {
        T3 temp = foo(A);
        if (temp == B) {}//true
        else {
            failer_count++;
            ostringstream absorb;
            absorb << test_name << ": Failure in test #" << counter << ": Function should return " << B << " but returned "
                   << temp << "!" << endl;
            string s=absorb.str();
            omessage.write(s.c_str(),s.size());
        }
        counter++;
        return *this;
    }

    void print();



};


#endif //EX9_TESTCASE_HPP

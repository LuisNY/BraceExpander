#include <iostream>
#include <vector>
#include <assert.h>
#include "../src/Expander.h"

int main(){

    bool c =false;

    std::string test="{O,A{M}E{K,W}}";
    Expander exp_tes(test);
    int index=0;
    auto vec = exp_tes.parseString(index,c);
    assert (vec.size()==3);
    assert (vec[0]=="O");
    assert (vec[1]=="AMEK");
    assert (vec[2]=="AMEW");

    int index0=0;
    std::string test0="{A,B{C,D}E,H{I,O}{Y,T}Q}";
    Expander exp_test(test0);
    auto vect0 = exp_test.parseString(index0,c);
    assert (vect0.size()==7);
    assert (vect0[0]=="A");
    assert (vect0[1]=="BCE");
    assert (vect0[2]=="BDE");
    assert (vect0[3]=="HIYQ");
    assert (vect0[4]=="HITQ");
    assert (vect0[5]=="HOYQ");
    assert (vect0[6]=="HOTQ");

    std::string test1="{A,B,C}";
    Expander exp_test1(test1);
    int index1=0;
    auto vect1 = exp_test1.parseString(index1,c);
    assert (vect1.size()==3);
    assert (vect1[0]=="A");
    assert (vect1[1]=="B");
    assert (vect1[2]=="C");

    std::string test2="{A,B{C,D}}";
    Expander exp_test2(test2);
    int index2=0;
    auto vect2 = exp_test2.parseString(index2,c);
    assert (vect2.size()==3);
    assert (vect2[0]=="A");
    assert (vect2[1]=="BC");
    assert (vect2[2]=="BD");

    std::string test3="{A,B}{C,D}";
    Expander exp_test3(test3);
    int index3=0;
    auto vect3 = exp_test3.parseString(index3,c);
    assert (vect3.size()==4);
    assert (vect3[0]=="AC");
    assert (vect3[1]=="AD");
    assert (vect3[2]=="BC");
    assert (vect3[3]=="BD");

    std::string test4="{ABC}";
    Expander exp_test4(test4);
    int index4=0;
    auto vect4 = exp_test4.parseString(index4,c);
    assert (vect4.size()==1);
    assert (vect4[0]=="ABC");

    std::string test5="ABC";
    Expander exp_test5(test5);
    int index5=0;
    auto vect5 = exp_test5.parseString(index5,c);
    assert (vect5.size()==1);
    assert (vect5[0]=="ABC");

    std::string test6="}ABC";
    Expander exp_test6(test6);
    assert(!exp_test6.isBalancedString());

    std::string test7="{ABC";
    Expander exp_test7(test7);
    assert(!exp_test7.isBalancedString());

    std::string test8="}{";
    Expander exp_test8(test8);
    assert(!exp_test8.isBalancedString());

    std::string test9="{}";
    Expander exp_test9(test9);
    assert(!exp_test9.isBalancedString());

    std::string test10="A,B,C";
    Expander exp_test10(test10);
    assert(!exp_test10.isBalancedString());

    std::string test11="{A{B,C}";
    Expander exp_test11(test11);
    assert(!exp_test11.isBalancedString());

    std::string test12="{A,}";
    Expander exp_test12(test12);
    assert(!exp_test12.isBalancedString());

}
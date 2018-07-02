//
//  main.cpp
//  DesignModes
//  参考文档：http://design-patterns.readthedocs.io/zh_CN/latest/index.html

//  Created by 龚丹丹 on 2018/6/29.
//  Copyright © 2018年 Iris. All rights reserved.
//

#include <iostream>
using namespace std;
#include "策略模式/MarketMode.cpp"
#include "工厂模式/FactoryMode.cpp"



void factory() {
    OperationFactory * fac = new OperationFactory();
    Operation * oper = fac->createOperation('/');
    oper->setA(10);
    oper->setB(20);
    double result = oper->result();
    cout << "result is:"<<result << endl;
}

void market() {
    char item;
    cout << "选择计费模式:" << endl;
    cin >>item;
    Context * text = new Context(item);
    text->contextInterface();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    market();
};


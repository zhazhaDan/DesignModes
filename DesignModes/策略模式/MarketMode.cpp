//
//  MarketMode.cpp
//  DesignModes
//
//  Created by 龚丹丹 on 2018/6/29.
//  Copyright © 2018年 Iris. All rights reserved.
//


/**
 
 意图：定义一系列的算法,把它们一个个封装起来, 并且使它们可相互替换。(此模式让算法的变化，不会影响到使用算法的客户)
 
 主要解决：在有多种算法相似的情况下，使用 if...else 所带来的复杂和难以维护。
 
 何时使用：一个系统有许多许多类，而区分它们的只是他们直接的行为。
 
 如何解决：将这些算法封装成一个一个的类，任意地替换。
 
 关键代码：实现同一个接口
 
 优点： 1、算法可以自由切换。 2、避免使用多重条件判断。 3、扩展性良好。
 
 缺点： 1、策略类会增多。 2、所有策略类都需要对外暴露。
 
 使用场景： 1、如果在一个系统里面有许多类，它们之间的区别仅在于它们的行为，那么使用策略模式可以动态地让一个对象在许多行为中选择一种行为。 2、一个系统需要动态地在几种算法中选择一种。 3、如果一个对象有很多的行为，如果不用恰当的模式，这些行为就只好使用多重的条件选择语句来实现。
 
 注意事项：如果一个系统的策略多于四个，就需要考虑使用混合模式，解决策略类膨胀的问题。
 */

/**
 策略模式封装了变化
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Strategy
{
public:
    virtual void Algorithm() = 0;
};

//具体算法
class ConcreteStrategyA:public Strategy
{
public:
    void Algorithm()
    {
        cout << "实现了具体算法A" << endl;
    }
};

class ConcreteStrategyB:public Strategy
{
public:
    void Algorithm()
    {
        cout << "实现了具体算法B" << endl;
    }
};

class ConcreteStrategyC:public Strategy
{
public:
    void Algorithm()
    {
        cout << "实现了具体算法C" << endl;
    }
};



//配置，维护对Strategy对象的引用
class Context
{
public:
    Strategy * strategy;
    Context(Strategy * str)//策略模式
    {
        this->strategy = str;
    }

    Context(char item){ //策略模式和简单工厂模式结合 低耦合
        {
            switch (item) {
                case 'A':
                    strategy = new ConcreteStrategyA();
                    break;
                case 'B':
                    strategy = new ConcreteStrategyB();

                    break;
                case 'C':
                    strategy = new ConcreteStrategyC();
                    break;
                default:
                    break;
            }
        }
    }
    
    void contextInterface()//根据具体的策略对象，调用其算法的方法
    {
        this->strategy->Algorithm();
    }
};








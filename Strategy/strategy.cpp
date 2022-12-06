#include <algorithm>
#include <iostream>

#define free_ptr(p) if(p) delete p; p = nullptr;

//strategy �࣬��������֧�ֵ��㷨�Ĺ����ӿ�
class Strategy 
{
public:
    virtual ~Strategy() {};
    virtual void AlgorithmInterface() = 0;
};

//ConcretStrategy ��װ������㷨���̳���Strategy
class ConcreteStrategyA : public Strategy
{
    void AlgorithmInterface()
    {
        std::cout << "�㷨Aʵ��" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void AlgorithmInterface()
    {
        std::cout << "�㷨Bʵ��" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface()
    {
        std::cout << "�㷨Cʵ��" << std::endl;
    }
};


//context ��һ��ConcreteStrategy�����ã�ά��һ����Strategy������
class Context
{
public:
    Context(Strategy* strategy) : m_strategy(strategy) { };
    ~Context() { free_ptr(m_strategy); }
    void AlgorithmInterface()
    {
        m_strategy->AlgorithmInterface();
    }
private:
    Strategy *m_strategy;
};

int main()
{
    Strategy* A = new ConcreteStrategyA();
    Strategy* B = new ConcreteStrategyB();
    Strategy* C = new ConcreteStrategyC();
    A->AlgorithmInterface();
    B->AlgorithmInterface();
    C->AlgorithmInterface();

    free_ptr(A);
    free_ptr(B);
    free_ptr(C);
    return 0;

}
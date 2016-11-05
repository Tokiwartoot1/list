#include <iostream>

using namespace std;
struct ListMem
{
    int listvalue;
    ListMem *next=0;
};
class List;
class Iterator
{
public:
    void setValue(int a);
    void next();
    int value();
    bool equal(Iterator &other);
private:
    ListMem *item=0;
    friend class List;
};
Iterator List::begin()
{
    Iterator iter;
    iter.item=head;
    return iter;
}

Iterator List::end()
{
    return Iterator();
}
void Iterator::setValue(int a)
{
    item->listvalue=a;
}

void Iterator::next()
{
    item=item->next;
}

int Iterator::value()
{
    return item->listvalue;
}

bool Iterator::equal(Iterator &other)
{
    return item ==other.item;
}
class List
{
public:
    void push(int a);
    Iterator begin();
    Iterator end();
private:
    ListMem *cur=0;
    ListMem *head=0;
};

void List::push(int a)
{
    auto item = new ListMem;
    //auto позволяет не указывать тип переменной явно, говоря компилятору,
    //чтобы он сам определил фактический тип переменной, на основе типа
    //инициализируемого значения.
    item->listvalue=a;
    item->next=head;
    head = item;
}


void input(List &list)
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        list.push(x);
    }
}


bool stringEqual(Iterator conteinerFrom,Iterator conteinerEnd,Iterator innerBegin,Iterator innerEnd)
{
    while (!innerBegin.equal(innerEnd))
    {
        if(conteinerFrom.equal(conteinerEnd))
            return false;
        if(conteinerFrom.value()!=innerBegin.value())
            return false;
        conteinerFrom.next();
        innerBegin.next();
    }
    return true;
}
bool stringContains(List &container,List &inner)
{
    auto begin=container.begin();
    auto end=container.end();

    auto innerBegin=inner.begin();
    auto innerEnd=inner.end();
    for(;;)
{
        if(stringEqual(begin,end,innerBegin,innerEnd))
        return true;
        if (begin.equal(end))
        break;
        begin.next();
}
        return false;
}

int main()
{
    List l1,l2;
    input(l1);
    input(l2);
    cout<<stringContains(l1,l2)<<endl;
}




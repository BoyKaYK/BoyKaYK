
#include <iostream>
#include<string>

using namespace std;
int n = 0;
int g = 0;
int k = 0;
int ile = 0;
int act = 0;
struct Node                             //Структура, являющаяся звеном списка
{
    int x;                             //Значение x будет передаваться в список
    Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class List                              //Создаем тип данных Список
{
    Node* Head, * Tail;                 //Указатели на адреса начала списка и его конца
public:
    List() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
    ~List();                           //Прототип деструктора
    void Show_backward();
    void Show_forward();                            
    void Add_END(int x); 
    void Add_BEG(int x);
    void Add_ACT(int x);
    void actual();
    void next();
    void prev();
    void Del_beg();
    void Del_End();
    void Del_act();
    void Del_value(int x);
};

List::~List()                           
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void List::next()
{
    n++;
    Node* actual = Head;
    if (Head == NULL) {
        actual = nullptr;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (actual->Next == NULL) {
                actual = Head;
                n = 0;
            }
            else {
                actual = actual->Next;
            }
        }
    }
    if (ile == 1) {
        actual = Head = Tail;
    }
    
    if (actual == nullptr) {
        cout << "NULL";
    }
    else {
        cout << actual->x << " ";
    }
   cout << "\n";
   
   g++;
}


void List::prev() {
    n--;
    Node* actual = Head ;
    if (Head == NULL) {
        actual = nullptr;
    }
    
    else {
        for (int i = 0; i < n; i++) {

            actual = actual->Next;

        }
    }

    if (n < 0) {
        actual = Tail;
        n = ile - 1;
    }

    if (ile == 1) {
        actual = Head = Tail;
    }
    
    if (actual == nullptr) {
        cout << "NULL";
    }
    else {
        cout << actual->x << " ";
    }
    
    
    cout << "\n";

    
    g++;
}
void List::actual() {
   
    Node* actual = Head;
    if (Head == NULL) {
         actual = nullptr ;
    }
    else if (act == 0 && n == 0 ){
        actual = Head;
         
    }
    else if(Head != NULL) {
        
        
        if (n == 0 && g == 0) {
            n = k - 1 ;

        } 


        for (int i = 0; i < n; i++) {
            actual = actual->Next;
        }

        if (n == -2) {
            actual = Tail;
            n = ile - 1;
        }

        
    }
    if (actual == nullptr) {
        cout << "NULL";
    }
    else {
        cout << actual->x << " ";
    }
    
    
    act++;
    
    cout << "\n";


}
void List::Del_beg()
{
    if (ile == 0) {
        ile = 0;
        
    }
    else {
        n--;
        ile--;
        Node* actual = Head;

        Head = Head->Next;

        delete actual;
        if (n == -1) {
            n--;
        }
        if (ile > 0) {
            Head->Prev = NULL;
        }
        else {
            Head = Tail = NULL;
        }
    }

}
void List::Del_End()
{
    if (ile == 0) {
        ile = 0;
    }
    else {
        ile--;
        Node* actual = Tail;

        Tail = Tail->Prev;

        delete actual;


        if (ile > 0) {
            Tail->Next = NULL;
        }
        else {
            Head = Tail = NULL;
        }
    }
    
}
void List::Del_act() {
    if (ile == 0) {
        ile = 0;
    }
    else {
        ile--;
        Node* actual = Head;
        if (Head == NULL) {
            actual = nullptr;
        }
        else if (act == 0 && n == 0) {
            actual = Head;

        }
        else if (Head != NULL) {


            if (n == 0 && g == 0) {
                n = k - 1;

            }

            for (int i = 0; i < n; i++) {
                actual = actual->Next;
            }

            if (n == -2) {
                actual = Tail;
                n = ile - 1;
            }

        }
        
        if (actual != Head) {
            actual = actual->Prev;

            Node* toDelete = actual->Next;

            actual->Next = toDelete->Next;

            delete toDelete;
            if (ile > 0) {
                actual->Next = NULL;
            }
        }
        else {
            Node* actual = Head;
            if (ile > 1) {
                Head = Head->Next;
            }
            else {
              Tail = Head = NULL;
            }

            delete actual;
            if (n == -1) {
                n--;
            }

            
             
          
        }

        n--;
    }
    
}
void List::Add_ACT(int x) 
{
    Node* actual = Head;
    if (Head == NULL) {
        actual = nullptr;
    }
    else if (act == 0 && n == 0) {
        actual = Head;

    }
    else if (Head != NULL) {


        if (n == 0 && g == 0) {
            n = k - 1;

        }

        for (int i = 0; i < n; i++) {
            actual = actual->Next;
        }

        if (n == -2) {
            actual = Tail;
            n = ile - 1;
        }

    }
    if (actual != Head) {
        actual = actual->Prev;
    }

    Node* temp = new Node; 
    if (actual == Head) {
        temp->Prev = NULL;                   
        temp->x = x;

        if (Head != NULL)                    
        {
            temp->Next = Head;               
            Head->Prev = temp;               
            Head = temp;                     
        }
        
    }
    else {
        temp->x = x;
        temp->Prev = actual;
        temp->Next = actual->Next;
        (actual->Next)->Prev = temp;
        actual->Next = temp;
    }
    
    
    ile++;
    n++;

}
void List::Del_value(int x) {
    Node* actual = Head;

    for (int i = 0; i < ile; i++) {

        if (actual->x == x) {

           if(actual == Head) {
               i--;
               n--;
               ile--;
               Node* toDelete = Head;

               Head = Head->Next;

               actual = Head;
               

               delete toDelete;
               if (n == -1) {
                   n--;
               }
               
            }
            else if(actual == Tail) {
               
               Node* toDelete = Tail;

               Tail = Tail->Prev;

               delete toDelete;
               Tail->Next = NULL;
               ile--;
               
            }
            else {
               actual = actual->Prev;

               Node* toDelete = actual->Next;

               actual->Next = toDelete->Next;

               delete toDelete;
               ile--;

              
           }

           
            
        }

        actual = actual->Next;

    }
    
}
void List::Add_END(int x)
{
    Node* temp = new Node;               
    temp->Next = NULL;                   
    temp->x = x;                         

    if (Head != NULL)                    
    {
        temp->Prev = Tail;               
        Tail->Next = temp;               
        Tail = temp;                    
                                         
    }
    else 
    {
        temp->Prev = NULL;               
        Head = Tail = temp;              
    }
   
    ile++;
}
void List::Add_BEG(int x) {
    Node* temp = new Node;
    temp->Prev = NULL;                  
    temp->x = x;                         

    if (Head != NULL)                    
    {
        temp->Next = Head;               
        Head->Prev = temp;               
        Head = temp;                     
    }
    else //Если список пустой
    {
        temp->Prev = NULL;               
        Head = Tail = temp;              
    }
    if (n>0) {
        g++;
    }
    if (n == 0) {
        k++;
    }
    ile++;
}
void List::Show_backward()
{
    //ВЫВОДИМ СПИСОК С КОНЦА
    if (ile == 0) {
        cout << "NULL"<<"\n";
    }
    else {
        Node* temp = Tail;                   //Временный указатель на адрес последнего элемента

        while (temp != NULL)               
        {
            cout << temp->x << " "; 
            
            if (ile > 1) {
                temp = temp->Prev;
            }            
        }
        cout << "\n";
    }
}
void List::Show_forward(){
    if (ile == 0) {
        cout << "NULL" << "\n";
    }//ВЫВОДИМ СПИСОК С НАЧАЛА
    else {
        Node* temp = Head;
        //Временно указываем на адрес первого элемента
        while (temp != NULL)              
        {
            cout << temp->x << " ";
            if (ile > 1) {
                temp = temp->Next;
            }
            else {
                temp = NULL;
            }

        }
        cout << "\n";
    }
}

int main()
{
    
    List lst; 
    string comand;
    int x;
    while (cin >> comand) {
        if (comand == "ADD_BEG") {
            cin >> x;
            lst.Add_BEG(x);
            
        }
        if (comand == "ADD_END") {
            cin >> x;
            lst.Add_END(x);
            

        }
        if (comand == "PRINT_BACKWARD") {
            
            lst.Show_backward();
           

        }
        if (comand == "PRINT_FORWARD") {

            lst.Show_forward();


        }
        if (comand == "NEXT") {

            lst.next();
            


        }
        if (comand == "PREV") {

            lst.prev();


        }
        if (comand == "ACTUAL") {

            lst.actual();


        }
        if (comand == "DEL_BEG") {

            lst.Del_beg();


        }
        if (comand == "DEL_END") {

            lst.Del_End();

            
        }
        if (comand == "DEL_ACT") {

            lst.Del_act();

        }
        if (comand == "ADD_ACT") {
            cin >> x;
            lst.Add_ACT(x);
           

        }
        if (comand == "DEL_VAL") {
               cin >> x;
               lst.Del_value(x);

           }


    }
    
    
    return 0;
}
#include <iostream>
#include <iostream>
#include<stack>
using namespace std;
stack <int> s1;
int main()
{
    cout<<s1.empty();//answer is 1 means true
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout<<"size="<<s1.size()<<endl;  //how many elements are there in stack
    s1.pop();   //only decrease the top doesnot return any thing
    cout<<s1.top();
    cout<<s1.empty();//answer is 0 means false
    cout<<!s1.empty();//answer is 1 means true
     //display all elements
	while (!s1.empty()) {
        cout << ' ' << s1.top();
        s1.pop();
    }
    
    return 0;
}

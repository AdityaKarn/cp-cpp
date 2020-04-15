#include <iostream>

using namespace std;

class Rectangle
{
private:
    /* data */

public:
    int height, width;
    void display(){
        cout<<height<<" "<<width<<endl;
    }
};

class RectangleArea: public Rectangle{
    public:
    
    void read_input(){
        cin>>height>>width;
    }
    void display(){
        cout<<height*width;
    }
};



/*
 * Create classes Rectangle and RectangleArea
 */
int main(){
    RectangleArea rect;
    rect.read_input();
    rect.Rectangle::display();
    rect.display();


    return 0;
}

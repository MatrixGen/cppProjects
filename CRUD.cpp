#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>


class Item
{
    public:
    std::string itemName;
    std::string itemId;
    double itemPrice;
    std::string description;

    void display(){
        std::cout<<itemId<<std::endl<<itemName<<std::endl<<itemPrice<<std::endl<<description<<std::endl;
    }

};

void createItem();
bool deleteItem();
void readItems();
bool updateItem();

std::vector<Item> items;

int main()
{
    
    int option;

    std::cout<<"welcome  to CRUD ---What do you want to do !\n";
    std::cout<<"please select your option\n";
    std::cout<<"1.create Item\n"<<"2.delete Item\n"<<"read Items\n"<<"4.update Items\n";
    std::cin>>option;
    if(option==1)
    {
        createItem();
    }
    
    else if(option==3)
    {
        readItems();
    }
   


}

void createItem(){
    Item newItem;
    std::cout<<"enter the item ID";
    std::cin>>newItem.itemId;

    std::cout<<"please enter the name of the item :";
    std::cin>>newItem.itemName;

    std::cout<<"enter the price of the item :$";
    std::cin>>newItem.itemPrice;

    std::cout<<"enter the item description if any :";
    std::cin>>newItem.description;

    items.insert(items.begin(),newItem);

    std::cout<<"item created successfully !";



}

void readItems()
{
    int i;
  
    if(items.empty())
    {
        std::cout<<"no items found";
    }
    else
    { 
        for(i=0;i<=sizeof(items);i++)
        {
            std::cout<<items[i].itemName<<std::endl<<items[i].itemId<<std::endl<<items[i].itemPrice<<std::endl<<items[i].description<<std::endl;
        }
        

    
    }
}

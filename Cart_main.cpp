#include <bits/stdc++.h>
#include "datamodel.h"
using namespace std;
vector<Product> allProducts = {
    Product(1, "banana", 26),
    Product(2, "mango", 50),
    Product(3, "apple", 30),
    Product(4, "kiwi", 40),
    Product(5, "pineapple", 90),
    Product(6, "strawberry", 100),
    Product(7, "cheeku", 49),
    Product(8, "guava", 36),
    Product(9, "orange", 55),
    Product(1, "dragon fruit", 119),
};
Product *chooseProduct()
{
    string productList;
    cout << "Available Products" << endl;
    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "---------------------------------" << endl;
    string choice;
    cin >> choice;
    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found!!" << endl;
    return NULL;
}
bool checkout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }
    int total = cart.getTotal();
    cout << "Pay in Cash";
    int paid;
    cin >> paid;
    if (paid >= total)
    {
        cout << "Change " << paid - total << endl;
        cout << " Thank you for shopping! " << endl
             << "Visit us soon!!";
        return true;
    }
    else
    {
        cout << "Not enough Cash!";
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action -- (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            cout << "---------------------------------" << endl;
            cout << cart.viewCart();
            cout << "---------------------------------" << endl;
        }
        else
        {
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}
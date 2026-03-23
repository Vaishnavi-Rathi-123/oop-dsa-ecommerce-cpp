#include <iostream>
#include <vector>
using namespace std;

// Product Class
class Product {
public:
    int id;
    string name;
    float price;

    Product(int id, string name, float price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    void display() {
        cout << id << " | " << name << " | Rs." << price << endl;
    }
};

// Cart Class
class Cart {
private:
    vector<Product> items;

public:
    void addProduct(Product p) {
        items.push_back(p);
        cout << "Added to cart!\n";
    }

    void viewCart() {
        if(items.empty()) {
            cout << "Cart is empty!\n";
            return;
        }

        float total = 0;
        cout << "\n--- Cart Items ---\n";
        for(auto &p : items) {
            p.display();
            total += p.price;
        }
        cout << "Total: Rs." << total << endl;
    }
};

// User Class
class User {
public:
    string name;
    Cart cart;

    User(string name) {
        this->name = name;
    }
};

// Main System
int main() {
    vector<Product> products = {
        Product(1, "Laptop", 50000),
        Product(2, "Phone", 20000),
        Product(3, "Headphones", 2000)
    };

    User user("Aditi");

    int choice;

    do {
        cout << "\n--- E-Commerce System ---\n";
        cout << "1. View Products\n2. Add to Cart\n3. View Cart\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "\n--- Products ---\n";
            for(auto &p : products) {
                p.display();
            }
        }

        else if(choice == 2) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            bool found = false;
            for(auto &p : products) {
                if(p.id == id) {
                    user.cart.addProduct(p);
                    found = true;
                    break;
                }
            }

            if(!found) cout << "Product not found!\n";
        }

        else if(choice == 3) {
            user.cart.viewCart();
        }

    } while(choice != 4);

    return 0;
}
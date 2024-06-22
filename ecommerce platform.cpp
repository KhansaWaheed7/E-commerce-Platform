#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h> // For getch()
#include <fstream>
#include <limits> // Required for clearing input buffer
using namespace std;

class UserAccount {
private:
	
    string username, email, password;

public:
    UserAccount(string username, string email, string password);
    bool authenticateUser(string username, string password);
	void setUsername(string username);
    void setEmail(string email);
    void setPassword(string password);
    string getUsername();
    string getEmail();
    string getPassword();
    static string getHiddenPassword();

};


UserAccount::UserAccount(string username, string email, string password) {
    this->username = username;
    this->email = email;
    this->password = password;
   
}


bool UserAccount::authenticateUser(string username, string password) {
    return (this->username == username && this->password == password);
}

void UserAccount::setUsername(string username) {
    this->username = username;
}

void UserAccount::setEmail(string email) {
    this->email = email;
}

void UserAccount::setPassword(string password) {
    this->password = password;
}

string UserAccount::getUsername() {
    return username;
}

string UserAccount::getEmail() {
    return email;
}

string UserAccount::getPassword() {
    return password;
}
string UserAccount::getHiddenPassword() {
    string password;
    char ch;

    while ((ch = _getch()) != 13) { // 13 is ASCII for Enter

        if (ch == 8) { // Handle backspace
            if (!password.empty()) {
                cout << "\b \b";
                 password.erase(password.size() - 1);
            }

        } else {
            password.push_back(ch);
            cout << '*'; // Print * for each character
        }
    }
    cout << endl;
    return password;
}


class Inventory {

protected:
    string name;
    int quantity;
    double price;

public:
    Inventory(string name, int quantity, double price);
    void setName(string name);
    void setQuantity(int quantity);
    void setPrice(double price);
    string getName();
    int getQuantity();
    double getPrice();
    virtual void DisplayItems() = 0; // Pure virtual function
    virtual ~Inventory() {} // Virtual destructor
};


Inventory::Inventory(string name, int quantity, double price) {
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

void Inventory::setName(string name) {
    this->name = name;
}

void Inventory::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Inventory::setPrice(double price) {
    this->price = price;
}

string Inventory::getName() {
    return name;
}

int Inventory::getQuantity() {
    return quantity;
}

double Inventory::getPrice() {
    return price;
}


class Shoes : public Inventory {
private:
    string shoeType;

public:
    Shoes(string name, int quantity, double price, string shoeType);
    string getShoeType();
};


Shoes::Shoes(string name, int quantity, double price, string shoeType) : Inventory(name, quantity, price) {
    this->shoeType = shoeType;
}

string Shoes::getShoeType() {
    return shoeType;
}


class LifestyleShoes : public Shoes {
public:
    LifestyleShoes(string name, int quantity, double price)
        : Shoes(name, quantity, price, "Lifestyle Shoes") {}
        
    virtual void DisplayItems(){
        cout << "\t1) Nike Dunk Low \t\t Price: $115"<<endl;
        cout << "\t2) Nike Air Max Koko \t\t Price: $100"<<endl;
        cout << "\t3) Nike Air Force 1'07 \t\t Price: $115"<<endl;
        cout << "\t4) Nike Air Max 270 \t\t Price: $115"<<endl;
        cout << "\t5) Nike Killshot 2 \t\t Price: $90"<<endl;
        cout << "\t6) Nike Dunk High \t\t Price: $130"<<endl;
        cout << "\t7) Nike V2K Run \t\t Price: $120"<<endl;
        cout << "\t8) Nike Gamma Force \t\t Price: $95"<<endl;
        
       
    }
};


class RunningShoes : public Shoes {
public:
    RunningShoes(string name, int quantity, double price)
        : Shoes(name, quantity, price, "Running Shoes") {}
        
    virtual void DisplayItems(){
        cout << "\t9) Nike Zoom Vomero \t\t Price: $160"<<endl;
        cout << "\t10) Nike P-6000 \t\t Price: $110"<<endl;
        cout << "\t11) Nike Waffle Nav \t\t Price: $80"<<endl;
        cout << "\t12) Nike Zoom Air Fire \t\t Price: $125"<<endl;
        cout << "\t13) Nike Cortez \t\t Price: $90"<<endl;
        cout << "\t14) Nike M2K Tekno \t\t Price: $120"<<endl;
        cout << "\t15) Nike Air Pegasus \t\t Price: $79.9"<<endl;
        cout << "\t16)Nike Phoenix Waffle \t\t Price: $100"<<endl;
    }
};


class TrainingShoes : public Shoes {
public:
    TrainingShoes(string name, int quantity, double price)
        : Shoes(name, quantity, price, "Training Shoes") {}
        
    virtual void DisplayItems(){
        cout << "\t17) Nike Motiva \t\t Price: $110"<<endl;
        cout << "\t18) Nike Metcon 9 \t\t Price: $112"<<endl;
        cout << "\t19) Nike Versair \t\t Price: $119"<<endl;
        cout << "\t20) Nike Romaleos 4 \t\t Price: $200"<<endl;
        cout << "\t21) Nike Sideline IV \t\t Price: $80"<<endl;
        cout << "\t22) Nike Fury \t\t Price: $90"<<endl;
        cout << "\t23) Nike Savaleos \t\t Price: $120"<<endl;
        cout << "\t24) Nike HyperSpeed Court \t\t Price: $90"<<endl;
    }
};


class Sandals : public Shoes {
public:
    Sandals(string name, int quantity, double price)
        : Shoes(name, quantity, price, "Sandals") {}
        
    virtual void DisplayItems(){
        cout << "\t25) Nike Calm SE \t\t Price: $50"<<endl;
        cout << "\t26) Nike Icon Classic \t\t Price: $65"<<endl;
        cout << "\t27) Nike Air Max Isla \t\t Price: $100"<<endl;
        cout << "\t28) Nike Offcourt Duo \t\t Price: $33.97"<<endl;
        cout << "\t29) Nike Victori One \t\t Price: $30"<<endl;
        cout << "\t30) Jordan Deja \t\t Price: $90"<<endl;
        cout << "\t31) Jordan Post \t\t Price: $30"<<endl;
        cout << "\t32) ACG Air Deschutz+ \t\t Price: $52.97"<<endl;
    }
};


class Clothing : public Inventory {
private:
    string clothingType;

public:
    Clothing(string name, int quantity, double price, string clothingType);
    string getClothingType();
};

Clothing::Clothing(string name, int quantity, double price, string clothingType) : Inventory(name, quantity, price) {
    this->clothingType = clothingType;
}

string Clothing::getClothingType() {
    return clothingType;
}


class SummerClothing : public Clothing {
public:
    SummerClothing(string name, int quantity, double price)
        : Clothing(name, quantity, price, "Summer Clothing") {}
        
    virtual void DisplayItems(){
        cout << "\t33) Long-Sleeve T-Shirt \t\t Price: $60"<<endl;
        cout << "\t34) Versatile Top \t\t Price: $55"<<endl;
        cout << "\t35) Button-Down Shirt \t\t Price: $95"<<endl;
        cout << "\t36) Solar Chase Top \t\t Price: $65"<<endl;
        cout << "\t37) Carpenter Pants \t\t Price: $120"<<endl;
        cout << "\t38) Challenger Pants \t\t Price: $62"<<endl;
        cout << "\t39) Volleyball T-Shirt \t\t Price: $35"<<endl;
        cout << "\t40) Heritage T-Shirt \t\t Price: $60"<<endl;
    }
};


class WinterClothing : public Clothing {
public:
    WinterClothing(string name, int quantity, double price)
        : Clothing(name, quantity, price, "Winter Clothing") {}
        
    virtual void DisplayItems(){
        cout << "\t50) Full-Zip Hoodie \t\t Price: $145"<<endl;
        cout << "\t51) Pullover Hoodie \t\t Price: $65"<<endl;
        cout << "\t52) Therma-Fit Top' \t\t Price: $70"<<endl;
        cout << "\t53) French terry Sweatshirt \t\t Price: $75"<<endl;
        cout << "\t54) Golf Jacket \t\t Price: $100"<<endl;
        cout << "\t55) Fleece Hoodie \t\t Price: $150"<<endl;
        cout << "\t56) Crew Neck Sweatshirt \t\t Price: $36"<<endl;
        cout << "\t57) Zip Sweatshirt \t\t Price: $101"<<endl;
    }
};


class Accessories : public Inventory {
private:
    string item;

public:
    Accessories(string name, int quantity, double price);
  
    virtual void DisplayItems(){
        cout << "\t58) AeroAdapt Cap \t\t Price: $45"<<endl;
        cout << "\t59) Futura Wash Cap \t\t Price: $26"<<endl;
        cout << "\t60) Waistpack(3L) \t\t Price: $27"<<endl;
        cout << "\t61) Fanny Pack(8L) \t\t Price: $47"<<endl;
        cout << "\t62) Card Wallet \t\t Price: $25"<<endl;
        cout << "\t63) Icon Blazer Wristlet \t\t Price: $40"<<endl;
        cout << "\t64) Swoosh Bucket hat \t\t Price: $30"<<endl;
        cout << "\t65) Stretch Woven Belt \t\t Price: $32"<<endl;
    }
};


Accessories::Accessories(string name, int quantity, double price) : Inventory(name, quantity, price) {
}

class SaleItems : public Inventory {
private:
    string item;

public:
    SaleItems(string name, int quantity, double price);

    virtual void DisplayItems(){
  	    cout << "\t66) Nike Air Max Plus \t\t Price: $135"<<endl;
        cout << "\t67) Max90 Basketball T-Shirt \t\t Price: $37"<<endl;
        cout << "\t68) Nike Pegasus 40 \t\t Price: $90"<<endl;
        cout << "\t69) Air Jordan 2 Low \t\t Price: $82"<<endl;
        cout << "\t70) Nike Air Huarache Runner \t\t Price: $89"<<endl;
        cout << "\t71) Jordan Max Aura 5 \t\t Price: $71"<<endl;
        cout << "\t72) Jordan Stadium 90 \t\t Price: $91"<<endl;
        cout << "\t73) Nike Metcon 9 \t\t Price: $86"<<endl;
    }
};


SaleItems::SaleItems(string name, int quantity, double price) : Inventory(name, quantity, price) {
}

class ShoppingCart {
private:
  Inventory* items[20]; 
  int cartSize;

public:
  ShoppingCart(); 
  void addItem(Inventory* item);
  void displayCart();
  void removeItem(string itemName);
  double calculateTotal();
  

};


ShoppingCart::ShoppingCart() {
  cartSize = 0; 
}

void ShoppingCart::addItem(Inventory* item) {
  if (cartSize < 20) {
    items[cartSize++] = item;
    cout << "\tItem added to cart." << endl;
  } else {
    cout << "\tSorry, the cart is full." << endl;
  }
}

void ShoppingCart::removeItem(string itemName) {
  cout<<"\tEnter the name or id of the product you want to remove from cart:";
  cin>>itemName;
  
  for (int i = 0; i < cartSize; i++) {
    if (items[i]->getName() == itemName) {
      for (int j = i; j < cartSize - 1; j++) {
        items[j] = items[j + 1];
      }
      cartSize--;
      cout <<"\t"<< itemName << " removed from the cart." << endl;
      return;
    }
  }
  cout << "\tItem not found in the cart." << endl;
}


void ShoppingCart::displayCart() {
  if (cartSize == 0) {
    cout << "\tYour shopping cart is empty." << endl;
  } else {
    cout << "\tItems in your shopping cart:" << endl;
    ofstream outfile("cart.txt",ios::app); 
    
    if (outfile.is_open()) {
      outfile << "Items in your shopping cart:" << endl;
      
      for (int i = 0; i < cartSize; i++) {
        cout << "\n\tProduct: " << items[i]->getName() <<"\n\tPrice $ " << items[i]->getPrice()<<"\n\tQuantity: " <<items[i]->getQuantity() << endl;
        outfile << "\n\tProduct: " << items[i]->getName()  <<"\n\tPrice $ " << items[i]->getPrice()<<"\n\tQuantity: " <<items[i]->getQuantity() << endl;
      }
      outfile.close();
    } else {
      cout << "\tUnable to open file." << endl;
    }
  }
}


double ShoppingCart::calculateTotal() {
  double total = 0.0;
  for (int i = 0; i < cartSize; i++) {
    total += items[i]->getPrice() * items[i]->getQuantity();
  }
  return total;
}



class Order {
private:
    string itemName;
    int quantity;
    double price;

public:
    Order(string itemName, int quantity, double price);
    void displayOrder();
};

Order::Order(string itemName, int quantity, double price) {
    this->itemName = itemName;
    this->quantity = quantity;
    this->price = price;
}

void Order::displayOrder() {
    cout << "\tItem: " << itemName << "\n\tQuantity: " << quantity << "\n\tPrice: $" << price << endl;
}


class Discount {
public:
    static double applyDiscount(double totalBill, const string& discountCode);
};

double Discount::applyDiscount(double totalBill, const string& discountCode) {
    if (discountCode == "NIKE10") {
        return totalBill * 0.9; // Apply 10% discount
    }
    cout<<"\tNo discount applied!"<<endl;
    return totalBill; // No discount applied
}


class Billing {
public:
    static double calculateTotalBill(ShoppingCart& cart, const string& discountCode);
};

double Billing::calculateTotalBill(ShoppingCart& cart, const string& discountCode) {
    double totalBill = cart.calculateTotal();
    totalBill = Discount::applyDiscount(totalBill, discountCode);
    
    return totalBill;
}



int main() {
    string name;
    int quantity;
    double price;
    ShoppingCart cart;
    Inventory *item;
    string itemName;
    string username, email, password;
     char option;
     char view;
     
    cout<<"\t\t\t ________________________________ \t\t\t"<<endl;
    cout<<"\t\t\t|                                |\t\t\t"<<endl;
    cout<<"\t\t\t|    WELCOME TO NIKE E-STORE!!   |\t\t\t" << endl;
    cout<<"\t\t\t|                                |\t\t\t"<<endl;
    cout<<"\t\t\t|________________________________|\t\t\t"<<endl;

   
    cout<<"\t\t\t|       CREATE NEW ACCOUNT       |\t\t\t" << endl;
    
    fstream outfile;
    outfile.open("User.txt",ios::app);
    cout << "\tEnter username: ";
    cin >> username;
    outfile <<"\n\tUsername: "<<username;
    cout << "\n\tEnter email: ";
    cin >> email;
    outfile <<"\n\tEmail: "<< email;
    cout << "\n\tEnter password: ";
    password = UserAccount::getHiddenPassword();
    outfile <<"\n\tPassword: "<< password;
    cout<<"\tAccount Created!"<<endl;
    outfile.close();
    
    UserAccount user(username, email, password);

    // Perform authentication
    string inputUsername, inputPassword;

    login:
    cout<<"\t\t\t       LOGIN TO YOUR ACCOUNT      \t\t\t"<<endl;
    cout << "\n\tEnter your username: ";
    cin >> inputUsername;
    cout << "\tEnter your password: ";
    inputPassword = UserAccount::getHiddenPassword();

    if (user.authenticateUser(inputUsername, inputPassword)) {
        cout << "\n\tLogin successful. Welcome, " << user.getUsername() << "!" << endl;
        
    main_menu:
    cout << "\tWe have following categories of Products: " << endl;
    cout << "\t1. SHOES\n\t2. CLOTHING \n\t3. ACCESSORIES \n\t4. SALE ITEMS." << endl;
    int choice;
    cout << "\tEnter your choice( 1-4 ): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\tWe have following categories of Shoes: " << endl;
        cout << "\t1. LIFESTYLE SHOES\n\t2. RUNNING SHOES\n\t3. TRAINING SHOES\n\t4. SANDALS" << endl;
        cout << "\tEnter your choice( 1-4 ): ";
        cin >> choice;
        if(choice==1) {
                    cout << "\tWe have following shoes in this category: " << endl;
                     LifestyleShoes ls(name, quantity, price);
                     ls.DisplayItems();
                     
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                    Inventory* item = new LifestyleShoes(name, quantity, ls.getPrice());
                 
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                    cart.addItem(item);
                    cart.displayCart();
                    
                    cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                }
                else{
	            goto main_menu;
               }
              }
                
                else if(choice==2) {
                    cout << "\tWe have following shoes in this category: " << endl;
                     RunningShoes rs(name, quantity, price);
                     rs.DisplayItems();
                     
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                    Inventory* item = new RunningShoes(name, quantity, rs.getPrice());
      
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                    
                        cart.addItem(item);
                    cart.displayCart();
                    
                   cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                }
                 else{
	            goto main_menu;
               }
            }
                else if(choice==3) {
                    cout << "\tWe have following shoes in this category: " << endl;
                     TrainingShoes ts(name, quantity, price);
                     ts.DisplayItems();
                     
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                   Inventory* item = new TrainingShoes(name, quantity, ts.getPrice());
  
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                    
                        cart.addItem(item);
                    cart.displayCart();
                    
                    cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                   
                }
                 else{
	            goto main_menu;
               }
            }
                else if(choice==4){
                    cout << "\tWe have following shoes in this category: " << endl;
                     Sandals ss(name, quantity, price);
                     ss.DisplayItems();
                     
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                    Inventory* item = new Sandals(name, quantity, ss.getPrice());
                  
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                     
                    cart.addItem(item);
                    cart.displayCart();
                    
                    cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                   
                }
                else{
				
            goto main_menu;
			}
			
           }
          else{
                    cout << "\tInvalid Choice! Try again. " << endl;
                    goto main_menu;
            }
        }
    
        else if(choice==2){
            cout << "\tWe have following categories of Clothing: " << endl;
            cout << "\t1. SUMMER CLOTHING\n\t2. WINTER CLOTHING" << endl;
            cout << "\tEnter your choice (1 or 2): ";
            cin >> choice;
            
                if (choice==1){
                    cout << "\tWe have following clothes in this category: " << endl;
                     SummerClothing sc(name, quantity, price);
                     sc.DisplayItems();
                     
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                    Inventory* item = new SummerClothing(name, quantity, sc.getPrice());
                   
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                      
                    cart.addItem(item);
                    cart.displayCart();
                    
                    cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                    
                }
                else{
	            goto main_menu;
	        }
            }
                else if(choice==2) {
                    cout << "\tWe have following clothing in this category: " << endl;
                    WinterClothing wc(name, quantity, price);
                    wc.DisplayItems();
                    cout << "\tEnter details of item you selected: "<<endl;
                    cout<<"\tName or id: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"\tQuantity: ";
                    cin>>quantity;
                    cout<<"\tPrice $ ";
                    cin>>price;
                   Inventory* item = new WinterClothing(name, quantity, wc.getPrice());
                    
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                        cart.addItem(item);
                    cart.displayCart();
                    
                   cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
                   
                }
                  else{
	            goto main_menu;
	        }
            }
               else{
                    cout << "\tInvalid Choice! Try again. " << endl;
                    goto main_menu;
            }
        }

        else if(choice==3)
        	{
            cout << "\tWe have following accessories in this category: " << endl;
            Accessories a(name, quantity, price);
            a.DisplayItems();
            cout << "\tEnter details of item you selected: "<<endl;
            cout<<"\tName or id: ";
            cin.ignore();
            getline(cin, name);
            cout<<"\tQuantity: ";
            cin>>quantity;
            cout<<"\tPrice $ ";
            cin>>price;
             Inventory* item = new Accessories(name, quantity, a.getPrice());
                    
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                        cart.addItem(item);
                    cart.displayCart();
                    
                    cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
        }
         else{
	            goto main_menu;
	        }
    }
        else if(choice==4)
        	{
            cout << "\tWe have following Sale items in this category: " << endl;
             SaleItems si(name, quantity, price);
             si.DisplayItems();
            cout << "\tEnter details of item you selected: "<<endl;
            cout<<"\tName or id: ";
            cin.ignore();
            
            getline(cin, name);
            cout<<"\tQuantity: ";
            cin>>quantity;
            cout<<"\tPrice $ ";
            cin>>price;
            Inventory* item = new SaleItems(name, quantity, si.getPrice());
                     
                    cout<<"\tDo you Want to add the product to your Shopping Cart?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : ";
                    cin>>option;
                    if(option=='Y' || option=='y'){
                        cart.addItem(item);
                       cart.displayCart();
                       
                   cout<<"\tEnter 'V' to view another product and 'C' to continue with this product : ";
                    cin>>view;
                    if(view=='V' || view =='v'){
                    	goto main_menu;
					}
            
        }
         else{
	            goto main_menu;
	        }
    }
        else if(choice!=1 || choice!=2 || choice!=3 || choice!=4){
        	 cout << "\n\t Invalid choice." << endl;
        	 goto main_menu;
		}
      }
      
	   else {
        cout << "\n\tLogin failed. Invalid username or password." << endl;
    goto login;
	}
         
         outfile.open("Order.txt" ,ios::app);
	cout<<"\tDo you want to Order this product?(Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) :  ";
    cin>>option;
   if(option=='Y' || option=='y'){
   	 string discountCode;
    cout << "\tEnter discount code (if any): ";
    cin >> discountCode;
    
   	  double totalBill = Billing::calculateTotalBill(cart, discountCode);
   	  
   	  cout<<"\tYour Order has been placed! "<<endl;
    cout << "\tTotal Bill after discount: $" << totalBill << endl;
    outfile << "\tTotal Bill after discount: $" << totalBill << endl;
    cout<<"\t\tThankYou For Shopping!"<<endl;

   }
   else{
    cout << "\tDo you want to remove the product from cart? (Enter 'Y' or 'y' for Yes and 'N' or 'n' for No) : " ;
    cin >> option;
    if (option == 'Y' || option == 'y') {
        string itemName;
        cout << "\tEnter the name of the item to remove: ";
        cin >> itemName;
        cart.removeItem(itemName); 
        
    }else{
    	goto main_menu;
	}

   }
    return 0;
}

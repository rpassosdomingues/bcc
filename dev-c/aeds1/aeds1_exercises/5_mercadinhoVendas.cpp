/*
  Problem 5: A merchant wants to calculate the profit of the goods he sells.
  he commercializes. To do this, he has a line for each merchandise with
  the name, purchase price, and sales price of the goods, the last line will have the
  name "end" for the merchandise. Make a program that:

  determine and write how many goods provide:
   - profit less than 10%;
   - profit between 10 and 20%;
   - profit greater than 20%.

  determine and write the total purchase and sale value of all goods, as well
  of all goods, as well as the total profit.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {

  string product;
  float profit, purchasePrice, sellingPrice;

  float totalPurchases = 0;
  float totalSales = 0;
  float totalProfit = 0;
  float profitLessThan10 = 0;
  float profitBetween10And20 = 0;
  float profitGreaterThan20 = 0;

  while(product != "end"){
    
    cout << "\n Enter the product name: ";
    cin >> product;
    
    if (product == "end") {
      break;
    }
    
    cout << "\n Enter the purchase price: ";
    cin >> purchasePrice;
    
    cout << "\n Enter the selling price: ";
    cin >> sellingPrice;
    
    totalPurchases += purchasePrice;
    totalSales += sellingPrice;
    
    profit = ((sellingPrice - purchasePrice) / purchasePrice) * 100;
    
    totalProfit += profit;
    
    if(profit < 10){
      profitLessThan10++;
    } else if (profit >= 10 && profit <= 20){
        profitBetween10And20++;
    } else profitGreaterThan20++;
  }

  cout << "\n\t ===================== Results ===================== \n" << endl;

  cout << "\n\t " << profitLessThan10 << " products: profit < 10%\n";
  cout << "\n\t " << profitBetween10And20 << " products: 10% <= profit <= 20%\n";
  cout << "\n\t " << profitGreaterThan20 << " products: profit > 20%\n";

  cout << "\n\t Total purchases: " << totalPurchases << "\n";
  cout << "\n\t Total sales: " << totalSales << "\n";
  cout << "\n\t Total profit: " << totalProfit << "\n";

  cout << "\n\t ===================== ------- ===================== \n" << endl;


  return 0;
}

#include "HashTableBaza.h"


int main(){
    int N = 6;
    HashTable table(10);
    table.Create(N, "KursaCInput.txt");
   // table.PrintHashTable();
    //table.PublicAddHashNode("A225BC", "89002500000", "B","A", 20,"05",2024);
    //table.PublicAddHashNode("A219BC", "89002500000", "B","A", 20,"05",2024);
   // table.PublicAddHashNode("A219BC", "89000000000", "A","B", 20,"05",2024);
    //table.Delete("A225BC", "89002500000", "B","A", 20,"05",2024); //Дописать удаление из списка круга
    //table.Delete("225BC", "89002500000", "A","B", 20,"05",2024); //Дописать удаление из списка круга
//    table.Delete("A233BC", "89003300000", "A","B", 20,"05",2024); //Дописать удаление из списка круга

    //table.Delete("A219BC", "89002500000", "B","A", 20,"05",2024);

    //table.PublicAddHashNode("A254BC", "89005400000", "B","A", 20,"05",2024);
   // table.Delete("A254BC", "89005400000", "A","B", 20,"05",2024);
   table.Delete("A254BC", "89005400000", "A","B", 20 ,"05", 2024);
    table.PrintHashTable();
    //cout<<table.FindDateHash("A225BC", "89002500000", "B", "A");


}
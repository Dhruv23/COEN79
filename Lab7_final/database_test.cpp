#include "database.h"

using namespace coen79_lab7;

int main() {
    std::cout << "Testing constructor...!" << std::endl;
    database myDB1;

    std::cout << "\nInserting company names...!" << std::endl;
    myDB1.insert_company("Intel");
    myDB1.insert_company("NVIDIA");
    myDB1.insert_company("Cypress");

    std::cout << "\nPrinting myDB1..." << std::endl;
    myDB1.print_companies();

    std::cout << "\nInserting company names to invoke reserve...!" << std::endl;
    myDB1.insert_company("Apple");
    myDB1.insert_company("Google");

    std::cout << "\nPrinting myDB1..." << std::endl;
    myDB1.print_companies();

    std::cout << "\nInserting product names...!" << std::endl;
    myDB1.insert_item("Intel", "Core i7", 300);
    myDB1.insert_item("Intel", "Core i5", 200);
    myDB1.insert_item("Apple", "iPhone 6", 400);
    myDB1.insert_item("Apple", "iPhone X", 900);
    myDB1.insert_item("Google", "glass", 1000);
    myDB1.insert_item("Google", "Android", 0);
    myDB1.insert_item("Google", "TensorFlow", 0);

    std::cout << "\nPrinting products of Apple and Intel..." << std::endl;
    std::cout << "Printing the products of Apple:" << std::endl;
    myDB1.print_items_by_company("Apple");
    std::cout << "Printing the products of Intel:" << std::endl;
    myDB1.print_items_by_company("Intel");

    std::cout << "\nCreating myDB2 on heap..." << std::endl;
    database* myDB2 = new database();
    myDB2->insert_company("Google");
    myDB2->insert_item("Google", "glass", 1000);
    myDB2->insert_item("Google", "Android", 0);
    myDB2->insert_item("Google", "TensorFlow", 0);

    std::cout << "\nPrinting myDB2..." << std::endl;
    std::cout << "Printing the products of Google:" << std::endl;
    myDB2->print_items_by_company("Google");

    std::cout << "\nCreating myDB3 on heap..." << std::endl;
    database* myDB3 = new database();

    std::cout << "\nAssigning myDB2 to myDB3..." << std::endl;
    *myDB3 = *myDB2;

    std::cout << "\nPrinting myDB3..." << std::endl;
    std::cout << "Printing the products of Google:" << std::endl;
    myDB3->print_items_by_company("Google");

    std::cout << "\nPrinting myDB2..." << std::endl;
    std::cout << "Printing the products of Google:" << std::endl;
    myDB2->print_items_by_company("Google");

    std::cout << "\nPrinting myDB3..." << std::endl;
    std::cout << "Printing the products of Google:" << std::endl;
    myDB3->print_items_by_company("Google");

    std::cout << "\nDeleting myDB2 and myDB3..." << std::endl;
    delete myDB2;
    delete myDB3;

    return 0;
}

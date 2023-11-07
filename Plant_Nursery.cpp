
#include <iostream>
#include<fstream>
#include<string>
struct P_Nursery
{
    char name[100];
    int id;
    int price;
    char des[150];//description
};
int Size()
{
    std::ifstream in("plant.bin", std::ios::binary);
    if(in.is_open())
    {
        in.seekg(0, std::ios::end);
        int n = in.tellg() / sizeof(P_Nursery);
        in.close();
        return n;
    }
}
int main(int argc, char* argv[])
{
    int k;
    std::string choice;
    P_Nursery* p = NULL;
    if (argc == 1)
    {
       /* std::cout << "Welcome to plant nursery inventory management system! "
            << std::endl;
        std::cout << "You can perform the following operation:" << std::endl;
        std::cout << "Add new plants" << std::endl;
        std::cout << "Retrive plant information" << std::endl;
        std::cout << "Update plants price" << std::endl;
        std::cout << "Delete plants" << std::endl;
        std::cout << "You can export information from Binary file into CSV file"
            << std::endl;
        std::cout << "You can import plants information from CSV file "
            << "into Binary file" << std::endl;*/
        std::ifstream in("plant.bin", std::ios::binary);
        bool file_exist;
        file_exist = in.good();
        if (file_exist)
        {
            if (in.is_open())
            {
                int size = Size();
                p = new P_Nursery[size];
                in.read((char*)p, sizeof(P_Nursery) * size);
                for (int i = 0; i < size; i++)
                {
                    std::cout << "Plant id: " << p[i].id << std::endl;
                    std::cout << "Plant Name: " << p[i].name << std::endl;
                    std::cout << "Plant Price: " << p[i].price << std::endl;
                    std::cout << "Plant Description: " << p[i].des << std::endl;
                }
                do
                {
                    std::cout << "Do you want to store record?" << std::endl;
                    std::cout << "Press yes or No" << std::endl;
                    // std::string choice;
                    std::cin >> choice;
                    P_Nursery* p1 = new P_Nursery();
                    if (choice == "yes" || choice == "Yes")
                    {
                        std::cin.ignore();
                        std::cout << "Plant name: ";
                        std::cin.getline(p1->name, 100);
                        std::cout << "Plant id: ";
                        std::cin >> p1->id;
                        for (int j = 0; j < size; j++)
                        {
                            if (p[j].id == p1->id)
                            {
                                std::cout << "This id already exist" << std::endl;
                                std::cout << "Pls Enter unique id: ";
                                std::cin >> p1->id;
                                k = -1;
                            }
                        }
                        std::cout << "Plant price: ";
                        std::cin >> p1->price;
                        std::cin.ignore();
                        std::cout << "Note: Plant Description should not exceed 150 characters!"
                            << std::endl;
                        std::cout << "Plant Description: ";
                        std::cin.getline(p1->des, 150);
                        std::ofstream out("plant.bin", std::ios::binary | std::ios::app);
                        if (out.is_open())
                        {
                            out.write((const char*)p1, sizeof(P_Nursery));
                            out.close();
                        }
                        else
                            std::cout << "Fail to open" << std::endl;
                        in.close();
                        delete p1;
                    }
                } while (choice == "yes" || choice == "Yes");
                delete[] p;
            }
            else
                std::cout << "Could not open" << std::endl;

        }
        else
        {
            int n, j = 0;
            std::cout << "File Empty" << std::endl;
            std::cout << "How many plant record you want to store?" << std::endl;
            std::cin >> n;
            std::cin.ignore();
            p = new P_Nursery[n];
            for (int i = 0; i < n; i++)
            {
                if (j == n - 1)
                    std::cout << "Enter last record..." << std::endl;
                else
                    std::cout << "Enter " << ++j << "th record.." << std::endl;
                std::cout << "Plant name: ";
                std::cin.getline(p[i].name, 100);
                if (i != 0)
                {
                    std::cout << "Plant id: ";
                    std::cin >> p[i].id;
                    for (int j = 0; j < i; j++)
                    {
                        if (p[j].id == p[i].id)
                        {
                            std::cout << "This id already exist" << std::endl;
                            std::cout << "Pls Enter unique id: ";
                            std::cin >> p[i].id;
                            k = -1;
                        }
                    }
                }
                else if (i == 0)
                {
                    std::cout << "Plant id: ";
                    std::cin >> p[i].id;
                }
                std::cout << "Plant price: ";
                std::cin >> p[i].price;
                std::cin.ignore();
                std::cout << "Note: Plant Description should not exceed 150 characters!"
                    << std::endl;

                std::cout << "Plant Description: ";
                std::cin.getline(p[i].des, 150);
            }
            std::ofstream out("plant.bin", std::ios::binary);
            if (out.is_open())
            {
                out.write((const char*)p, sizeof(P_Nursery) * n);
                out.close();
            }
            else
                std::cout << "Could not open" << std::endl;
            delete[] p;
        }
    }





    if (argc == 2)
    {

        std::string compare = argv[1];
        if (compare == "add" || compare == "Add")
        {
            std::ifstream in("plant.bin", std::ios::binary);
            //in.open("plant.bin", std::ios::binary);
            if (in.is_open())
            {
                
                int size = Size();
                P_Nursery* p1 = new P_Nursery[size];
                in.read((char*)p1, sizeof(P_Nursery) * size);
                p = new P_Nursery();         
                    std::cout << "Plant name: ";
                    std::cin.ignore();
                    std::cin.getline(p->name, 100);
                        std::cout << "Plant id: ";
                        std::cin >> p->id;
                        for (int k = 0; k < size; k++)
                        {
                            if (p1[k].id == p->id)
                            {
                                std::cout << "This id already exist" << std::endl;
                                std::cout << "Pls Enter unique id: ";
                                std::cin >> p->id;
                                k = -1;
                            }
                        }  
                    std::cout << "Plant price: ";
                    std::cin >> p->price;
                    std::cin.ignore();
                    std::cout << "Note: Plant Description should not exceed 150 characters!"
                        << std::endl;

                    std::cout << "Plant Description: ";
                    std::cin.getline(p->des, 150);
                    std::ofstream out("plant.bin", std::ios::binary|std::ios::app);
                    if (out.is_open())
                    {
                        out.write((const char*)p, sizeof(P_Nursery));
                        out.close();
                    }
                    else
                        std::cout << "Fail to open" << std::endl;
                    in.close();
                    delete p;
                    delete[] p1;
                
            }
            else
            std::cout << "Could not opened" << std::endl;
        }
    }




    std::string compare = argv[1];
   
    if (compare == "update" || compare== "Update")
    {
        int index = std::stoi(argv[2]);
        int size = Size();
        std::ifstream in("plant.bin", std::ios::binary);
        // in.open("plant.bin", std::ios::binary);
        if (in.is_open())
        {
            if (size != 0)
            {
                int size = Size();
                P_Nursery* p2 = new P_Nursery[size];
                in.read((char*)p2, sizeof(P_Nursery) * size);
                if (index <= size)
                {
                    p = new P_Nursery();
                    int x = index - 1;
                    P_Nursery* p1 = new P_Nursery();
                    strcpy(p1->name, p2[x].name);
                    p1->id = p2[x].id;
                    strcpy(p1->des, p2[x].des);
                    p1->price = p2[x].price;
                    std::cout << "For No CHANGE in Name and Description, press N/n"
                        << std::endl;
                    std::cout << "For NO CHANGE in id and price, press -1" << std::endl;
                    std::cout << "Enter Updated name: ";
                    std::cin.getline(p->name, 100);
                    std::string n1 = p->name;
                    if (n1 == "n" || n1 == "N")
                        strcpy_s(p->name, p1->name);
                    std::cout << "Enter Updated id: ";
                    std::cin >> p->id;
                    for (int k = 0; k < size; k++)
                    {
                        if (p2[k].id == p->id)
                        {
                            std::cout << "This id already exist" << std::endl;
                            std::cout << "Pls Enter unique id: ";
                            std::cin >> p->id;
                            k = -1;
                        }
                    }
                    if (p->id == -1)
                    {
                        p->id = p1->id;
                    }
                    std::cout << "Enter Updated price: ";
                    std::cin >> p->price;
                    std::cin.ignore();

                    if (p->price == -1)
                        p->price = p1->price;
                    std::cout << "Enter updated Description: ";
                    std::cin.getline(p->des, 150);
                    n1 = p->des;
                    if (n1 == "n" || n1 == "N")
                        strcpy(p->des, p1->des);
                    std::fstream f("plant.bin", std::ios::binary | std::ios::ate | std::ios::in | std::ios::out);
                    if (index != 1)
                    {
                        f.seekp(sizeof(P_Nursery) * x);
                    }
                    else
                        f.seekp(0);
                    f.write((const char*)p, sizeof(P_Nursery));
                    f.close();
                    delete p;
                    delete p1;
                    delete[] p2;
                }
                else
                {
                    std::cout << "Invalid index!!" << std::endl;
                    std::cout << "Only " << size << " records are present.." << std::endl;
                }
            }
            else
                std::cout << "File empty" << std::endl;
        }
        in.close();
    }


    //compare = argv[1];
   
    


    if (compare == "export" || compare == "Export")
    {
        std::string file = argv[2];
        std::ofstream  out(file);
        int size = Size();
        int esize = size / sizeof(sizeof(P_Nursery));
        p = new P_Nursery();
        std::ifstream in("plant.bin", std::ios::binary);
        if (out.is_open())
        {
            if (size != 0)
            {
                in.read((char*)p, sizeof(P_Nursery));
                while (!in.eof())
                {
                    out << p->name << ",";
                    out << p->id << ",";
                    out << p->price << ",";
                    out << p->des;
                    out << std::endl;
                    in.read((char*)p, sizeof(P_Nursery));
                }
                std::cout << "Data has been exported.." << std::endl;
            }
            else
            std::cout << "File Empty" << std::endl;
        }

        else
            std::cout << "not opened CSV file";
        delete p;
        in.close();
        out.close();
    }




    if (compare == "import" || compare == "Import")
    {
        int size = Size();
        std::string file_name = argv[2];
        std::ifstream in(file_name);
        bool file_exist = in.good();
        if (size != 0)
        {
            if (file_exist)
            {

                std::string line;
                // p = new P_Nursery();
                getline(in, line);
                while (!in.eof())
                {
                    std::cout << line;
                    std::cout << std::endl;
                    getline(in, line);
                }
            }
            else
                std::cout << "This file does not exist.." << std::endl;
        }
        else
            std::cout << "file empty" << std::endl;
    }
        






        if (compare == "delete" || compare == "Delete")
        {
            if (argc == 3)
            {
                int index = std::stoi(argv[2]);
                std::ifstream in("plant.bin", std::ios::binary);
                if (in.is_open())
                {
                    in.seekg(0, std::ios::end);
                    int count = in.tellg() / sizeof(P_Nursery);
                    in.seekg(0);
                    if (index <= count)
                    {
                        int size = index - 1;
                        p = new P_Nursery[size];
                        in.read((char*)p, sizeof(P_Nursery) * size);
                        std::ofstream out("temp.bin", std::ios::binary);
                        if (out.is_open())
                        {
                            out.write((const char*)p, sizeof(P_Nursery) * size);
                            delete[] p;
                        }
                        else
                            std::cout << "could not created" << std::endl;
                        out.close();
                        in.seekg(sizeof(P_Nursery), std::ios::cur);
                        size = count - index;
                        p = new P_Nursery[size];
                        in.read((char*)p, sizeof(P_Nursery) * size);
                        in.close();
                        out.open("temp.bin", std::ios::binary | std::ios::app);
                        if (out.is_open())
                        {
                            out.write((const char*)p, sizeof(P_Nursery) * size);
                            delete[] p;
                        }
                        else
                            std::cout << "Could not reopen" << std::endl;
                        out.close();
                        in.open("temp.bin", std::ios::binary);
                        if (in.is_open())
                        {
                            in.seekg(0, std::ios::end);
                            count = in.tellg() / sizeof(P_Nursery);
                            in.seekg(0);
                            p = new P_Nursery[count];
                            in.read((char*)p, sizeof(P_Nursery) * count);
                            for (int i = 0; i < count; i++)
                            {
                                std::cout << p[i].name << std::endl;
                                std::cout << p[i].id << std::endl;
                                std::cout << p[i].price << std::endl;
                                std::cout << p[i].des << std::endl;
                            }
                            delete[] p;
                            in.close();
                            remove("plant.bin");
                            int h = rename("temp.bin", "plant.bin");
                        }
                    }
                    else if (count == 0)
                        std::cout << "File empty" << std::endl;
                    else
                    {
                        std::cout << "Only " << count << " records are present" << std::endl;
                        std::cout << "Wrong index:" << std::endl;
                    }
                }
                else
                    std::cout << "Could not opened" << std::endl;
            }
            else
            {
                std::cout << "It takes two arguments,1st one is delete ";
                std::cout << "and 2nd one is index." << std::endl;
                std::cout << "Argument missing!!" << std::endl;
            }

        }




        if (compare == "search" || compare == "Search")
        {
            int size = Size();
            if (size != 0)
            {
                    int n, i, c = 0;
                std::cout << "On which basis you want to serach?" << std::endl;
                std::cout << "1. ID" << std::endl;
                std::cout << "2. Name" << std::endl;
                std::cout << "3. price range" << std::endl;
                std::cout << "Press 1 for id and 2 for Name and 3 for price range" << std::endl;
                std::cin >> n;
                p = new P_Nursery();
                if (n == 1)
                {
                    std::cout << "Enter id: ";
                    std::cin >> i;
                    std::ifstream in("plant.bin", std::ios::binary);
                    if (in.is_open())
                    {
                        in.read((char*)p, sizeof(P_Nursery));
                        while (!in.eof())
                        {
                            if (i == p->id)
                            {
                                std::cout << p->name << std::endl;
                                std::cout << p->id << std::endl;
                                std::cout << p->price << std::endl;
                                std::cout << p->des << std::endl;
                                c++;
                            }
                            in.read((char*)p, sizeof(P_Nursery));
                        }
                        if (c == 0)
                        {
                            std::cout << "No record exist of this id.." << std::endl;
                        }
                        in.close();
                        delete p;
                    }

                }
                else if (n == 2)
                {
                    std::string plant, extra;
                    c == 0;
                    std::cout << "Enter plant name: ";
                    std::cin >> plant;
                    p = new P_Nursery();
                    std::ifstream in("plant.bin", std::ios::binary);
                    if (in.is_open())
                    {
                        in.read((char*)p, sizeof(P_Nursery));
                        while (!in.eof())
                        {
                            extra = p->name;
                            if (plant == extra)
                            {
                                std::cout << p->name << std::endl;
                                std::cout << p->id << std::endl;
                                std::cout << p->price << std::endl;
                                std::cout << p->des << std::endl;
                                c++;
                            }
                            in.read((char*)p, sizeof(P_Nursery));
                        }
                        if (c == 0)
                            std::cout << "No record found of this name" << std::endl;
                        in.close();
                        delete p;
                    }
                }
                else if (n == 3)
                {

                    int s, e;
                    c = 0;

                    std::cout << "Enter price range: " << std::endl;
                    std::cout << "Enter Starting price: ";
                    std::cin >> s;
                    std::cout << "Enter Ending price: ";
                    std::cin >> e;
                    std::ifstream in("plant.bin", std::ios::binary);
                    p = new P_Nursery();
                    if (in.is_open())
                    {
                        in.read((char*)p, sizeof(P_Nursery));
                        while (!in.eof())
                        {
                            if (p->price >= s && p->price <= e)
                            {
                                std::cout << p->name << std::endl;
                                std::cout << p->id << std::endl;
                                std::cout << p->price << std::endl;
                                std::cout << p->des << std::endl;
                                c++;
                            }
                            in.read((char*)p, sizeof(P_Nursery));
                        }
                        if (c == 0)
                   std::cout << "Not record found between this range" << std::endl;
                        in.close();
                        delete p;
                    }

                }
                else
                    std::cout << "Inavlid input" << std::endl;
            }
            else
                std::cout << "File Empty" << std::endl;
        }



        if (compare == "help" || compare == "Help")
        {
             std::cout<<std::endl << "Welcome to plant nursery inventory management "
             <<"help centre!!" << std::endl;
         std::cout << "You can perform the following operations:" << std::endl;
         std::cout << "Add new plants by giving command line " 
             <<"argument 'add'" << std::endl;
         std::cout << "search plant information by giving command " 
             <<"line argument 'search' " << std::endl;
         std::cout << "Update plant information by giving index (starting "
             << " from 1) but NOT ID of the record in Command line argument followed by 'update'" << std::endl;
         std::cout << "Delete plant information by giving index (starting "
             << " from 1) but NOT ID of the record in Command line argument followed by 'delete'" << std::endl;
         std::cout << "You can export information from Binary file into CSV file "
            <<"by giving command line argument 'export' followed by file name "
            <<"( in which data will be exported )" << std::endl;
         std::cout << "You can import information from CSV into binary file "
             << "by giving command line argument 'import' followed by file name "
             << "( from which data will be imported )" << std::endl;
        }
        

}





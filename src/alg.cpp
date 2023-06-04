// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string val;
    BST <std::string> tree;
    if (!file) {
        std::cout << "File error!" << std::endl;
        //return;
    } else {
        while (!file.eof())	{
            val.erase();
            while (true) {
                int ch = file.get();
                if (ch >= 99 && ch <= 122) {
                    val += ch;
                } else if (ch >= 65 && ch <= 90) {
                    ch += 32;
                    val += ch;
                } else {
                    break;
                }
            }
            if (!val.empty())
                tree.add(val);
        }
        file.close();
    }
    return tree;
}
}

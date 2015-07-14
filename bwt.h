#ifndef BWT_H_
#define BWT_H_

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

class LexicalSorter {
public:
    LexicalSorter(const char *start_pointer, const char *end_pointer) 
    : start_pointer(start_pointer), end_pointer(end_pointer)
    {}

    bool operator()(const char *s1, const char *s2) const 
    {
        while (true)
        {
            if (s1 == s2) return false;
            if (s1 == end_pointer) s1 = start_pointer;
            if (s2 == end_pointer) s2 = start_pointer;
            if (*s1 < *s2) return true;
            if (*s1 > *s2) return false;
            s1++; s2++;
        }
    }
private:
    const char *start_pointer;
    const char *end_pointer;
};

class Bwt
{
public:
    static std::pair<std::string *, unsigned int *> Transform(const std::string *input) 
    {
        std::cout << input->size() << std::endl;
        const char *input_chars = input->c_str();
        std::vector<const char *> pointers(input->size());
        for (int i = 0; i < input->size(); i++)
        {
            pointers[i] = input_chars + i;
        }
        std::sort(pointers.begin(), pointers.end(), LexicalSorter(input_chars, input_chars + input->size()));
        std::string *bw_string = new std::string(input->size(), 'X');
        unsigned int *bw_locations = new unsigned int[input->size()];
        for (auto it = pointers.begin(); it != pointers.end(); it++)
        { 
            (*bw_string)[it - pointers.begin()] = (*it == input_chars) ? (*(input_chars + input->size() - 1)) : (*(*it - 1));
            bw_locations[it - pointers.begin()] = *it - input_chars;
        } 

        return std::tie(bw_string, bw_locations);
    }
};

#endif
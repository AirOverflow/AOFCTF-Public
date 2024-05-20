#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

__attribute__((constructor))
void __setup__(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
}

void print_flag() {
    std::fstream flag_file("flag.txt", std::ios::in);
    std::string flag;
    std::getline(flag_file, flag);
    std::cout << flag << std::endl;
}

const std::vector<std::string> valid_licences = {
    "ccb2f12a-a03c-47f6-9b89-dedbd2219287",
    "e0f9cb86-0678-4e07-b423-c18adceeae20",
    "38d1187f-8047-4652-8bfa-b1021962b604",
    "825ea97e-140c-4675-be64-f8834d4845e0",
    "2db18f01-f1b2-4396-b663-90f99f9fcd02",
    "e0163c59-e29c-4ce5-bf55-8309c4a75b82",
    "c1e7434c-e8df-41e2-a1bc-1bab0e41e139",
    "f443cf58-cba9-4913-9540-3b6ab87645d2",
    "4efab785-ef78-4d51-b105-6eb4921d94c0",
    "fc7e0eb4-66ed-4d5a-b7d5-8c0cb3041559",
    "043a4fc7-4939-4081-97bb-67fdb4054d9c",
    "243fd2a3-3236-448d-9fb1-8652b5a2c73a",
    "f9eb3829-b66f-4f03-9cd3-c7bc43042de4",
    "9cec6682-9490-48cf-a1b7-fabf56045d89",
    "a8342a5a-eff8-4ea0-9224-139a090a9762",
    "52fb554b-f728-4f30-b484-3163e6b12d5a",
    "7fd0290d-ba80-4ecf-ad46-091700ce4248",
    "7e37eae3-0b38-4d34-aa84-08eaae185f34",
    "9d8e89d9-3649-4ff7-a15d-b6293bade546",
    "d7da8c41-fcb7-40c2-918b-bb8d3ebaa872"
};

std::string base_swapper(std::unordered_map<int, int> _swap, const std::string& _rt) {
    std::string buffer = _rt;
    
    for (const auto kv : _swap) {
        std::swap(buffer[kv.first], buffer[kv.second]);
    }
    return buffer;
}

std::string swapper(const std::string & _rt) {
    std::unordered_map<int, int> _swap = {
        {13, 1}, {6, 0}, {27, 12}, {21, 26}, {23, 9}, {32, 25},
        {24, 28}, {2, 17}, {5, 33}, {35, 18}, {15, 22}, {10, 11},
        {20, 8}, {4, 19}, {16, 31}, {14, 3}, {30, 34}, {7, 29}
    };
    return base_swapper(_swap, _rt);
}

std::string swapper2(const std::string& _rt) {
    std::unordered_map<int, int> _swap = {
        {26, 16}, {8, 24}, {14, 23}, {17, 7}, {5, 22}, {30, 19},
        {21, 31}, {27, 2}, {29, 25}, {32, 34}, {20, 18}, {3, 33},
        {10, 13}, {35, 6}, {9, 12}, {11, 0}, {4, 28}, {15, 1}
    };
    return base_swapper(_swap, _rt);
}

bool check(std::string buffer) {
    buffer = swapper(buffer);
    buffer = swapper2(buffer);
    for (const auto& lic : valid_licences) {
        if (buffer == lic) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string buffer;
    std::cout << "Enter the license key: ";
    std::getline(std::cin, buffer);

    if (check(buffer)) {
        std::cout << "Good job!" << std::endl;
        std::cout << "Flag: ";
        print_flag();
    }
    else {
        std::cout << "Invalid license" << std::endl;
    }
}
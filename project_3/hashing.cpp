#include <openssl/sha.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string generate_words(int length) {
    string words;
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < chars.length(); i++) {
        for (int j = 0; j < chars.length(); j++) {
            for (int k = 0; k < chars.length(); k++) {
                if (length == 4) {
                    for (int l = 0; l < chars.length(); l++) {
                        string code = "";
                        code += chars[i];
                        code += chars[j];
                        code += chars[k];
                        code += chars[l];
                        words += code + " ";
                    }
                } else if (length == 6) {
                    for (int l = 0; l < chars.length(); l++) {
                        for (int m = 0; m < chars.length(); m++) {
                            for (int n = 0; n < chars.length(); n++) {
                                string code = "";
                                code += chars[i];
                                code += chars[j];
                                code += chars[k];
                                code += chars[l];
                                code += chars[m];
                                code += chars[n];
                                // cout << code << endl;
                                words += code + " ";
                            }
                        }
                    }
                }
            }
        }
    }
    return words;
}

void crack_hash(string given_hash, string words) {
    // Compute hash value of each word and compare to given hash
    string word;
    istringstream iss(words);
    while (iss >> word) {
        // Compute hash value of current string
        // cout << word << endl;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256((const unsigned char*)word.c_str(), word.length(), hash);
        string computed_hash = "";
        for (int m = 0; m < SHA256_DIGEST_LENGTH; m++) {
            char buf[3];
            sprintf(buf, "%02x", hash[m]);
            computed_hash += buf;
        }

        // Compare hash values
        if (computed_hash == given_hash) {
            cout << "Found answer! Secret code word is: " << word << endl;
        }
    }
}

// int main() {
//     // Given hash value
//     string given_hash = "3803b47609a2a464054659b14a0cdfba92830fb46ee70c03a336d5554b9acad4";
//     string given_hash2 = "9994a0007e4271061b671424371f3f04dce63520b25ef9036fa45f3439e2f062";
//     string given_hash3 = "6c3d036f677dd8f744b4df9cf517eb2ac93982629e4eb7978336cfcb8b5cedb6";

//     // Generate all 4-character words
//     // string words = generate_words(4);

//     // Generate all 6-character words
//     string words2 = generate_words(6);
//     cout << "ready" << endl;
//     // string words3 = generate_words(10);
//     //  crack_hash(given_hash, words);

//     crack_hash(given_hash2, words2);

//     // crack_hash(given_hash3, words3);

//     return 0;
// }

int main() {
    string given_hash2 = "3803b47609a2a464054659b14a0cdfba92830fb46ee70c03a336d5554b9acad4";
    string given_hash = "9994a0007e4271061b671424371f3f04dce63520b25ef9036fa45f3439e2f062";
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < chars.length(); i++) {
        for (int j = 0; j < chars.length(); j++) {
            for (int k = 0; k < chars.length(); k++) {
                for (int l = 0; l < chars.length(); l++) {
                    for (int m = 0; m < chars.length(); m++) {
                        for (int n = 0; n < chars.length(); n++) {
                            string code = "";
                            code += chars[i];
                            code += chars[j];
                            code += chars[k];
                            code += chars[l];
                            code += chars[m];
                            code += chars[n];
                            unsigned char hash[SHA256_DIGEST_LENGTH];
                            SHA256((const unsigned char*)code.c_str(), code.length(), hash);
                            string computed_hash = "";
                            for (int m = 0; m < SHA256_DIGEST_LENGTH; m++) {
                                char buf[3];
                                sprintf(buf, "%02x", hash[m]);
                                computed_hash += buf;
                            }

                            // Compare hash values
                            if (computed_hash == given_hash) {
                                cout << "Found answer! Secret code word is: " << code << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

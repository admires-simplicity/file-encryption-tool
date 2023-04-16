#include <fstream>
#include <filesystem>
#include <iostream>

int main()
{
	//std::ios::openmode offlag = (std::filesystem::exists("test.txt")) ? std::ios::app : std::ios::out;
	//std::ofstream ofs("test.txt", (offlag | std::ios::binary));
	//ofs << "Hello World!" << std::endl;
	//ofs.close();
	//return 0;

//pseudocode:
//// Note: All variables are unsigned 64 bits
//
//// Pre-processing: padding with the size difference in bytes
//append padding until len in bits ≡ 0 (mod 64)
//
//var long key // The keys given by the user
//var long keys[16]
//var long left, right
//
//// Generate Keys
//
//// PC1 (64bits to 56bits) 
//key := permutation(key, PC1)
//left := (key rightshift 28) and 0xFFFFFFF
//right := key and 0xFFFFFFF
//
//for i from 0 to 16 do
//	right := right leftrotate KEY_shift[i]
//	left := left leftrotate  KEY_shift[i]
//	var long concat := (left leftshift 28) or right
//	// PC2 (56bits to 48bits)
//	keys[i] := permutation(concat, PC2)
//end for
//
//// To decrypt a message reverse the order of the keys
//if decrypt do
//	reverse keys
//end if
//
//// Encrypt or Decrypt
//for each 64-bit chunk of padded message do
//	var long tmp
//
//	// IP
//	chunk := permutation(chunk, IP)
//	left := chunk rightshift 32
//	right := chunk and 0xFFFFFFFF
//	for i from 0 to 16 do
//		tmp := right
//		// E (32bits to 48bits)
//		right := expansion(right, E)
//		right := right xor keys[i]
//		// Substitution (48bits to 32bits)
//		right := substitution(right)
//		// P
//		right := permutation(right, P)
//		right := right xor left
//		left := tmp
//	end for
//	// Concat right and left
//	var long cipher_chunk := (right leftshift 32) or left
//	// FP
//	cipher_chunk := permutation(cipher_chunk, FP)
//end for

	//read entire file in binary format
	std::ifstream ifs("in.txt", std::ios::binary);
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	ifs.close();

	std::cout << "length of content is " << content.size() << '\n';
	std::cout << "length of content in bits is " << content.size() * 8 << '\n';
	while (content.size() % 8 != 0)
	{
		content += ' ';
	}
	std::cout << "length of padded content is " << content.size() << '\n';
	std::cout << "length of padded content in bits is " << content.size() * 8 << '\n';

	//write entire file in binary format
	std::ofstream ofs("out.txt", std::ios::binary);
	ofs << content;
	ofs.close();


}

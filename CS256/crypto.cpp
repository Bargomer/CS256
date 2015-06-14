#include "stdafx.h"
#include "..\cryptopp562\rsa.h" 
#include "..\cryptopp562\osrng.h" 
#include <string.h> 
#include <ctime>
#include <iostream> 
#include <fstream>
#include <iomanip> 
using namespace std;
using namespace CryptoPP;


//void print_string_hex(byte* in, int len)
//{
//	for (int i = 0; i<len; i++)
//		cout << setfill('0') << setw(2) << hex << (short)in[i];
//}

string encrypt(string plainText)
{
		string cipher, restored;
		int keylength = 512;

		CryptoPP::AutoSeededRandomPool rng;
		InvertibleRSAFunction params;
		

		//if (cin.fail()) {
		//	cin.clear();
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//}

		params.GenerateRandomWithKeySize(rng, keylength);
		RSA::PrivateKey private_key(params);
		RSA::PublicKey public_key(params);

		RSAES_OAEP_SHA_Encryptor e(public_key);
		StringSource ss1(plainText, true,
			new PK_EncryptorFilter(rng, e, new StringSink(cipher)));

		RSAES_OAEP_SHA_Decryptor d(private_key);
		StringSource ss2(cipher, true,
			new PK_DecryptorFilter(rng, d, new StringSink(restored)));

		//cout << "Plain Text: " << plainText << endl;

		//cout << "Ciphered Text: " << cipher << " ";
		//print_string_hex((byte*)cipher.data(), cipher.length());
		//cout << endl;
		//cout << "Decrypted Text: " << restored << endl;

		//return ciphered text
		return cipher;
}

//int main(){
//	encrypt("hello world how");
//}

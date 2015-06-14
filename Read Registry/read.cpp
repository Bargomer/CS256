// registry_read.cpp
// compile with: /clr
using namespace System;
using namespace Microsoft::Win32;
#include <iostream>

int main()
{
	array<String^>^ key = Registry::CurrentUser->GetSubKeyNames();

	Console::WriteLine("Subkeys within CurrentUser root key:");
	for (int i = 0; i<key->Length; i++)
	{
		Console::WriteLine("   {0}", key[i]);
	}

	Console::WriteLine("Opening subkey 'Identities'...");
	RegistryKey^ rk = nullptr;
	rk = Registry::CurrentUser->OpenSubKey("Software");
	if (rk == nullptr)
	{
		Console::WriteLine("Registry key not found - aborting");
		return -1;
	}

	Console::WriteLine("Key/value pairs within 'Identities' key:");
	array<String^>^ name = rk->GetValueNames();
	for (int i = 0; i<name->Length; i++)
	{
		String^ value = rk->GetValue(name[i])->ToString();
		Console::WriteLine("   {0} = {1}", name[i], value);
	}

	std::cin.get();
	return 0;
}